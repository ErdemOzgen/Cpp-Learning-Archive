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
    int counter = 0;

    printf("N\t10*N\t100*N\t1000*N\n\n");

    while (counter < 5) {
        counter++;

        printf("%d\t%d\t%d\t%d\n", counter, counter * 10, counter * 100, counter * 1000);
    }
    return 0;
}
