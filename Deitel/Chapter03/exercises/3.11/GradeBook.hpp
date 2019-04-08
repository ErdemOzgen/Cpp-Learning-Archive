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
#pragma once

#include <string>

class GradeBook {
 private:
    std::string courseName;
    std::string instructorName;

 public:
    GradeBook(const std::string &, const std::string &);

    // SETTERS
    void setCourseName(const std::string &);
    void setInstructorName(const std::string &);

    // GETTERS
    std::string getCourseName();
    std::string getInstructorName();

    void displayMessage();
};
