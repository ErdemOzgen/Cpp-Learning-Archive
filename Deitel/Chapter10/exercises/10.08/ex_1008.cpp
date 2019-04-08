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
#include "IntegerSet.hpp"

int main(int argc, const char *argv[]) {
    IntegerSet set1;
    IntegerSet set2;
    IntegerSet set3;

    for (int i = 0; i <= 100; i += 3) {
        set1.insertElement(i);
        set3.insertElement(i);
    }
    for (int i = 0; i <= 100; i += 2) {
        set2.insertElement(i);
    }

    std::cout << "set1: " << set1;
    std::cout << "\nset2: " << set2;
    std::cout << "\nset3: " << set3;

    std::cout << "\nset1 == set2 : " << ((set1 == set2) ? "true" : "false");
    std::cout << "\nset1 == set3 : " << ((set1 == set3) ? "true" : "false");
    std::cout << "\nset2 != set3 : " << ((set2 != set3) ? "true" : "false");

    set3.deleteElement(6);

    std::cout << " \nset3: " << set3;

    IntegerSet set4 = set1.unionOfSets(set2);

    std::cout << "\n\nunionOfSets (set1 + set2): " << set4;

    set4 = set1.intersectionOfSets(set2);

    std::cout << "\n\nintersectionOfSets (set1 + set2): " << set4;

    IntegerSet set5;

    std::cout << "\n\nset5: " << set5;
    std::cout << "\nset5.isEmpty() = " << ((set5.isEmpty()) ? "true" : "false")
              << std::endl;

    return 0;
}
