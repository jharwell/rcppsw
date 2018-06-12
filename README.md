# RCPPSW (Reusable C++ Software)

This is a collection of various useful algorithms/data structures/etc. that I
have found useful for multi-agent robots research, and that do not currently
exist in Boost, or that build on what boost provides. Includes such things as:

- Highly configurable Event Reporting (logging to a file/debug printing) server
  with runtime module installation/removal and verbosity adjustment.

- Logical task hierarchy, including executives capable of executing a task
  decomposition graph.

- Data structures involved in multi-agent robotics, such as logical occupancy
  grids. Multiprocessing/multithreading queues, vectors.

- Implementation of various design patterns:

  - polled FSM, Hierarchical FSM
  - decorator
  - visitor
  - factory (releasing and sharing variants)
  - prototype
  - singleton

  Some of these DO exist elsewhere, but I found their implementations somewhat
  hard to follow/poorly documented, and it was easier to roll my own.

 - Control theoretic bits such as PID loops

 - Swarm robotics constructs such as pheromone density

 - Miscellaneous other things as kmeans clustering,
   multithreading/multiprocessing management tools.

## Pre-cloning Setup

1. This project uses the build scaffolding provided by
   [cmake-config](https://github.com/jharwell/cmake-config). Please look at the
   platform requirements for that project and install any needed
   packages/libraries.

2. Install the following libraries:

   - boost 1.58

3. Set up an ssh key for password-less connection to github (this is for the
   [cmake config](https://github.com/jharwell/cmake-config) submodule). Yes I
   know that it can be done without ssh, but I set it up this way so I don't
   have to type my github password ever.

## Post-cloning

1. Check out the development branch, as that has not only the latest semi-stable
   release, but also the most up-to-date documentation, including this README.

        git checkout devel

2. Pull in the cmake project scaffolding:

        git submodule update --init --recursive  --remote

3. Build via:

        mkdir build && cd build
        cmake ..
        make

    This will build for the default HAL configuration (see below). to build for
    a different configuration, pass the desired flag to cmake via `-D`.

    There are a number of configuration options that can be passed to cmake that
    are specific to rcppsw, which are shown in the table below. For other,
    additional configuration options, please see the README in the [cmake
    config](https://github.com/jharwell/cmake-config) repo:


   | Option            | Meaning                                                       | Options                                                                    | Default            |
   |-------------------|---------------------------------------------------------------|----------------------------------------------------------------------------|--------------------|
   | `WITH_HAL_CONFIG` | Specify which hardware configuration to enable. At most *ONE* | `"argos-footbot"`: Build for the footbot robot within the argos simulator. | `"argos-footbot""` |
   |                   | configuration can be enabled at a time.                       |                                                                            |                    |


To build the documentation, do the following from the build directory:

    make documentation

# Contributing

For contributing to `rcppsw`, see [CONTRIBUTING](docs/CONTRIBUTING.md)

# Troubleshooting

- If you are having trouble building:

  1. Make sure you are on the `devel` branch.

  2. Update the cmake submodule via `git submodule update`

  If the problem perists, open an issue.

# License
This project is licensed under GPL 2.0. See [LICENSE](LICENSE.md).

# Donate
If you've found this project helpful, please consider donating somewhere between
a cup of coffe and a nice meal:

[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.me/jharwell1406)
