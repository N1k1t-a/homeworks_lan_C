@echo off
chcp 1251 > nul
echo ====================================
echo   Компиляция программы DFS
echo ====================================
echo.

g++ main.cpp graph.cpp -o laba20.exe -std=c++11

if %ERRORLEVEL% EQU 0 (
    echo [OK] Компиляция выполнена успешно!
    echo Исполняемый файл: laba20.exe
    echo.
    echo Для запуска введите: laba20.exe
) else (
    echo [ОШИБКА] Ошибка компиляции!
)

pause
