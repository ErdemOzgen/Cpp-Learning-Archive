/*
Program name: main.cpp
Version: 1.0
Author: Ian A Schafer
Date: 25-June-2018
Description: Test file for mergeLists function of class orderedLinkedList.h
*/

#include <windows.h>
#include "ConsoleOutro.h"
#include <iostream>
#include "orderedLinkedList_v2.h"

using namespace std;

int main()
{
    cout << "-----------------------------------------------" << endl;
    cout << "           Test Program - mergeLists" << endl;
    cout << "-----------------------------------------------" << endl;

    ConsoleOutro Outro;

    cout << endl;
    orderedLinkedList<int> newList;
    orderedLinkedList<int> list1;
    orderedLinkedList<int> list2;

    cout << "main populating list1 .. ";
    list1.insert(2);
    list1.insert(6);
    list1.insert(7);
    list1.insert(97);
    list1.insert(98);
    cout << endl;

    cout << "main printing list1 .. ";
    list1.print();
    cout << endl << endl;

    cout << "main populating list2 .. ";
    list2.insert(3);
    list2.insert(5);
    list2.insert(8);
    list2.insert(99);
    list2.insert(100);
    cout << endl;

    cout << "main printing list2 .. ";
    list2.print();
    cout << endl << endl;

    cout << "-------> Calling mergeLists function ------->" << endl;

    newList.mergeLists(newList, list1, list2);

    cout << "main printing list1 .. ";
    list1.print();
    cout << endl;

    cout << "main printing list2 .. ";
    list2.print();
    cout << endl;

    cout << "main printing newList .. ";
    newList.print();
    cout << endl << endl;


    return 0;
}//End main
