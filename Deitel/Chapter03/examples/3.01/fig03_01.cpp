/*
 * =====================================================================================
 *
 *       Filename:  
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thanks to github you know it
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author: Mahmut Erdem ÖZGEN   m.erdemozgen@gmail.com
 *   
 *
 * =====================================================================================
 */
#include <iostream>

// GradeBook class definition
class GradeBook {
 public:
    // function that displays a welcome message to the Gradebook user
    void displayMessage() {
        std::cout << "Welcome to the Grade Book!" << std::endl;
    }
};

// function main begins program execution
int main(int argc, const char *argv[]) {
    GradeBook myGradeBook;  // create a GradeBook object named myGradeBook

    myGradeBook.displayMessage();

    return 0;
}
