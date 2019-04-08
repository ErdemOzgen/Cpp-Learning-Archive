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
#include <iostrem>
int main(int argc, const char *argv[]) {
    const int SIZE = 80;
    char buffer[SIZE];

    // input characters in buffer via cin function getline
    std::cout << "Enter a sentence:" << std::endl;
    std::cin.getline(buffer, SIZE);

    // display buffer contents
    std::cout << "\nThe sentence entered is:" << std::endl
              << buffer << std::endl;

    return 0;
}
