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

 public:
    explicit GradeBook(const std::string &);

    // SETTERS
    void setCourseName(const std::string &);

    // GETTERS
    std::string getCourseName();

    void displayMessage();
};
