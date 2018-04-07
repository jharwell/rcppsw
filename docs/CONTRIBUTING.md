# Contributing to RCPPSW

## Pre-cloning Setup

You will also need the following development packages, which can usually be
found in linux software repositories:

- catch (A unit testing framework that some unit tests use).

In addition, you way also want to install these programs for development:

- ccache (will make compiling a lot faster).
- icpc (additional syntax checking comes from Intel Parallel Studio, which is
  ~14GB).
- ctags/gtags/rtags/cscope (moving around in a large C/C++ code base).

## Post-cloning Setup

1. Clone https://github.com/jharwell/devel somewhere, and either symlink the
   below files into the repository, or just copy them directly (they are ignored
   by git).

   `<rcppsw root>/.clang-format` -> `<develroot>/templates/.clang-format`

   `<rcppsw root>/.clang-tidy` -> `<develroot>/templates/.clang-tidy`

## Directory layout

- `src/` - All `.cpp` files live under here, in their respective modules.

- `include/` - All `.hpp` files live under here.

- `docs/` - All documentation besides the main README lives under here,
  including all development/style guides.
this
- `VERSION` - A file in the root root that holds the current/next versions of
  the code. Versions are numbered as `major.minor.patch`, and is updated in
  accordance with semantic versioning/GitFlow. You should never modify this file
  directly.

## Development Guides

The following development guides should be followed:

- [C++ Development Guide](CXX_DEV_GUIDE.md)
- [Git Commit Guide](GIT_COMMIT_GUIDE.md)
- [Issue Usage Guide](ISSUE_GUIDE.md)

## General Workflow

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
