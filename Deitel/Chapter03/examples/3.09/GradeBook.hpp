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
#pragma once//you can use #ifndef #define #endif but #pragma once is more simp

#include <iostream>
#include <string>

// GradeBook class definition
class GradeBook {
 private:
    std::string courseName;

 public:
    explicit GradeBook(const std::string &name) { setCourseName(name); }
    // SETTERS
    void setCourseName(const std::string &name) { courseName = name; }
    // GETTERS
    std::string getCourseName() { return courseName; }
    // display a welcome message to the GradeBook user
    void displayMessage() {
        std::cout << "Welcome to the grade book for\n"
                  << getCourseName() << "!" << std::endl;
    }
};
