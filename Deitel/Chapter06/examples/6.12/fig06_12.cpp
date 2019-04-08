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

void useLocal();
void useStaticLocal();
void useGlobal();

int x = 1;

int main(int argc, const char *argv[]) {
    std::cout << "global x in main is " << x << std::endl;

    int x = 5;

    std::cout << "local x in main's outer scope is " << x << std::endl;

    // start new scope
    {
        int x = 7;  // hides both x in outer scope and global x

        std::cout << "local x in main's inner scope is " << x << std::endl;
    }

    std::cout << "local x in main's outer scope is " << x << std::endl;

    useLocal();
    useStaticLocal();
    useGlobal();
    useLocal();
    useStaticLocal();
    useGlobal();

    std::cout << "\nlocal x in main is " << x << std::endl;
    return 0;
}
// useLocal reinitializes local variable x during each call
void useLocal() {
    int x = 25;

    std::cout << "\nlocal x is " << x << " on entering useLocal" << std::endl;
    ++x;
    std::cout << "local x is " << x << " on exiting useLocal" << std::endl;
}
// useStaticLocal initializes static local variable x only the first time the
// function is called; value of x is saved between calls to this function
void useStaticLocal() {
    static int x = 50;

    std::cout << "\nlocal static x is " << x << " on entering useStaticLocal"
              << std::endl;

    ++x;

    std::cout << "local static x is " << x << " on exiting useStaticLocal"
              << std::endl;
}
// useGlobal modifies global variable x during each call
void useGlobal() {
    std::cout << "\nglobal x is " << x << " on entering useGlobal" << std::endl;

    x *= 10;

    std::cout << "global x is " << x << " on exiting useGlobal" << std::endl;
}
