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
#include <iomanip>
#include <iostream>

#include "GradeBook.hpp"

GradeBook::GradeBook(std::string name, const int gradesArray[][tests]) {
    setCourseName(name);

    // copy grades from gradeArray to grades
    for (int student = 0; student < students; ++student) {
        for (int test = 0; test < tests; ++test) {
            grades[student][test] = gradesArray[student][test];
        }
    }
}
// SETTERS
void GradeBook::setCourseName(std::string name) { courseName = name; }
// GETTERS
std::string GradeBook::getCourseName() { return courseName; }
int GradeBook::getMinimum() {
    int lowGrade = 100;

    for (int student = 0; student < students; ++student) {
        for (int test = 0; test < tests; ++test) {
            if (grades[student][test] < lowGrade) {
                lowGrade = grades[student][test];
            }
        }
    }

    return lowGrade;
}
int GradeBook::getMaximum() {
    int highGrade = 0;

    for (int student = 0; student < students; ++student) {
        for (int test = 0; test < tests; ++test) {
            if (grades[student][test] > highGrade) {
                highGrade = grades[student][test];
            }
        }
    }

    return highGrade;
}
double GradeBook::getAverage(const int setOfGrades[], const int grades) {
    int total = 0;

    for (int grade = 0; grade < grades; ++grade) {
        total += setOfGrades[grade];
    }

    return static_cast<double>(total) / grades;
}
void GradeBook::displayMessage() {
    std::cout << "Welcome to the grade book for\n"
              << getCourseName() << "!" << std::endl;
}
void GradeBook::processGrades() {
    outputGrades();

    std::cout << "\nLowest grade in the grade book is " << getMinimum()
              << "\nHighest grade in the grade book is " << getMaximum()
              << std::endl;

    outputBarChart();
}
void GradeBook::outputBarChart() {
    std::cout << "\nOverall grade distribution:" << std::endl;

    const int frequencySize = 11;
    int frequency[frequencySize] = {};

    for (int student = 0; student < students; ++student) {
        for (int test = 0; test < tests; ++test) {
            ++frequency[grades[student][test] / 10];
        }
    }

    for (int count = 0; count < frequencySize; ++count) {
        if (count == 0) {
            std::cout << "  0-9: ";
        } else if (count == 10) {
            std::cout << "  100: ";
        } else {
            std::cout << count * 10 << "-" << (count * 10) + 9 << ": ";
        }

        for (int stars = 0; stars < frequency[count]; ++stars) {
            std::cout << '*';
        }

        std::cout << std::endl;
    }
}
void GradeBook::outputGrades() {
    std::cout << "\nThe grades are:\n\n";
    std::cout << "            ";

    for (int test = 0; test < tests; ++test) {
        std::cout << "Test " << test + 1 << " ";
    }

    std::cout << "Average" << std::endl;

    for (int student = 0; student < students; ++student) {
        std::cout << "Student" << std::setw(2) << student + 1;

        for (int test = 0; test < tests; ++test) {
            std::cout << std::setw(8) << grades[student][test];
        }

        double average = getAverage(grades[student], tests);

        std::cout << std::setw(9) << std::setprecision(2) << std::fixed
                  << average << std::endl;
    }
}
