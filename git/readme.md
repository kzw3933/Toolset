## Part1 Background
1. Version Control System(tracking changes)
2. Why version control
3. How to learn git

## Part2 Data models
- Thinking of history: story of snapshots
    Simple model: linear history
    Git: directed acyclic graph(DAG)

## Part3 Commands

1. Basics
 - `git help <command>`: get help for a git command
 - `git init`: create a new git repo, with data stored in the .git directory
 - `git status`: tells you what's going on
 - `git add <filename>`: add files to staging area
 - `git commit`: creates a new commit
 - `git log`: show a flattened log of history
 - `git log --all --graph --decorate`: visualizes history as a DAG
 - `git diff <filename>`: show changes you made relative to the staging area
 - `git diff <revision> <filename>`: show differences in a file between snapshots
 - `git checkout <revision>`: update HEAD and current branch 

2. Branching and merging
 - `git branch`: show branches
 - `git branch <name>`: creates a branch
 - `git checkout -b <name>`: creates a branch and switches to it
 - `git merge <revision>`: merges into current branch
 - `git rebase`: rebase set of patches onto a new base

3. Remotes
 - `git remote`: list remotes
 - `git remote add <name> <url>`: add a remote
 - `git push <remote> <local branch>:<remote branch>`: send objects to remote, and update remote reference
 - `git branch --set-upstream-to=<remote>/<remote branch>`: set up correspondence between local and remote branch
 - `git fetch`: retrieve objects/references from remote
 - `git pull`: same as git fetch;git merge
 - `git clone`: download repository from remote

4. Undo
 - `git commit --amend`: edit a commit's contents/message
 - `git reset HEAD <file>`: unstage a file
 - `git checkout -- <file>`: discard changes

5. Advanced
 - `git config`: git is highly customizable
 - `git clone --depth=1`: shallow clone, without entire version history
 - `git add -p`: interactive staging
 - `git rebase -i`: interactive rebasing
 - `git blame`: show who last edited which line
 - `git stash`: temporarily remove modifications to working directory
 - `git bisect`: binary search history
 - .gitignore: specify intentionally untracked file to ignore

## Part4 Case Studies
