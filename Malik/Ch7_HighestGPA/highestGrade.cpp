//*************************************************************
// Author: D.S. Malik
//
// This program reads a data file consisting of students’ GPAs 
// followed by their names. The program then prints the highest
// GPA and the names of the students with the highest GPA.
//*************************************************************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "myStack.h"

using namespace std;

int main()
{
        //Step 1
    double GPA;
    double highestGPA;
    string name;

    stackType<string> stack(100);

    ifstream infile;

    infile.open("HighestGPAData.txt");          //Step 2

    if (!infile)                                //Step 3
    {
        cout << "The input file does not "
             << "exist. Program terminates!" << endl;
        return 1;
    }

    cout << fixed << showpoint;                 //Step 4
    cout << setprecision(2);                    //Step 4

    infile >> GPA >> name;                      //Step 5

    highestGPA = GPA;                           //Step 6

    while (infile)                              //Step 7
    {
        if (GPA > highestGPA)                   //Step 7.1
        {
            stack.initializeStack();            //Step 7.1.1

            if (!stack.isFullStack())           //Step 7.1.2
                stack.push(name);

            highestGPA = GPA;                   //Step 7.1.3
        }
        else if (GPA == highestGPA)             //Step 7.2
            if (!stack.isFullStack())
                stack.push(name);
            else
            {
                cout << "Stack overflows. "
                     << "Program terminates!" << endl;
                return 1;  //exit program
            }

        infile >> GPA >> name;                  //Step 7.3
    }

    cout << "Highest GPA = " << highestGPA << endl;//Step 8
    cout << "The students holding the "
         << "highest GPA are:" << endl;

    while (!stack.isEmptyStack())                   //Step 9
    {
        cout << stack.top() << endl;
        stack.pop();
    }

    cout << endl;

    return 0;
}

