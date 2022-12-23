.. SPDX-License-Identifier: MIT

.. _ln-rcppsw-usage:

===================================
Using RCPPSW: Runtime Configuration
===================================

All of RCPPSW's runtime configuration parameters are read from XML (for the
moment). Its structure supports other types of sources.

XML Configuration
=================

RCPPSW Uses the following conventions when describing its XML configuration:

- Multiple choices for an XML attribute value are separated by a ``|`` in the
  example XML.

- XML attributes that should be floating point are specified as ``FLOAT`` in the
  example XML (acceptable range, if applicable, is documented for each
  individual attribute).

- XML attributes that should be integers are specified as ``INTEGER`` in the
  example XML (acceptable range, if applicable, is documented for each
  individual attribute).


The following root XML tags are defined:

.. list-table::
   :widths: 25,75
   :header-rows: 1

   * - Root XML Tag

     - Description

   * - ``output``

     - Parameters for logging application metrics/results.

.. toctree::
   :maxdepth: 2
   :caption: XML Configuration Details:

   output.rst
