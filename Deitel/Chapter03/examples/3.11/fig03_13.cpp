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

int main(int argc, const char *argv[]) {
    GradeBook gradeBook1("CS101 Introduction to C++ Programming.");
    GradeBook gradeBook2("CS102 Data Structures in C++.");

    // display initial values of courseName for each GradeBook
    std::cout << "gradeBook1 created for course: "
              << gradeBook1.getCourseName();
    std::cout << "\ngradeBook2 created for course: "
              << gradeBook2.getCourseName() << std::endl;
    return 0;
}
