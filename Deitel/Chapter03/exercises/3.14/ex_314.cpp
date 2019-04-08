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

#include "Employee.hpp"

int main(int argc, const char *argv[]) {
    Employee emp1("Bob", "Bobson", 1200);
    Employee emp2("Sue", "Sueson", 2000);

    emp1.showEmployee();
    emp2.showEmployee();

    emp1.giveRaise(10);
    emp2.giveRaise(10);

    emp1.showEmployee();
    emp2.showEmployee();
    return 0;
}
