// math.IXX
// "\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.24.28314\bin\Hostx64\x64\cl.exe" /std:c++latest /experimental:module /TP /EHsc /MD /c math.IXX /module:interface /Fo: math.obj /module:output math.pcm
// "\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.24.28314\bin\Hostx64\x64\cl.exe" /std:c++latest /experimental:module /TP /EHsc /MD /c module_test.cpp /module:reference math.pcm /Fo: module_test.obj
// "\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.24.28314\bin\Hostx64\x64\cl.exe" math.obj module_test.obj
// LINK : fatal error LNK1104: Datei "MSVCRT.lib" kann nicht geöffnet werden.
// LINK : fatal error LNK1104: Datei "OLDNAMES.lib" kann nicht geöffnet werden.
// "\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.24.28314\bin\Hostx64\x64\cl.exe" "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.24.28314\lib\x64\msvcrt.lib" "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.24.28314\lib\x64\oldnames.lib" module_test.obj math.obj


export module math;

export int add(int fir, int sec){
    return fir + sec;
} 