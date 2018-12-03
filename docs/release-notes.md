# Breaking Changes

- Switched to log4cxx for logging instead of homegrown library.

# New Features

- Fleshed out math library for vectors, degrees, radians.
- Overhauled the task executive / decomposition graph to work with recursive
  task partitioning at least to a beta level.
- Incorporated additional XML parsing into task allocation namespace where
  feasible for easy incorporation into fordyca.oa
- Added a lot of options for controlling input sources into task allocation
  decisions made in the executive.

# Improvements

- Remove need to have ARGoS installed for rcppsw to build (I think).
-

# Other Changes

- Now under GPL 3.0.
