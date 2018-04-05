# C++ Development Guide

## Coding Style

Generally speaking, I follow the "do as the standard library does" mantra for
this project. In particular:

- All source files have the `.cpp` extension, and all header files have the
  `.hpp` extension.

- All file, class, variable, enum, namespace, etc. names are
  `specified_like_this`, NOT `specifiedLikeThis` or
  `SpecifiedLikeThis`. Rationale: Most of the time you shouldnot really need to
  know whether the thing in between `::` is a class, namespace, enum, etc. You
  really only need to know what operations it has.

- Exactly one class/struct definition per .cpp/.hpp file, unless there is a very
  good reason to do otherwise.

- The namespace hierarchy exactly corresponds to the directory hierarchy that
  the source/header files for classes can be found in.

- Code should pass the google C++ linter, ignoring the following items. For
  everything else, the linter warnings should be addressed.

  - Use of non-const references--I do this all the time.

  - Header ordering (whatever the auto-formatter does is fine, but should
    generally be google style).

  - rand_r() instead of rand() (I use random(), which it does not flag).

  - Line length >= 80 ONLY if it is only 1-2 chars too long, and breaking the
    line would decrease readability. The formatter generally takes care of this
    too.

- Code should pass the clang-tidy linter, which checks for style elements like:

  - All members prefixed with `m_`

  - All constant members prefixed with `mc_`.

  - All global variables prefixed with `g_`.

  - All functions less than 100 lines, with no more than 5 parameters/10
    branches. If you have something longer than this, 9/10 times it can and
    should be split up.

## Documentation

As I was told in my youth:

`If it is hard to document, it is probably wrong`

To that end all contributions *must* be properly documented.

- All classes should have:

    - A doxygen brief
    - A group tag

- All non-getter/non-setter member functions should be documentated with at
  least a brief, UNLESS those functions are overrides/inherited from a parent
  class, in which case they should be left blank (usually) and their
  documentation be in the class in which they are initially declared. All
  parameters should be documented.

Tricky/nuanced issues with member variables should be documented, though in
general the namespace name + class name + member variable name + member variable
type should be enough documentation. If its not, chances are you are naming
things somewhat obfuscatingly.

## Testing

As I was also told in my youth:

`If it is hard to test, it is almost assuredly wrong`

To that end, all NEW classes should have some basic unit tests associated with
them, when possible (one for each major public function that the class
provides). For any *existing* classes that have *new* public functions added, a
new unit test should also be added. It is not possible to create unit tests for
all classes, as some can only be tested in an integrated manner, but there many
that can and should be tested in a stand alone fashion.
