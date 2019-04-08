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

int main(int argc, const char* argv[]) {
    const char* const word = "again";

    // display value of char *, then display value of char *
    // static_cast to void *
    std::cout << "Value of word is: " << word << std::endl
              << "Value of static_cast<void*>(word) is: "
              << static_cast<void*>(word) << std::endl;

    return 0;
}
