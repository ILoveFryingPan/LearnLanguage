@echo off
choice /c mnp /m ѧϰchoice�������ﵯ����仰
rem errorlevel ������ʾ���ڵ���ĳֵ������Ҫ�Ӵ�С����
if %errorlevel%==3 goto pp
if %errorlevel%==2 goto nn
if %errorlevel%==1 goto mm
:mm
echo ѡ����m
goto end
:nn
echo ѡ����n
goto end
:pp
echo ѡ����p
goto end
:end
pause