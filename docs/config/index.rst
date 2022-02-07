=================
XML Configuration
=================

The following root XML tags are defined:

.. list-table::
   :widths: 25,50
   :header-rows: 1

   * - Root XML Tag

     - Description

   * - ``output``

     - Parameters for logging application metrics/results.

``output``
==========

- Required child attributes if present: all.
- Required child tags if present: none.
- Optional child attributes: none.
- Optional child tags: none.

XML configuration:

.. code-block:: XML

    <output
        output_parent="output"
        output_leaf="__current_date__">
        <metrics>
            ...
        </metrics>
    </output>

- ``output_parent`` - The parent directory in which the directories of
  different runs will be placed. The path specified can be relative or absolute,
  and will be created if it does not exist.

- ``output_leaf`` - The output directory for the current run under
  ``output_parent``. If you put the special field ``__current_date__`` here, the
  run will get a unique output directory in the form ``YYYY-MM-DD:HH-MM``.


``output/metrics``
------------------

- Required child attributes if present: [ ``metrics_path`` ].
- Required child tags if present: [ ``sinks`` ].
- Optional child attributes: none.
- Optional child tags: none.

XML configuration:

.. code-block:: XML

    <output>
        <metrics
            metrics_path="metrics">
            <sinks>
                ...
            </sinks>
        </metrics>
        ...
    </output>

- ``metrics_path`` - Path to the root metrics output directory *relative* to the
  output root.

Metrics are a separate configuration item than output, because it is possible
(and likely!) that applications generate more than 1 type of output.

``output/metrics/sinks``
^^^^^^^^^^^^^^^^^^^^^^^^

- Required by: all controllers.
- Required child attributes if present: none.
- Required child tags if present: none.
- Optional child attributes: none.
- Optional child tags: [ ``csv`` ].

XML configuration:

.. code-block:: XML

    <metrics>
        ...
        <sinks>
            <csv>
        </sinks>
        ...
    </metrics>

``output/metrics/sinks/csv``
""""""""""""""""""""""""""""

- Required by: none.
- Required child attributes if present: none.
- Required child tags if present: none.
- Optional child attributes: none.
- Optional child tags: [ ``append``, ``create``, ``truncate`` ].

XML configuration:

.. code-block:: XML

    <csv>
        ...
        <create
            output_interval="INTEGER"
            />
        <append
            output_interval="INTEGER"
            />
        <truncate
            output_interval="INTEGER"
            />

        ...
    </csv>


- ``output_interval`` - Required for all child tags. For ``append``, this
  defines the timestep interval after which metrics will be written out
  (appended) to the specified ``.csv`` created from the provided stem.  For
  ``create``, this defines timestep interval after which metrics will be written
  out to a NEW ``.csv`` file with a unique timestep tag after the provided
  stem. For ``truncate``, this defines the timestep interval after which metrics
  will be written out to a truncated ``.csv`` created from the provided stem;
  that is, each time they are output the results of the previously written out
  metrics are lost.

  What collectors can be added under what child tag (
  ``<append>,<create>,<truncate>`` ) is application dependent, and not defined
  here. Not defining them disables metric collection of the given type for that
  category. However, the format for enabling metric collectors is the same for
  all applications, and consists of an ``id=filename-no-extension`` XML
  attribute pair.
