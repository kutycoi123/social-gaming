# Project Workflow Guide

### Project Organization
*Are there any rules related to project organization (i.e. how folders/directories are organized)?*

### Git Workflow
* NEVER push directly into master. Always create a separate branch when making any change, no matter how small.
* Consistently merge master branch into your working branch to reduce the size of merge conflicts.
* NEVER delete any branches (as per the course rules).
* NEVER squash any commits (as per the course rules).

### Build
* ALWAYS build your project (using the README.md) in order to be able to merge your work in. Never break the build with your MR.
* Furthermore, it is advisable to run the project to test if any features have been impacted (ESPECIALLY if you are directly working on the feature).

### Code Review
* It is generally advisable to create a WIP ("Work-In-Progress") merge request when a branch is not completed, but still needs some review (or to show progress).
* Any MR that is not marked as WIP is assumed to be completed work (but not necessary code reviewed).
* Any MR MUST have at least 2 thumbs up from other teammates prior to being merged. The person who made the merge request must be responsible for merging the branch.

### Branch Naming
*Are there any rules in branch naming that apply here?*

### C++/Code Standard
* The code specific guidelines are in the 'Coding Standards.md' file in the root directory.