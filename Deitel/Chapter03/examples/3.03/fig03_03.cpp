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

// GradeBook class definition
class GradeBook {
 public:
    void displayMessage(const std::string &courseName) {//take function input with reference https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbclx01/cplr233.htm
        std::cout << "Welcome to the grade book for\n"
                  << courseName << "!" << std::endl;
    }
};

// function main begins program execution
int main(int argc, const char *argv[]) {
    std::string nameOfCourse;
    GradeBook myGradeBook;

    // prompt for and input course name
    std::cout << "Please enter the course name: ";
    std::getline(std::cin, nameOfCourse);  // read a course name with blanks http://www.cplusplus.com/reference/string/string/getline/
    std::cout << std::endl;

    // call myGradeBook's displayMessage function
    // and pass nameOfCourse as an argument
    myGradeBook.displayMessage(nameOfCourse);
    return 0;
}
