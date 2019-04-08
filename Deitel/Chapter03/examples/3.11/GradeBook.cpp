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
#include "GradeBook.hpp"

#include <iostream>
#include <string>

// Constructor
GradeBook::GradeBook(const std::string &name) { setCourseName(name); }
// SETTERS
void GradeBook::setCourseName(const std::string &name) { courseName = name; }
// GETTERS
std::string GradeBook::getCourseName() { return courseName; }
// display a welcome message to the GradeBook user
void GradeBook::displayMessage() {
    std::cout << "Welcome to the grade book for\n"
              << getCourseName() << "!" << std::endl;
}
