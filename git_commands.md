
git --version
git config --global user.name " "
git config --global user.email " "
git config --list

git clone <link>
git status           ~ displays the status of the code
ls -a                ~ shows hidde files

git add <file name>
git add .           ~ add all modified files to git
git commit -m <commit message>
git push origin main

git rm --cached <file>    ~ to unstage
git restore -staged <file>   ~to unstage
git restore <file>       ~ to discard changes in working directory

# create repo from local to github
git init
git remote add origin <link>
git remote -v            ~ to verify remote
git branch              ~ to check branch
git branch -M main      ~ to rename branch
git push -u origin main     ~ -u is to set upstream

git checkout -b <branch name>      ~ to create new branch & checkout
git branch -d <branch name>       ~ to delete branch
git diff <branch name>
git merge <branch name>
git log                 ~ to check commits

# to revert added changes
git reset <file name>
git reset

# to revert last committed change
git reset HEAD~1            OR          git reset <commit hash>             OR          git reset --hard <commit hash>