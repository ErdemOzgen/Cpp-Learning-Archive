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

#include <iomanip>
#include <iostream>

GradeBook::GradeBook(std::string name, const int gradesArray[]) {
    setCourseName(name);

    // copy grades from gradesArray to grades data member
    for (int grade = 0; grade < students; ++grade) {
        grades[grade] = gradesArray[grade];
    }
}
// SETTERS
void GradeBook::setCourseName(std::string name) { courseName = name; }
// GETTERS
std::string GradeBook::getCourseName() { return courseName; }
// find minimum grade
int GradeBook::getMinimum() {
    int lowGrade = 100;

    for (int grade = 0; grade < students; ++grade) {
        if (grades[grade] < lowGrade) { lowGrade = grades[grade]; }
    }

    return lowGrade;
}
// find maximum grade
int GradeBook::getMaximum() {
    int highGrade = 0;

    for (int grade = 0; grade < students; ++grade) {
        if (grades[grade] > highGrade) { highGrade = grades[grade]; }
    }

    return highGrade;
}
// determine average grade for test
double GradeBook::getAverage() {
    int total = 0;

    for (int grade = 0; grade < students; ++grade) {
        total += grades[grade];
    }

    return static_cast<double>(total) / students;
}
// display a welcome message to the GradeBook user
void GradeBook::displayMessage() {
    std::cout << "Welcome to the grade book for\n"
              << getCourseName() << "!" << std::endl;
}
// perform various operations on the data
void GradeBook::processGrades() {
    outputGrades();

    // display average of all grades and minimum and maximum grades
    std::cout << "\nClass average is " << std::setprecision(2) << std::fixed
              << getAverage() << "\nLowest grade is " << getMinimum()
              << "\nHighest grade is " << getMaximum() << std::endl;

    outputBarChart();
}
// output bar chart displaying grade distribution
void GradeBook::outputBarChart() {
    std::cout << "\nGrade distribution:" << std::endl;

    // stores frequency of grades in each range of 10 grades
    const int frequencySize = 11;

    int frequency[frequencySize] = {};

    // for each grade increment the appropriate frequency
    for (int grade = 0; grade < students; ++grade) {
        ++frequency[grades[grade] / students];
    }

    // for each grade frequency, print bar in chart
    for (int count = 0; count < frequencySize; ++count) {
        // output bar labels
        if (count == 0) {
            std::cout << "  0-9: ";
        } else if (count == 10) {
            std::cout << "  100: ";
        } else {
            std::cout << count * 10 << "-" << (count * 10) + 9 << ": ";
        }

        // print bar of asterisks
        for (int stars = 0; stars < frequency[count]; ++stars) {
            std::cout << '*';
        }

        std::cout << std::endl;
    }
}
// output the contents of the grades array
void GradeBook::outputGrades() {
    std::cout << "|nThe grades are:\n\n";

    for (int student = 0; student < students; ++student) {
        std::cout << "Student " << std::setw(2) << student + 1 << ": "
                  << std::setw(3) << grades[student] << std::endl;
    }
}
