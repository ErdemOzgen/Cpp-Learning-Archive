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

GradeBook::GradeBook(const std::string &name) { setCourseName(name); }
// SETTERS
// ensure coursename does not exceed 25 chars
void GradeBook::setCourseName(const std::string &name) {
    if (name.length() <= 25) { courseName = name; }

    if (name.length() > 25) {
        courseName = name.substr(0, 25);

        std::cout << "Name \"" << name << "\" exceeds maximum length (25).\n";
        std::cout << "Limiting courseName to first 25 characters.\n"
                  << std::endl;
    }
}
// GETTERS
std::string GradeBook::getCourseName() { return courseName; }
// display a welcome message to the GradeBook user
void GradeBook::displayMessage() {
    std::cout << "Welcome to the grade book for\n"
              << getCourseName() << "!" << std::endl;
}
