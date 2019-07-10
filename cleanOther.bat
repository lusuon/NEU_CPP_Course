@echo off
for /r %%i in (debug,release,ipch) do rd /s /q "%%i"
pause