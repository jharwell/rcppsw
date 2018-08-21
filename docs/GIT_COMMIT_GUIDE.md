# Git Commit Guide

- Use the present tense ("Add feature" not "Added feature")
- Use the imperative mood ("Move cursor to..." not "Moves cursor to...")
- Limit the first line to 72 characters or less
- Reference issues and pull requests liberally after the first line
- Your commit messages don't have to be an essay, but they
  should all reference the issue # of the task so that in-progress commits show
  up in github, and describe what was done and why in reasonable detail. Don't
  do things like "in progress", or "misc updates", or if you do such things,
  rebase/collapse your history into a single detailed commit when you are done
  BEFORE merging to devel.

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
