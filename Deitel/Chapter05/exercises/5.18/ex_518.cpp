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

int main(int argc, const char *argv[]) {
    std::cout << "Binary\tOctal\tHexadecimal\n";

    for (int i = 1; i <= 256; i++) {
        std::cout << std::dec << i << "\t" << std::oct << i << "\t" << std::hex
                  << i << std::endl;
    }
    return 0;
}
