//This program tests various operation of a linked list
 
#include <iostream>                                 //Line 1
#include "newClock.h"                               //Line 2
#include "unorderedLinkedList.h"                    //Line 3

using namespace std;                                //Line 4

int main()                                          //Line 5
{                                                   //Line 6
    unorderedLinkedList<clockType> list1, list2;    //Line 7
    clockType cl;                                   //Line 8

    cl.setTime(5, 17, 32);                          //Line 9
    list1.insertLast(cl);                           //Line 10
    cl.setTime(18, 27, 55);                         //Line 11
    list1.insertLast(cl);                           //Line 12
    cl.setTime(3, 11, 6);                           //Line 13
    list1.insertLast(cl);                           //Line 14
    cl.setTime(22, 18, 25);                         //Line 15
    list1.insertLast(cl);                           //Line 16
    cl.setTime(11, 4, 25);                          //Line 17
    list1.insertLast(cl);                           //Line 18
    cl.setTime(6, 51, 44);                          //Line 19
    list1.insertLast(cl);                           //Line 20

    cout << "Line 21: list1: ";                     //Line 21
    list1.print();                                  //Line 22
    cout << endl;                                   //Line 23
    cout << "Line 24: Length of list1: " 
         << list1.length() << endl;                 //Line 24

    list2 = list1;	   //test the assignment operator Line 25

    cout << "Line 26: list2: ";                     //Line 26
    list2.print();                                  //Line 27
    cout << endl;                                   //Line 28
    cout << "Line 29: Length of list2: " 
         << list2.length() << endl;                 //Line 29

    int hours, minutes, seconds;                    //Line 30

    cout << "Line 31: Enter the hours, minutes, " 
         << "and seconds of the time to be "
         << "deleted: ";                            //Line 31
    cin >> hours >> minutes >> seconds;             //Line 32
    cout << endl;                                   //Line 33

    cl.setTime(hours, minutes, seconds);            //Line 34

    list2.deleteNode(cl);                           //Line 35
	
    cout << "Line 36: After deleting " << cl 
         << " list2: " << endl;                     //Line 36
    list2.print();                                  //Line 37
    cout << endl;                                   //Line 38

    cout << "Line 39: Length of list2: " 
         << list2.length() << endl;                 //Line 39

    cout << endl << "Line 40: Output list1 " 
         << "using an iterator" << endl;            //Line 40

    linkedListIterator<clockType> it;               //Line 41

    for (it = list1.begin(); it != list1.end(); 
                             ++it)                  //Line 42
        cout << *it << " ";                         //Line 43
    cout << endl;                                   //Line 44

    return 0;                                       //Line 45
}                                                   //Line 46



