/*
Program name: ConsoleOutro.h
Version: 1.0
Author: Ian A Schafer
Date: 05-June-2018
Description: Tool for terminating console apps gracefully. Requires #include <windows.h>
*/


#ifndef CONSOLEOUTRO_H
#define CONSOLEOUTRO_H

//    Tool for terminating console apps gracefully.
//    Requires #include <windows.h>
//
//    Inspired by ropez (MSc grad from 	Tromsø, Norway) in forum post on http://www.cplusplus.com/forum/beginner/1988/
//
//    Summary of above forum reference:
//    First I would search for the setting in my IDE that says "Keep console window open after program terminates".
//    If none ... let them know and use the following,
//
//    Typical suggestions to delay closing a console app assume that the program will reach the end of main().
//    For example, cin.get();, System (Pause);, Sleep(NNNN);
//
//    They do not work in the case of exceptions:
//    if (somethingFailed())
//        return SOME_ERROR_CODE;
//
//    This class keeps the console open, even if it doesn't reach the end of main for some reason.
//    BTW: Of course, remember to remove this code before the program is "released".
//
//    Thanks ropez ... may you live long and prosper

class ConsoleOutro
{
    public:
    ConsoleOutro();
   ~ConsoleOutro();
 };

#endif // CONSOLEOUTRO_H
