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

- All structs that are "types" (i.e. convenientt wrappers around a boolean
  status + possibly valid result of an operation) should have a `_t` postfix so
  that it is clear when constructing them that they are types and it is not a
  function being called (calls with `()` can seem ambiguous if you don't know
  the code). Types are collections of data members that generally should be
  treatable as POD, even if they are not (e.g. contain a std::vector).

- Exactly one class/struct definition per .cpp/.hpp file, unless there is a very
  good reason to do otherwise.

- The namespace hierarchy exactly corresponds to the directory hierarchy that
  the source/header files for classes can be found in.

- Code should pass the google C++ linter, ignoring the following items. For
  everything else, the linter warnings should be addressed.

  - Use of non-const references--I do this occasionally. When possibly, const
    references should be used, but sometimes it is more convenient to use a
    non-const reference. Case by case.

  - Header ordering (whatever the auto-formatter does is fine, but should
    generally be google style).

  - Line length >= 80 ONLY if it is only 1-2 chars too long, and breaking the
    line would decrease readability. The formatter generally takes care of this
    too.

- Function Parameters (most of these from Herb Sutter's excellent C++ guidelines
  on smart pointers
  [here](https://herbsutter.com/2013/05/29/gotw-89-solution-smart-pointers/)).

  - Function inputs should use `const` to indicate that the parameter is
    input-only (`&` or `*`).

  - `std::shared_ptr` should be passed by VALUE to a function when the function
    is going to take a copy and share ownership, and ONLY then.

  - Pass `std::shared_ptr` by `&` if the function is itself not going to take
    ownership, but a function/object that it calls will. This will avoid the
    copy on calls that don't need it.

  - `const std::shared_ptr<T>&` should be not be used--use `const T*` to
      indicate non-owning access to the managed object.

  - `std::unique_ptr` should be passed by VALUE to a "consuming" function
    (i.e. whatever function is ultimately going to claim ownership of the
    object).

  - `std::unique_ptr` should NOT be passed by reference, unless the function
    needs to replace/update/etc the object contained in the unique_ptr. It
    should never be passed by constant reference.

  - Raw pointers should be used to express the idea that the pointed to object
    is going to outlive the function call and the function is just going to
    observe/modify it.

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
