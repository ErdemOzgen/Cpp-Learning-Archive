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

int main(int argc, const char* argv[]) {
    int x, y;

    // ptr is a constant pointer to an integer that can be modified through ptr,
    // but ptr always points to the same memory location.
    int* const ptr = &x;

    *ptr = 7;  // allowed: *ptr is not const
    ptr = &y;  // error: ptr is const; cannot assign it to a new address
    return 0;
}
