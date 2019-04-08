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

bool isPalindrome(int);

int main(int argc, const char *argv[]) {
    int num = 0;

    std::cout << "A program to determine if a 5 digit integer is a palindrome\n"
              << std::endl;

    std::cout << "Enter a 5 digit integer: ";
    std::cin >> num;

    printf("%d is%sa palindrome\n", num, (isPalindrome(num)) ? " " : " not ");

    return 0;
}
// check if number is a palindrome
bool isPalindrome(int num) {
    if ((num / 10000) == (num % 10)) {
        num /= 10000;
        num /= 10;

        if ((num / 10) == (num % 10)) {
            return true;
        }
    }

    return false;
}
