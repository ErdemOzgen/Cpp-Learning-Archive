/*
Program name: Clox
Version: 0.0
Author: Ian A Schafer (this main file)
Date: 05-June-2018
Description: Creation of Class and Assoc Implementation file.
Refer: D.S. Malik, Ch1
*/

#include <iostream>
#include "clockType.h"
#include "ConsoleOutro.h"

using namespace std;

int main()
{
    ConsoleOutro Outro;

    cout << "-------------------------------" << endl;
    cout << "         CloX Program" << endl;
    cout << "-------------------------------" << endl;
    cout << endl;

    clockType clox;

    clox.setTime(21, 02, 12);
    cout << "Time: ";
    clox.printTime();
    cout << endl;
    cout << endl;

    return 0;
}
