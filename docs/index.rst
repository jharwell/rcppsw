==================================
Welcome to RCPPSW's documentation!
==================================

This is a collection of various useful algorithms/data structures/etc. that I
have found useful for multi-agent robots research, and that do not currently
exist in Boost, or that build on what boost provides. Includes such things as:

- Event reporting framework, built on top of Log4cxx.

- Logical task hierarchy, including executives capable of executing a task
  decomposition graph.

- Data structures involved, such as 2D/3D grid graphs,
  multiprocessing/multithreading queues/vectors, type maps.

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

   config/index.rst
   contributing/index.rst
   _api/api.rst

Directory Layout
================

- ``src/`` - All ``.cpp`` files live under here, in their respective modules.

- ``include/`` - All ``.hpp`` files live under here.

- ``docs/`` - All documentation besides the main README lives under here.

Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
