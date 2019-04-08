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
#include "GradeBook.hpp"

// function main begins program excution
int main(int argc, const char *argv[]) {
    // create two GradeBook objects
    GradeBook gradeBook1("CS101 Introduction to C++ Programming");
    GradeBook gradeBook2("Cs102 Data Structures in C++");

    // display initial value of courseName for each GradeBook
    std::cout << "gradeBook1 created for course: "
              << gradeBook1.getCourseName();
    std::cout << "\ngradeBook2 created for course: "
              << gradeBook2.getCourseName() << std::endl;
    return 0;
}
