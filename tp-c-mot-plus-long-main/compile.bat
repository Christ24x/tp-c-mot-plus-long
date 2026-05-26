@echo off
REM Script de compilation pour le projet "mot le plus long"
REM Prérequis: MinGW-w64 ou gcc doivent être installés et dans le PATH

echo Compilation du projet...
gcc main.c save.c -o jeu.exe

if errorlevel 1 (
    echo Erreur: la compilation a echouee.
    echo Verifiez que gcc est installe et dans le PATH.
    pause
    exit /b 1
)

echo Compilation reussie!
echo Execution du programme...
.\jeu.exe

pause
