# Contributing/Development Guide

## Development Setup

If you are going to be doing any development in RCPPSW, you will also need the
following programs, as running them is part of the development workflow:

- cppcheck (static analysis).
- clang-check-3.8 (syntax checking/static analysis). 3.8 is the minimum; 4.0
  recommended (better warnings).
- clang-format-4.0 (automatic code formatting).
- clang-tidy-4.0 (static analysis/automated checking of naming conventions). 3.8
  is the minimum; 4.0 is recommended (better warnings).
- gcov (for viewing code coverage).

You will also need to:

1. clone https://github.com/jharwell/devel somewhere, and adjust a few more
   symlinks (or just download these files and place them directly in wherever
   you cloned `rcppsw`):

   `<rcppsw root>/.clang-format` -> `<develroot>/templates/.clang-format`

   `<rcppsw root>/.clang-tidy` -> `<develroot>/templates/.clang-tidy`

Some additional cmake config options that may be of interest:

- `BUILD_SHARED_LIBS` - Build shared instead of static libraries [Default=YES].

- `WITH_CHECKS` - Build in run-time checking of code [Default=NO].

- `BUILD_TESTS` - Build tests. [Default=NO].

- `WITH_OPENMP` - Enable OpenMP code [Default=NO].

- `WITH_MPI` - Enable MPI code [Defaut=NO].

- `WITH_FPC` - `FPC_RETURN` or `FPC_ABORT` [Default=`FPC_ABORT`]. This controls the
             behavior a Function PreCondition (FPC) fails: Either return a
             specified error or halt the program.

- `ER_NDEBUG` - Disable printing of assertion failures when `NDEBUG` is defined
  (as for optimized builds). [Default=1].

The cmake config supports the following compilers: `g++, clang++, icpc`; any one
can be selected as the `CMAKE_CXX_COMPILER`, and the correct compile options
will be populated.

## Directory layout

- `src/` - All `.cpp` files live under here.

- `include/` - All `.hpp` files live under here.

- `tests` - All test code lives under here.

- `docs/` - All documentation besides this README lives under here.

- `VERSION` - A file in the root root that holds the current/next versions of
  the code. Versions are numbered as `major.minor.patch`, and is updated in
  accordance with semantic versioning/GitFlow:

  - `major` corresponds to releases/milestones in the code, and is only updated when `devel` is merged to
    `master`.

  - `minor` corresponds to the addition of new features/major refactorings.

  - `patch` corresponds to fixing bugs/documentation updates/etc.

  You should never modify this file directly.

## Development Guides
### C++ Style Guide

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

### Documentation Style

`If it is hard to document, it is probably wrong`,

as I was told in my youth, and to that end all contributions *must* be
properly documented.

- All classes should have:

    - A doxygen brief
    - A group tag

- All non-getter/non-setter member functions should be documentated with at least a
  brief, UNLESS those functions are overrides/inherited from a parent class, in
  which case they should be left blank (usually) and their documentation be in
  the class in which they are initially declared. All parameters should be
  documented.

Tricky/nuanced issues with member variables should be documented, though in
general the namespace name + class name + member variable name + member variable
type should be enough documentation. If its not, chances are you are naming
things somewhat obfuscatingly.

### Git Commit Messages

- Use the present tense ("Add feature" not "Added feature")
- Use the imperative mood ("Move cursor to..." not "Moves cursor to...")
- Limit the first line to 72 characters or less
- Reference issues and pull requests liberally after the first line
- Consider starting the commit message with an applicable emoji:

  - :art: `:art:` when improving the format/structure of the code
  - :racehorse: `:racehorse:` when improving performance
  - :penguin: `:penguin:` when fixing something on Linux
  - :apple: `:apple:` when fixing something on macOS

  - :non-potable_water: `:non-potable_water:` when plugging memory leaks
  - :memo: `:memo:` when writing docs
  - :bug: `:bug:` when fixing a bug
  - :fire: `:fire:` when removing code or files
  - :white_check_mark: `:white_check_mark:` when adding tests
  - :lock: `:lock:` when dealing with security
  - :arrow_up: `:arrow_up:` when upgrading dependencies
  - :arrow_down: `:arrow_down:` when downgrading dependencies
  - :shirt: `:shirt:` when removing linter warnings

### Issues Labelling

All issues that are entered into github should have a `Priority`, a `Status`,
and a `Type` associated with them. Well usually. Sometimes it doesn't make
sense (Question for example) to have all three. Furthermore, they should all
follow the [docs/ISSUE_TEMPLATE.md](ISSUE_TEMPLATE).

Priorities:

- `Critical` - Things that are main features/super important, or are
  segmentation-fault level bugs, as in "this must be fixed/addressed now before
  we can move forward".

- `Major` - Things that support/are main project features, but are not blocking
  other tasks.

- `Minor` - Things that would be nice to have (think enhancements), but that are
  not required at the moment, but will be needed at some point in the near-ish
  future.

- `Low` - Things that are not blocking any other tasks, can be implemented
  anytime without compromising the project in any way. A "wishlist" of things
  that would be nice to add, as it were.

