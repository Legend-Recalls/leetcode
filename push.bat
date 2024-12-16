@echo off
:: Add all changes to the staging area
git add .

:: Extract commit number from the .iteration file
for %%f in (*.iteration) do (
    for /f "tokens=1 delims=." %%a in ("%%f") do set number=%%a
)

:: Count the number of files added to the staging area
for /f %%c in ('git diff --cached --name-only ^| find /c /v ""') do set fileno=%%c

:: Display commit information
echo This is commit number %number%
echo Number of files added: %fileno%

:: Commit with the extracted commit number and file count
git commit -m "commit no. %number%.. + %fileno% files added"

:: Increment the commit number
set /a newnumber=%number%+1

:: Update the .iteration file with the new commit number
(for %%f in (*.iteration) do (
    echo %newnumber% > %%f
))

:: Push the commit
git push
