# undo working dir changes
# discard changes in working dir
git checkout -- <filename>

# unstage files
git reset HEAD <filename>

# amend commits
git commit --amend -m "message"

# revert a commit
git revert <SHA number>