@echo off
setlocal enabledelayedexpansion

set input_file=small_sum.in
set output_file=small_sum.txt
set temp_file=output_temp.txt

type nul > %output_file%

for /f "tokens=*" %%a in (%input_file%) do (
    client_bignumber.exe < %%a >> %temp_file%
)

type %temp_file% >> %output_file%

del %temp_file%
