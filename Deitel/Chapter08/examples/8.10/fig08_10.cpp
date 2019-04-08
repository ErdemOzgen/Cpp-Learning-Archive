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
void f(const int *);

int main(int argc, const char *argv[]) {
    int y;

    f(&y);

    return 0;
}
// xPtr cannot modify the value of constant variable to which it points
void f(const int *xPtr) {
    *xPtr = 100;  // error: cannot modify a const object
}