Statuses:

- `Available` - The task is available to be worked on.

- `Blocked` - The task is blocked waiting for the completion of another task.

- `Completed` - The task has been completed. All tasks should be in this state
  before the issue is closed.

- `Future` - It is not possible to work on the task at the moment, because too
  much development needs to happen to make it accessible, or that it is
  something worth considering adding in the future, when the project is more
  mature.

- `In Progress` - The task is currently being worked on.

- `Review Needed` - The task has been completed, but needs to be reviewed (this
  should be tied to a pull request) before it can be moved to the completed
  state.

Types:

- `Bugfix` - This is a task to address a bug in the code.

- `Docs` - This is a task related to creating/updating documentation.

- `Enhancement` - This is a task that extends the functionality of an existing
  part of the code, but not so far that it is considered a new feature.

- `Feature` - This is a task that adds new functionality to the code.

- `Question` - This is not a task per-se, but a question whose resolution will
  lead to the creation of enhancements/features/refactors.

- `Refactor` - This is a task to refactor the code, not changing functionality
  but modifying the interface, changing data structures, etc. This should be
  accompanied by unit tests if applicable.

- `Task` - This is a task that relates to "chore" work for the project. Renaming
  files, moving things around, mucking about with the build process are all good
  examples of things that should get a `Task` label.

### Testing

All submitted *new* classes should have associated unit tests, one for each
major public function that the class provides. For any *existing* classes that
have *new* public functions added, a new unit test should also be added. It is
not possible to create unit tests for all classes, as some can only be tested in
an integrated manner, but there many that can and should be tested in a stand
alone fashion.

As part of each issue addressal, a `gcov`/`gcovr` report showing full
code coverage in the new class/new functions should be attached.

## Working from a clone, rather than a forked repo
If you fork the repo rather than cloning it, you can use whatever style of
development (issues, branches, etc.) that you prefer, and you only need to worry
about conforming to the documentation, C++, and git commit style guides . If you
clone it and are pushing directly to this repo, rather than submitting pull
requests, then the following additional guidelines apply.

### Branches

All branches should have a corresponding issue on github, and the issue should
be named the *same* thing as the branch. This may seem pedantic, but when you
have hundreds or thousands of issues and branches, any little thing you can do
to increase the self-documenting nature of the development process is worth
doing. I don't generally delete branches, so you should be able to see how they
should be named/link to github issues by browsing the repo.

### General Workflow

1. Find an issue on github to work on that looks interesting/doable, possibly
   discussing it with the project's main author(s).

2. Mark said task as `Status: In Progress` so no one else starts working on it
   too, and assign it to yourself if it is not already assigned to you.

3. Branch off of the `devel` branch with a branch with the *SAME* name as the
   issue.

4. Work on the issue/task, committing as needed. You should push your changes
   regularly, so people can see that the issue is being actively worked on. Your
   commit messages don't have to be an essay, but they should all reference the
   issue # of the task so that in-progress commits show up in github, and
   describe what was done and why in reasonable detail. Don't do things like "in
   progress", or "misc updates", or if you do such things, rebase/collapse your
   history into a single detailed commit when you are done BEFORE merging to
   devel. Be sure you know what you are doing if you go this route...

   *DO NOT REBASE/REWRITE HISTORY ON* `devel` *OR* `master` *BRANCHES.*

   In addition, you may need to put an appropriate tag for semantic versioning
   somewhere in your message (I usually put it at the bottom), depending on if
   you are working on something whose TYPE matches one of the ones listed below:

        +semver: feature
        +semver: bugfix
        +semver: docs
        +semver: enh

   There should only be ONE semantic versioning tag for each issue/task you are
   working on, so you should add it on the last commit on your branch before you
   merge to devel. The "main" commit should also have a form like this:

        <TYPE>(#issue_number): Subject

   Where TYPE is one of the types listed above.

5. If you create any new functions/classes that can be unit tested, then define
   appropriate unit tests for them, and prepare a report documenting code
   coverage, as described above.

6. Run static analysis on the code:

        make static-check-all

   Pay special attention to files that you have changed. Fix anything the
   static analyzers flag.

   If you are feeling REALLY adventurous, you can run this one on the code too,
   which takes *much* longer:

        make cppcheck-all

7. Run the style checker on the code:

        make tidy-check-all

   Not everything flagged should/can be fixed, so only pay attention to things
   that it flags in code YOU have changed. If you aren't sure, ask someone.

8. Run the clang formatter on the code to fix any formatting things you may have
   inadverdently missed.

        make format-all

9. Change status to `Status: Needs Review` and open a pull request (if working
   from a forked repo), or mention the project's main author in the correspond
   issue to bring it to their attention (if working from a cloned repo). In the
   latter case, they will review the commits. If you created unit tests, attach
   a log/run showing they all pass, as well as the code coverage report from
   gcov.

10. Once the task has been reviewed and given the green light, merge it into
    devel, and marked the issue as `Status: Completed`, and close the issue.
