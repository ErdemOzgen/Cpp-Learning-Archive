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

int main(int argc, const char *argv[]) {
    int gradesArray[GradeBook::students] = {87, 68, 94, 100, 83,
                                            78, 85, 91, 76,  87};

    GradeBook myGradeBook("CS101 Introduction to C++ Programming", gradesArray);

    myGradeBook.displayMessage();
    myGradeBook.processGrades();

    return 0;
}
