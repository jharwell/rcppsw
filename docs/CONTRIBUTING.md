# Contributing to RCPPSW

## Pre-cloning Setup

You may want to install these programs for development:

- ccache (will make compiling a lot faster).
- icpc (additional syntax checking comes from Intel Parallel Studio, which is
  ~14GB).
- ctags/gtags/rtags/cscope (moving around in a large C/C++ code base).

## Directory layout

- `src/` - All `.cpp` files live under here, in their respective modules.

- `include/` - All `.hpp` files live under here.

- `docs/` - All documentation besides the main README lives under here,
            including all development/style guides.

- `VERSION` - A file in the root root that holds the current/next versions of
  the code. Versions are numbered as `major.minor.patch`, and is updated in
  accordance with semantic versioning/GitFlow. You should never modify this file
  directly.

## Development Guides

The following development guides should be followed:

- [LIBRA C++ Development Guide](https://github.com/swarm-robotics/libra/tree/devel/cxx-dev-guide.md)
- [LIBRA Git Commit Guide](https://github.com/swarm-robotics/libra/tree/devel/git-commit-guide.md)
- [LIBRA Issue Usage Guide](https://github.com/swarm-robotics/libra/tree/devel/git-issue-guide.md)

## General Workflow

1. Find an issue on github to work on that looks interesting/doable, possibly
   discussing it with the project's main author(s).

2. Mark said task as `Status: In Progress` so no one else starts working on it
   too, and assign it to yourself if it is not already assigned to you.

3. Branch off of the `devel` branch with a branch with the *SAME* name as the
   issue.

4. Work on the issue/task, committing as needed. You should:

   - Push your changes regularly, so people can see that the issue is being
     actively worked on. Commit messages should follow the [Git Commit
     Guide](https://github.com/swarm-robotics/libra/tree/devel/git-commit-guide.md).

   - Merge in the `devel` branch into your branch periodicaly so that merge
     conflicts/headaches are minimized.

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

9. Change status to `Status: Needs Review` and open a pull request, and someone
   will review the commits. If you created unit tests, attach a log/run showing
   they all pass, as well as the code coverage report from gcov.

10. Once the task has been reviewed and given the green light, it will be merged
    into devel and marked as `Status: Completed`, and closed (you generally
    don't need to do this).
