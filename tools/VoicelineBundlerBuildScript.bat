@echo off

call "C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\VC\Auxiliary\Build\vcvars64.bat"

cd /d "%~dp0"

cl /std:c++latest /EHsc VoicelineBundler.cpp /Fo:"debug\VoicelineBundler.obj" /Fe:VoicelineBundler.exe

pause
