/*
 * =====================================================================================
 *
 *       Filename:  fig20_05.cpp
 *
 *    Description:  Fig. 20.5 - List Class test program
 *
 *        Version:  1.0
 *        Created:  13/03/17 14:22:49
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include "List.hpp"

#include <iostream>
#include <string>

// display program instructions to user
void instructions() {
    std::cout << "Enter one of the following:\n"
              << " 1 to insert at beginning of list\n"
              << " 2 to insert at end of list\n"
              << " 3 to delete from beginning of list\n"
              << " 4 to delete from end of list\n"
              << " 5 to end list processing\n";
}
// function to test a list
template <typename T>
void testList(List<T> &listObject, const std::string &typeName) {
    std::cout << "Testing a List of " << typeName << " values\n";
    instructions();

    int choice;
    T value;

    do {
        std::cout << "? ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter " << typeName << ": ";
                std::cin >> value;
                listObject.insertAtFront(value);
                listObject.print();
                break;
            case 2:
                std::cout << "Enter " << typeName << ": ";
                std::cin >> value;
                listObject.insertAtBack(value);
                listObject.print();
                break;
            case 3:
                if (listObject.removeFromFront(value))
                    std::cout << value << " removed from list\n";

                listObject.print();
                break;
            case 4:
                if (listObject.removeFromBack(value))
                    std::cout << value << " removed from list\n";

                listObject.print();
                break;
        }
    } while (choice < 5);

    std::cout << "End list test\n\n";
}
int main(int argc, const char *argv[]) {
    List<int> integerList;
    testList(integerList, "integer");

    List<double> doubleList;
    testList(doubleList, "double");

    return 0;
}
