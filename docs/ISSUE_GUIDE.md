# Issues Usage Guihe

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

- `Research` - The task is open-ended, requiring paper reading and/or lots of
  experiment running, analyzing, etc.

## Branches

All branches should have a corresponding issue on github, and the issue should
be named the *same* thing as the branch. This may seem pedantic, but when you
have hundreds or thousands of issues and branches, any little thing you can do
to increase the self-documenting nature of the development process is worth
doing. I don't generally delete branches, so you should be able to see how they
should be named/link to github issues by browsing the repo.
