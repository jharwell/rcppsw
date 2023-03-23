.. SPDX-License-Identifier: MIT

.. _ln-rcppsw-setup:

=================
Setting Up RCPPSW
=================

.. _ln-rcppsw-setup-dev:

Developer Setup
===============

#. RCPPSW uses `LIBRA <https://github.com/jharwell/libra>`_ so go to
   :ref:`ln-libra-req` and install any needed packages.

#. Setup RCPPSW's dependencies (packages is fine, unless you'll be modifying the
   dependencies too):

   - :ref:`RCSW user setup <ln-rcsw-setup-user>`

#. Clone RCPPSW and init LIBRA::

     git clone git@github.com:jharwell/rcppsw.git
     cd rcppsw
     git submodule update --init --remote --recursive

#. Build RCPPSW. From the root of the repo::

     mkdir build && cd build
     cmake <ARGS> ..
     make

   ``<ARGS>`` is a list of cmake arguments.

   .. IMPORTANT:: RCPPSW and LIBRA output **VERY** thorough summaries of their
                  build configuration, so check them to make sure you are
                  building what you think you are.


   You can pass any option as part of ``<ARGS>`` that LIBRA supports (see
   :ref:`ln-libra-capabilities`). RCPPSW supports the following additional
   options:

   .. list-table::
      :header-rows: 1
      :widths: 10 10 80

      * - Argument

        - Possible Values

        - Meaning

      * - RCPPSW_AL_MT_SAFE_TYPES

        - YES/NO

        - Sets ``rcppsw::al::mt*`` to use ``std::atomic`` types if
          enabled. Otherwise, uses non-atomic versions. Default=YES.

      * - RCPPSW_ER_OLD_LOG4CXX

        - YES/NO

        - Sets ``rcppsw::er`` to use an older version of log4cxx. Needed for
          older versions of the library with slightly different
          API. Default=NO.
