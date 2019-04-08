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
#include "Date.hpp"

int main(int argc, const char *argv[]) {
    Date date1(12, 7, 1983);
    Date date2(14, 23, 1255);

    date1.displayDate();
    date2.displayDate();

    return 0;
}
