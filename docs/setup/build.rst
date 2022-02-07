===========
Debug Build
===========

.. IMPORTANT:: These instructions assume:

   - You are running on a Debian-based linux environment, specifically
     Ubuntu. If you are running on something else (OSX, WSL, etc) you will have
     to manually modify the script to work on your target platform and/or
     probably have to build a **LOT** more stuff from source manually.

   - You have sudo privileges on the machine you want to install the project on.

   If either of these conditions are not met, you will be on your own for
   getting things setup in your development environment of choice.

This project should not generally need to be built on its own, but if you DO
need to do so, download ``scripts/bootstrap.sh`` BEFORE cloning this repo. The
script can be downloaded by navigating to the file on github, clicking the
``raw`` button, and then right clicking and doing ``Save As``. After
downloading, mark the script as executable (``chmod +x bootstrap.sh``) and then
run it (it can be run from anywhere), with the following arguments:

The bootstrap script takes a number of arguments, which you can read about via::

  ./bootstrap.sh --help

The default values of the arguments should be OK for most use cases.

For example::

  ./bootstrap.sh > output.txt 2>&1

Will install system packages, and build the code under ``$HOME/research`` . The
``> output.txt 2>&1`` part is important to capture the output of running the
script so that if there are errors it is easier to track them down (the script
generates a LOT of output, which usually overflows terminal ringbuffers).

The script is configured such that it will stop if any command fails. So if the
script makes it all the way through and you see a ``BOOTSTRAP SUCCESS!`` line at
the end of the ``output.txt``, then you know everything worked. Otherwise look
in the ``output.txt`` for the error and fix it and try running the script again
(the script **should** be idempotent).
