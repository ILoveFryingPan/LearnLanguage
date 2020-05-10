@echo off
choice /c mnp /m 学习choice，在哪里弹出这句话
rem errorlevel 变量表示大于等于某值，所以要从大到小排序
if %errorlevel%==3 goto pp
if %errorlevel%==2 goto nn
if %errorlevel%==1 goto mm
:mm
echo 选择了m
goto end
:nn
echo 选择了n
goto end
:pp
echo 选择了p
goto end
:end
pause