@REM @echo off
set solution_dir=%cd%\src

cd tools/cmm
if not exist node_modules call npm install
call node dist/main.js --solution_dir %solution_dir%

cd ../..
if not exist build mkdir build
cd build
call cmake ../src
