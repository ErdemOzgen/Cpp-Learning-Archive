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
#include <stdexcept>
#include <vector>

#include "IntegerSet.hpp"

IntegerSet::IntegerSet() { reset(); }
IntegerSet::IntegerSet(int arr[], int size) {
    reset();

    for (int i = 0; i < size; ++i) {
        if (!elementExists(arr[i])) {
            insertElement(arr[i]);
        }
    }
}
// creates a set-theoretic union of two existing IntegerSets
// element is true if either existing sets is true, false otherwise
IntegerSet IntegerSet::unionOfSets(IntegerSet& is) const {
    std::vector<int> tmp;
    int count = 0;

    for (int i = 0; i <= _limit; ++i) {
        if (is.elementExists(i) || elementExists(i)) {
            tmp.push_back(i);
            ++count;
        }
    }

    return IntegerSet(&tmp[0], count);
}
// creates a set-theoretic intersection of two existing IntegerSets
// element is false if either existing sets is false, true otherwise
IntegerSet IntegerSet::intersectionOfSets(IntegerSet& is) const {
    std::vector<int> tmp;
    int count = 0;

    for (int i = 0; i < _limit; ++i) {
        if (!is.elementExists(i) || !elementExists(i)) {
            continue;
        } else {
            tmp.push_back(i);
            ++count;
        }
    }

    return IntegerSet(&tmp[0], count);
}
// COMPARISON OPERATORS
bool IntegerSet::operator==(const IntegerSet& is) const {
    for (int i = 0; i < _limit; ++i) {
        if (is.elementExists(i) != elementExists(i)) {
            return false;
        }
    }
    return true;
}
bool IntegerSet::operator!=(const IntegerSet& is) const {
    for (int i = 0; i < _limit; ++i) {
        if (is.elementExists(i) != elementExists(i)) {
            return true;
        }
    }
    return false;
}
// print IntegerSet
std::ostream& IntegerSet::printSet(std::ostream& out) const {
    if (isEmpty()) {
        out << "---";
    } else {
        for (int i = 0; i <= _limit; ++i) {
            if (elementExists(i)) {
                out << i << " ";
            }
        }
    }
    return out;
}
// UTILITY FUNCTIONS
// resets _integerSet to default values
void IntegerSet::reset() {
    for (int i = 0; i < _limit; ++i) {
        _integerSet.push_back(false);
    }
}
// inserts an element
void IntegerSet::insertElement(int el) {
    if (!elementExists(el)) {
        _integerSet[el] = true;
    } else {
        throw std::invalid_argument("element already exists in set");
    }
}
// deletes an element
void IntegerSet::deleteElement(int el) {
    if (elementExists(el)) {
        _integerSet[el] = false;
    } else {
        throw std::invalid_argument("element does not exist in set");
    }
}
// checks for existance of element in _integerSet
bool IntegerSet::elementExists(int el) const { return _integerSet[el]; }
// checks whether _integerSet is empty
bool IntegerSet::isEmpty() const {
    for (int i = 0; i < _limit; ++i) {
        if (elementExists(i)) {
            return false;
        }
    }
    return true;
}
