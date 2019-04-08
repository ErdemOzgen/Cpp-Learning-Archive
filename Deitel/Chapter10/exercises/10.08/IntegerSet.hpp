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
#pragma once

#include <iostream>
#include <vector>

class IntegerSet {
 public:
    IntegerSet();
    IntegerSet(int[], int);

    // COMMON SET OPERATIONS
    IntegerSet unionOfSets(IntegerSet&) const;
    IntegerSet intersectionOfSets(IntegerSet&) const;
    bool operator==(const IntegerSet&) const;
    bool operator!=(const IntegerSet&) const;

    // UTILITY FUNCTIONS
    void insertElement(int);
    void deleteElement(int);
    bool elementExists(int) const;
    bool isEmpty() const;

    friend std::ostream& operator<<(std::ostream& out, IntegerSet& is) {
        return is.printSet(out);
    }

    std::ostream& printSet(std::ostream&) const;

 private:
    static const int _limit = 101;

    std::vector<bool> _integerSet;

    void reset();
};
