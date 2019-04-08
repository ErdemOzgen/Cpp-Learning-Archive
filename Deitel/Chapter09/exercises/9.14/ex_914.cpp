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
#include "HugeInteger.hpp"

int main(int argc, const char *argv[]) {
    HugeInteger h1("123456");
    HugeInteger h2("123456");
    HugeInteger h3p = (h1 + h2);
    HugeInteger h3m = (h1 - h2);

    std::cout << h1 << " + " << h2 << " = " << h3p << "\n";
    std::cout << h1 << " - " << h2 << " = " << h3m << "\n";
    std::cout << "h1 < h2: " << ((h1 < h2) ? "True" : "False") << "\n";
    std::cout << "h1 > h2: " << ((h1 > h2) ? "True" : "False") << "\n";
    std::cout << "h1 == h2: " << ((h1 == h2) ? "True" : "False") << "\n";
    std::cout << "h1 != h2: " << ((h1 != h2) ? "True" : "False") << "\n";
    std::cout << "h1 >= h2: " << ((h1 >= h2) ? "True" : "False") << "\n";
    std::cout << "h1 <= h2: " << ((h1 <= h2) ? "True" : "False") << "\n\n";

    HugeInteger h4("923456");
    HugeInteger h5("923456");
    HugeInteger h6p = (h4 + h5);
    HugeInteger h6m = (h4 - h5);

    std::cout << h4 << " + " << h5 << " = " << h6p << "\n";
    std::cout << h4 << " - " << h5 << " = " << h6m << "\n";
    std::cout << "h4 < h5: " << ((h4 < h5) ? "True" : "False") << "\n";
    std::cout << "h4 > h5: " << ((h4 > h5) ? "True" : "False") << "\n";
    std::cout << "h4 == h5: " << ((h4 == h5) ? "True" : "False") << "\n";
    std::cout << "h4 != h5: " << ((h4 != h5) ? "True" : "False") << "\n";
    std::cout << "h4 >= h5: " << ((h4 >= h5) ? "True" : "False") << "\n";
    std::cout << "h4 <= h5: " << ((h4 <= h5) ? "True" : "False") << "\n\n";

    HugeInteger h7("1");
    HugeInteger h8("9999999999999999999999999999999999999998");
    HugeInteger h9p = (h7 + h8);
    HugeInteger h9m = (h8 - h7);

    std::cout << h7 << " + " << h8 << " = " << h9p << "\n";
    std::cout << h8 << " - " << h7 << " = " << h9m << "\n";
    std::cout << "h7 < h8: " << ((h7 < h8) ? "True" : "False") << "\n";
    std::cout << "h7 > h8: " << ((h7 > h8) ? "True" : "False") << "\n";
    std::cout << "h7 == h8: " << ((h7 == h8) ? "True" : "False") << "\n";
    std::cout << "h7 != h8: " << ((h7 != h8) ? "True" : "False") << "\n";
    std::cout << "h7 >= h8: " << ((h7 >= h8) ? "True" : "False") << "\n";
    std::cout << "h7 <= h8: " << ((h7 <= h8) ? "True" : "False") << "\n\n";

    HugeInteger h10;

    std::cout << "h10.isZero(): " << ((h10.isZero()) ? "True" : "False")
              << "\n";

    HugeInteger h11("12345");
    HugeInteger h12("11726");
    HugeInteger h13m = (h11 - h12);

    std::cout << h11 << " - " << h12 << " = " << h13m << "\n";

    HugeInteger h14;
    HugeInteger h15;

    std::cout << "Enter HugeInteger 1 :";
    std::cin >> h14;

    std::cout << "\nEnter HugeInteger 2: ";
    std::cin >> h15;

    HugeInteger h16 = (h14 + h15);

    std::cout << "h14 + h16 = " << h16 << "\n";

    HugeInteger h17 = (h14 - h15);

    std::cout << "h14 - h15 = " << h17 << "\n";
    std::cout << "h17.size() = " << h17.size() << std::endl;

    return 0;
}
