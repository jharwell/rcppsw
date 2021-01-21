Design Patterns
===============

Decorator
---------

Decorator
---------

.. doxygenclass:: decorator
   :project: patterns

.. doxygenclass:: ptr_decorator
   :project: patterns

Macros
######

.. doxygendefine:: RCPPSW_DECORATE_FUNC
   :project: patterns

.. doxygendefine:: RCPPSW_DECORATE_FUNC_TEMPLATE
   :project: patterns

Factory
-------

.. doxygenclass:: releasing_factory
   :project: patterns

.. doxygenclass:: sharing_factory
   :project: patterns

.. doxygenclass:: multifactory
   :project: patterns

.. doxygenclass:: sharing_multifactory
   :project: patterns

.. doxygenclass:: releasing_multifactory
   :project: patterns

FSM
---

Core Classes
############

.. doxygenclass:: base_fsm
   :project: patterns

.. doxygenclass:: simple_fsm
   :project: patterns

.. doxygenclass:: hfsm
   :project: patterns

Other Classes
#############

.. doxygenclass:: event_signal
   :project: patterns

.. doxygenclass:: event_type
   :project: patterns

.. doxygenclass:: event_data
   :project: patterns

.. doxygenclass:: no_event_data
   :project: patterns

.. doxygenclass:: state
   :project: patterns

.. doxygenclass:: state_entry
   :project: patterns

.. doxygenclass:: state_exit
   :project: patterns

.. doxygenclass:: state_guard
   :project: patterns

.. doxygenclass:: state_map_ex_row
   :project: patterns

.. doxygenclass:: state_map_row
   :project: patterns

.. doxygenclass:: hfsm_state
   :project: patterns


:class:`simple_fsm` State Macros
################################

The ``*_STATE()``, ``*_GUARD()``, ``*_ENTRY()``, ``*_EXIT()`` macros all have
variants which do not have a data argument, and have ``_ND`` appended to their
name (not documented here to save space).

.. doxygendefine:: RCPPSW_FSM_STATE_DECLARE
   :project: patterns

.. doxygendefine:: RCPPSW_FSM_STATE_DEFINE
   :project: patterns

.. doxygendefine:: RCPPSW_FSM_GUARD_DECLARE
   :project: patterns

.. doxygendefine:: RCPPSW_FSM_GUARD_DEFINE
   :project: patterns

.. doxygendefine:: RCPPSW_FSM_ENTRY_DECLARE
   :project: patterns

.. doxygendefine:: RCPPSW_FSM_ENTRY_DEFINE
   :project: patterns

.. doxygendefine:: RCPPSW_FSM_EXIT_DECLARE
   :project: patterns

.. doxygendefine:: RCPPSW_FSM_EXIT_DEFINE
   :project: patterns


:class:`simple_fsm` Transition Map Macros
#########################################

.. doxygendefine:: RCPPSW_FSM_DEFINE_TRANSITION_MAP
   :project: patterns

.. doxygendefine:: RCPPSW_FSM_VERIFY_TRANSITION_MAP
   :project: patterns

:class:`simple_fsm` State Map Macros
####################################

.. doxygendefine:: RCPPSW_FSM_DECLARE_STATE_MAP
   :project: patterns

.. doxygendefine:: RCPPSW_FSM_DEFINE_STATE_MAP
   :project: patterns

.. doxygendefine:: RCPPSW_FSM_DEFINE_STATE_MAP_ACCESSOR
   :project: patterns

.. doxygendefine:: RCPPSW_FSM_STATE_MAP_ENTRY
   :project: patterns

.. doxygendefine:: RCPPSW_FSM_STATE_MAP_ENTRY_EX
   :project: patterns

.. doxygendefine:: RCPPSW_FSM_STATE_MAP_ENTRY_EX_ALL
   :project: patterns

:class:`hfsm` State Macros
##########################

Only differences with the ``RCPPSW_FSM_*`` macros are documented here, along
with new HFSM specific macros. For all other macros, replacing ``FSM`` with
``HFSM`` is sufficient. The ``*_STATE()``, ``*_GUARD()``, ``*_ENTRY()``,
``*_EXIT()`` macros all have variants which do not have a data argument, and
have ``_ND`` appended to their name (not documented here to save space).

.. doxygendefine:: RCPPSW_HFSM_STATE_INHERIT
   :project: patterns

.. doxygendefine:: RCPPSW_HFSM_EXIT_INHERIT
   :project: patterns

.. doxygendefine:: RCPPSW_HFSM_ENTRY_INHERIT
   :project: patterns

.. doxygendefine:: RCPPSW_HFSM_STATE_DECLARE
   :project: patterns

.. doxygendefine:: RCPPSW_HFSM_ENTRY_DECLARE
   :project: patterns

.. doxygendefine:: RCPPSW_HFSM_EXIT_DECLARE
   :project: patterns

.. doxygendefine:: RCPPSW_HFSM_CONSTRUCT_STATE
   :project: patterns

:class:`hfsm` Transition Map Macros
###################################

Only differences with the ``RCPPSW_FSM_*`` macros are documented here, along
with new HFSM specific macros. For all other macros, replacing ``FSM`` with
``HFSM`` is sufficient.

:class:`hfsm` State Map Macros
##############################

Only differences with the ``RCPPSW_FSM_*`` macros are documented here, along
with new HFSM specific macros. For all other macros, replacing ``FSM`` with
``HFSM`` is sufficient.

PIMPL
-----

.. doxygenclass:: pimpl
   :project: patterns

Prototype
---------

.. doxygenclass:: caching_factory
   :project: patterns

.. doxygenclass:: clonable
   :project: patterns

Singleton
---------

.. doxygenclass:: singleton
   :project: patterns

Visitor
---------

.. doxygenclass:: visit_set
   :project: patterns

.. doxygenclass:: precise_visit_set
   :project: patterns

.. doxygenclass:: precise_visitor
   :project: patterns

.. doxygenclass:: filtered_visitor
   :project: patterns

.. doxygenclass:: polymorphic_accept_set
   :project: patterns
