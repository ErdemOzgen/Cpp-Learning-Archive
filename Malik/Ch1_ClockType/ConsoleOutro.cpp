/*
Program name: ConsoleOutro.cpp
Version: 1.0
Author: Ian A Schafer
Date: 05-June-2018
Description: Implementation file for ConsoleOutro.h
*/

#include <windows.h>


#include "ConsoleOutro.h"

using namespace std;

ConsoleOutro::ConsoleOutro()
{
    //ctor
}

ConsoleOutro::~ConsoleOutro()
{
    // Whatever code you prefer to keep the program running, e.g.
        system("pause"); // System outputs "Press enter to continue..."
        Sleep(5); // Wait 5 seconds
        Beep(1000, 50);
};
