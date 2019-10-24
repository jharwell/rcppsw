Contributing
============

`C++ development guide <https://github.com/swarm-robotics/libra/tree/devel/cxx-dev-guide.md>`_

`Git commit guide <https://github.com/swarm-robotics/libra/tree/devel/git-commit-guide.md>`_.

`Git issue guide <https://github.com/swarm-robotics/libra/tree/devel/git-issue-guide.md>`_

Workflow
--------

For the general contribution workflow, see the docs over in `libra
<https://github.com/swarm-robotics/libra/tree/devel/workflow.md>`_

For the static analysis step:

#. Run static analysis on the code::

     make static-check-all

   Pay special attention to files that you have changed. Fix anything the
   static analyzers flag.

   If you are feeling REALLY adventurous, you can run this one on the code too,
   which takes *much* longer::

     make cppcheck-all

#. Run the style checker on the code::

     make tidy-check-all

   Not everything flagged should/can be fixed, so only pay attention to things
   that it flags in code YOU have changed. If you aren't sure, ask someone.

#. Run the clang formatter on the code to fix any formatting things you may have
   inadverdently missed::

     make format-all
