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
#include <string>

#include "GradeBook.hpp"//include your header file

// Constructor
GradeBook::GradeBook(const std::string &name, const std::string &instructor) {
    setCourseName(name);
    setInstructorName(instructor);
}
// SETTERS
void GradeBook::setCourseName(const std::string &name) { courseName = name; }
void GradeBook::setInstructorName(const std::string &instructor) { instructorName = instructor; }

// GETTERS
std::string GradeBook::getCourseName() { return courseName; }
std::string GradeBook::getInstructorName() { return instructorName; }

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() {
    std::cout << "Welcome to the grade book for: " << getCourseName() << "!\n"
              << "This course is presented by: " << getInstructorName()
              << std::endl;
}
