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
#include <string>

int main(int argc, const char *argv[]) {
    std::string s1("happy");
    std::string s2(" birthday");
    std::string s3;

    // test overloaded equality and relational operators
    std::cout << "s1 is \"" << s1 << "\"; s2 is \"" << s2 << "\"; s3 is \""
              << s3 << '\"' << "\n\nThe results of comparing s2 and s1:"
              << "\ns2 == s1 yields " << (s2 == s1 ? "true" : "false")
              << "\ns2 != s1 yields " << (s2 != s1 ? "true" : "false")
              << "\ns2 >  s1 yields " << (s2 > s1 ? "true" : "false")
              << "\ns2 <  s1 yields " << (s2 < s1 ? "true" : "false")
              << "\ns2 >= s1 yields " << (s2 >= s1 ? "true" : "false")
              << "\ns2 <= s1 yields " << (s2 <= s1 ? "true" : "false");

    // test string member-function empty
    std::cout << "\n\nTesting s3.empty():" << std::endl;

    if (s3.empty()) {
        std::cout << "s3 is empty; assigning s1 to s3;" << std::endl;
        s3 = s1;
        std::cout << "s3 is \"" << s3 << "\"";
    }

    // test overloaded string contatenation operator
    std::cout << "\n\ns1 += s2 yields s1 = ";
    s1 += s2;
    std::cout << s1;

    // test overloaded string concatenation operator with a char* string
    std::cout << "\n\ns1 += \" to you\" yields" << std::endl;
    s1 += " to you";
    std::cout << "s1 = " << s1 << "\n\n";

    // test string member function on substr
    std::cout << "The substring of s1 starting at location 0 for\n"
              << "14 characters, s1.substr(0, 14). is:\n"
              << s1.substr(0, 14) << std::endl;

    // test substr "to-end-of-string" option
    std::cout << "The substring of s1 starting at\n"
              << "location 15, s1.substr(15), is:\n"
              << s1.substr(15) << std::endl;

    // test copy constructor
    std::string s4(s1);
    std::cout << "\ns4 = " << s4 << std::endl;

    // test overloaded assignment (=) operator with self-assignent
    std::cout << "assigning s4 to s4" << std::endl;
    s4 = s4;
    std::cout << "s4 = " << s4 << std::endl;

    // test using overloaded subscript operator to create lvalue
    s1[0] = 'H';
    s1[6] = 'B';
    std::cout << "\ns1 after s1[0] = 'H' and s1[6] = 'B' is: " << s1 << "\n\n";

    // test subscript out of range iwth string member function "at"
    try {
        std::cout << "Attempt to assign 'd' to s1.at(30) yields:" << std::endl;
        s1.at(30) = 'd';  // ERROR: subscript out of range
    } catch (std::out_of_range &ex) {
        std::cout << "An exception occured: " << ex.what() << std::endl;
    }

    return 0;
}
