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

For full details, clone the repo and build the documentation via:

    make documentation

from your build directory.

## Basic Setup

Before starting, you will need a recent version of the following programs:

- cmake
- make
- gcc
- g++ (A version that supports C++11 is required)

You will also need recent versions of the following libraries:

- boost (1.58 is known to work; older versions may also work)

After cloning this repo, you will need to:

1. Pull in the cmake config:

        git submodule update --init --recursive

2. Clone `rcsw` https://github.com/jharwell/rcsw (Reusable C software) somewhere
   and link it into `ext/rcsw`.

Then you can build via:

    mkdir build && cd build
    cmake ..
    make

To build the extensive documentation, do:

    make documentation

For contributing to `rcppsw`, see [CONTRIBUTING](docs/CONTRIBUTING.md)

# License
This project is licensed under GPL 2.0. See [LICENSE](LICENSE.md).

# Donate
If you've found this project helpful, please consider donating somewhere between
a cup of coffe and a nice meal:

[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.me/jharwell1406)
