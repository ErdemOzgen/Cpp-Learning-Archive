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
    int maximumGrade;

 public:
    GradeBook(std::string);

    // SETTERS
    void setCourseName(std::string);

    // GETTERS
    std::string getCourseName();

    void displayMessage();
    void inputGrades();
    void displayGradeReport();
    int maximum(int, int, int);
};
