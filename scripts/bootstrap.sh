#!/bin/bash
#
# Bootstraps the project, including:
#
# - Install .deb dependencies from repositories (ubuntu assumed)
# - Install python package dependencies
# - Set up dependent repositories
# - Compile main project
#
usage() {
    cat << EOF >&2
Usage: $0 [--rroot <dir>] [--cores <n_cores>] [--nosyspkgs ] [--opt] [-h|--help]

--rroot <dir>: The root directory for all repos for the project. All github
               repos will be cloned/built in here. Default=$HOME/research.

--cores: The # cores to use when compiling. Default=$(nproc).

--nosyspkgs: If passed, then do not install system packages (requires sudo
             access). Default=YES (install system packages).

--nobuild: Do everything but actually build RCPPSW. Used when RCPPSW
           is a sub-project/submodule which will be built by the main
           project as needed.

--opt: Perform an optimized build of RCPPSW. Default=NO.

-h|--help: Show this message.
EOF
    exit 1
}

repo_root=$HOME/research
install_sys_pkgs="YES"
do_build="YES"
n_cores=$(nproc)
build_type="DEV"
options=$(getopt -o h --long help,rroot:,cores:,nosyspkgs,opt,nobuild  -n "BOOTSTRAP" -- "$@")
if [ $? != 0 ]; then usage; exit 1; fi

eval set -- "$options"
while true; do
    case "$1" in
        -h|--help) usage;;
        --rroot) repo_root=$2; shift;;
        --cores) n_cores=$2; shift;;
        --nosyspkgs) install_sys_pkgs="NO";;
        --nobuild) do_build="NO";;
        --opt) build_type="OPT";;
        --) break;;
        *) break;;
    esac
    shift;
done

echo -e "********************************************************************************"
echo -e "RCPPSW BOOTSTRAP START:"
echo -e "REPO_ROOT=$repo_root"
echo -e "N_CORES=$n_cores"
echo -e "SYSPKGS=$install_sys_pkgs"
echo -e "BUILD_TYPE=$build_type"
echo -e "DO_BUILD=$do_build"
echo -e "********************************************************************************"

mkdir -p $repo_root && cd $repo_root

# Install system packages
if [ "YES" = "$install_sys_pkgs" ]; then
    rcppsw_pkgs=(libboost-all-dev liblog4cxx-dev catch ccache python3-pip)
    libra_pkgs=(make cmake git nodejs npm graphviz doxygen cppcheck
                gcc-9 g++-9 libclang-9-dev clang-tools-9
                clang-format-9 clang-tidy-9)

    # Modern cmake required, default with most ubuntu versions is too
    # old--use kitware PPA.
    wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | sudo tee /usr/share/keyrings/kitware-archive-keyring.gpg >/dev/null
    echo 'deb [signed-by=/usr/share/keyrings/kitware-archive-keyring.gpg] https://apt.kitware.com/ubuntu/ focal main' | sudo tee /etc/apt/sources.list.d/kitware.list >/dev/null
    sudo apt-get update

    # Install packages (must be loop to ignore ones that don't exist)
    for pkg in "${libra_pkgs[@]}" "${rcppsw_pkgs[@]}"
    do
        sudo apt-get -my install $pkg
    done
fi


python_pkgs=(cpplint breathe exhale)
pip3 install --user  "${python_pkgs[@]}"

# Exit when any command after this fails. Can't be before the package installs,
# because it is not an error if some of the packages are not found (I just put a
# list of possible packages that might exist on debian systems to satisfy
# project requirements).
set -e

# Bootstrap rcppsw
if [ -d rcppsw ]; then rm -rf rcppsw; fi
git clone https://github.com/swarm-robotics/rcppsw.git
cd rcppsw
git checkout devel
git submodule update --init --recursive --remote

# Build rcppsw and documentation
if [ "YES" = "$do_build" ]; then
    if [ "OPT" = "$build_type" ]; then
    er="NONE"
    else
        er="ALL"
    fi
    npm install
    mkdir -p build && cd build
    cmake -DCMAKE_C_COMPILER=gcc-9 -DCMAKE_CXX_COMPILER=g++-9 ..
    make -j $n_cores
    make documentation
    cd ..
fi;

cd ..


# Made it!
echo -e "********************************************************************************"
echo -e "RCPPSW BOOTSTRAP SUCCESS!"
echo -e "******************************************************************************"
