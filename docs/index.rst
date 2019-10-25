Welcome to RCPPSW's documentation!
===================================

This is a collection of various useful algorithms/data structures/etc. that I
have found useful for multi-agent robots research, and that do not currently
exist in Boost, or that build on what boost provides. Includes such things as:

- Event reporting framework, built on top of Log4cxx.

- Logical task hierarchy, including executives capable of executing a task
  decomposition graph.

- Data structures involved, such as logical occupancy
  grids, multiprocessing/multithreading queues, vectors, type maps.

- Some reusable named type definitions.

- Implementation of various design patterns:

  - polled FSM, Hierarchical FSM
  - decorator
  - visitor
  - factory (releasing/sharing variants)
  - prototype
  - singleton
  - PIMPL

- Components that DO exist elsewhere, but I found their implementations somewhat
  hard to follow/poorly documented, and it was easier to roll my own.

 - Control theoretic bits such as PID loops

 - Miscellaneous other things as kmeans clustering,
   multithreading/multiprocessing management tools.

.. toctree::
   :maxdepth: 2
   :caption: Contents:

   contributing/index.rst

Directory Layout
----------------

- ``src/`` - All ``.cpp`` files live under here, in their respective modules.

- ``include/`` - All ``.hpp`` files live under here.

- ``docs/`` - All documentation besides the main README lives under here,
  including all development/style guides.

- ``VERSION`` - A file in the root root that holds the current/next versions of
  the code. Versions are numbered as ``major.minor.patch``, and is updated in
  accordance with semantic versioning/GitFlow.

Debug Build
-----------

This project should not generally need to be built on its own, but if you DO
need to do so, download ``scripts/bootstrap.sh`` BEFORE cloning this repo. The
script can be downloaded by navigating to the file on github, clicking the
``raw`` button, and then right clicking and doing ``Save As``. After
downloading, mark the script as executable (``chmod +x bootstrap.sh``) and then
run it (it can be run from anywhere), with the following arguments:

- 1st arg: The root directory for the project (all repos will be cloned/built in
  here, and it **must** be an absolutae path).
- 2nd arg: The # of cores to use when building RCPPSW (should be set to
  # cores on your machine).

For example::

  ./bootstrap.sh $HOME/research 2 > output.txt 2>&1

To build the code under ``~/research`` on a 2 core machine. The ``> output.txt
2>&1`` part is important to capture the output of running the script so that if
there are errors it is easier to track them down (the script generates a LOT of
output, which usually overflows terminal ringbuffers).

The script assumes:

- You are running on a debian-based linux environment. If you are running on
  something else (OSX, WSL, etc) you will have to manually modify the script to
  work on your target platform and/or probably have to build a **LOT** more
  stuff from source manually.

.. IMPORTANT:: If you want to build an optimized version of RCPPSW, you will
   need to manually modify the ``bootstrap.sh`` script that you copied, or
   re-run ``cmake`` and ``make`` with the proper LIBRA arguments to generate an
   optimlized build.

The script is configured such that it will stop if any command fails. So if the
script makes it all the way through and you see a ``BOOTSTRAP SUCCESS!`` line at
the end of the ``output.txt``, then you know everything worked. Otherwise look in
the ``output.txt`` for the error and fix it and try running the script again (the
script **should** be idempotent).

Other Projects (in descending probability of interest)
------------------------------------------------------

- `FORDYCA <https://fordyca.readthedocs.io>`_
- `COSM <https://cosm.readthedocs.io>`_
- `RCSW <https://rcsw.readthedocs.io>`_
- `SIERRA <https://sierra.readthedocs.io>`_
