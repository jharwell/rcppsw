#!/bin/bash
#
# Bootstraps the project, including:
#
# - Install .deb dependencies from repositories (ubuntu assumed)
# - Install python package dependencies
# - Set up dependent repositories
# - Compile main project
#
# $1 - The root directory for all repos for the project
# $2 - # cores to use when compiling

mkdir -p $1 && cd $1

rcppsw_pkgs=(libboost-all-dev liblog4cxx-dev catch ccache python3-pip)
libra_pkgs=(make cmake git npm graphviz doxygen cppcheck cmake make gcc-9 g++-9
            libclang-9-dev clang-tools-9 clang-format-9 clang-tidy-9)

python_pkgs=(cpplint breathe exhale)

# Install packages (must be loop to ignore ones that don't exist)
for pkg in "${libra_pkgs[@]}" "${rcppsw_pkgs[@]}" "${fordyca_pkgs[@]}"
do
    sudo apt-get -my install $pkg
done

pip3 install  "${python_pkgs[@]}"

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
npm install
cd ..

# Build rcppsw and documentation
mkdir -p build && cd build
cmake -DCMAKE_C_COMPILER=gcc-8 -DCMAKE_CXX_COMPILER=g++-8 ..
make -j $2
make documentation

# Made it!
echo "Bootstrap successful!"
