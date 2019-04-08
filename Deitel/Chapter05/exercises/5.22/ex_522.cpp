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

/**
 * This is the main method.
 * @param argc.
 * @param argv[].
 * @return int.
 */
int main(int argc, char* argv[]) {
    int x = 4;
    int y = 8;
    int a = 10;
    int b = 5;
    int g = 2;
    int i = 4;
    int j = 9;

    // !(x < 5) && !(y >= 7)
    if ((!(x < 5) && !(y >= 7)) == !((x < 5) || (y >= 7))) {
        std::cout << "!(x < 5) && !(y >= 7) is comparable to !((x < 5) || (y >= 7))" << std::endl;
    }

    // !(a == b) || !(g != 5)
    if ((!(a == b) || !(g != 5)) == (!((a == g) && (g != 5)))) {
        std::cout << "!(a == b) || !(g != 5) is comparable to !((a == b) && (g != 5))" << std::endl;
    }

    // !((x <= 8) && (y > 4))
    if ((!((x <= 8) && (y > 4))) == (!(x <= 8) || !(y > 4))) {
        std::cout << "!((x <= 8) && (y > 4)) is comparable to !(x <= 8) || !(y > 4)" << std::endl;
    }

    // !((i > 4) || (j <= 6))
    if (!((i > 4) || (j <= 6)) == (!(i > 4) && !(j <= 6))) {
        std::cout << "!((i > 4) || (j <= 6)) is comparable to !(i > 4) && !(j <= 6)" << std::endl;
    }

    return 0;
}  // end method main
