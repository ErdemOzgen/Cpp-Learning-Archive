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

#include <string>

HugeInteger::HugeInteger(const std::string& s) { input(s); }
HugeInteger::HugeInteger(int hi[]) {
    for (unsigned int i = 0; i < MAX_INTEGER; ++i) {
        _hugeInteger[i] = hi[i];

        if (hi[i] == TERMINATOR) {
            break;
        }
        ++_hiSize;
    }
}
// === ARITHMETIC OPERATIONS === //
// add two HugeIntegers - result as new HugeInteger
HugeInteger HugeInteger::operator+(const HugeInteger& hi) {
    // result + carry over values
    int newHuge[MAX_INTEGER] = {0};

    int* ptrNewHuge = &newHuge[0];

    int sum = 0;
    int addend1 = _hiSize - 1;
    int addend2 = hi._hiSize - 1;
    unsigned int count = 0;

    // iterate both and add each value
    while ((addend1 >= 0 || addend2 >= 0) && count < MAX_INTEGER) {
        if (addend1 < 0) {
            sum = *ptrNewHuge + hi._hugeInteger[addend2];
        } else if (addend2 < 0) {
            sum = *ptrNewHuge + _hugeInteger[addend1];
        } else {
            sum =
                *ptrNewHuge + _hugeInteger[addend1] + hi._hugeInteger[addend2];
        }
        if (sum >= 10) {
            *(ptrNewHuge++) = sum % 10;
            *ptrNewHuge = sum / 10;
        } else {
            *(ptrNewHuge++) = sum;
        }
        --addend1;
        --addend2;
        ++count;
    }
    // decrease pointer if limit is reached
    if (count == MAX_INTEGER - 1) {
        --ptrNewHuge;
        // carry over value is present - increase counters
        // result array is reversed so no trailing zeros
    } else if (*ptrNewHuge != 0) {
        ++ptrNewHuge;
        count++;
    }

    reverse(newHuge, count);

    *ptrNewHuge = TERMINATOR;

    ptrNewHuge = nullptr;

    return HugeInteger(newHuge);
}
// subtract hi from _hugeInteger result as new HugeInteger
// uses quick subtraction
HugeInteger HugeInteger::operator-(const HugeInteger& hi) {
    // result + carry over values
    int newHuge[MAX_INTEGER] = {0};

    int* ptrNewHuge = &newHuge[0];

    int minuend = _hiSize - 1;
    int subtrahend = hi._hiSize - 1;
    int difference = 0;
    unsigned int count = 0;

    while ((minuend >= 0 || subtrahend >= 0) && (count < MAX_INTEGER)) {
        if (minuend < 0) {
            difference = 0 - (*ptrNewHuge + hi._hugeInteger[subtrahend]);
        } else if (subtrahend < 0) {
            difference = _hugeInteger[minuend] - *ptrNewHuge;
        } else {
            difference = _hugeInteger[minuend] -
                         (hi._hugeInteger[subtrahend] + *ptrNewHuge);
        }
        if (difference < 0) {
            *ptrNewHuge = 10 - ((hi._hugeInteger[subtrahend] + *ptrNewHuge) -
                                _hugeInteger[minuend]);

            *(++ptrNewHuge) = 1;
        } else {
            *(ptrNewHuge++) = difference;
        }
        --minuend;
        --subtrahend;
        ++count;
    }

    ptrNewHuge = nullptr;

    count = MAX_INTEGER - 1;

    // remove trailing zeros
    while (newHuge[count] == 0 && count > 0) {
        --count;
    }

    reverse(newHuge, count + 1);

    newHuge[count + 1] = TERMINATOR;

    return HugeInteger(newHuge);
}
// ===== PREDICATE OPERATIONS ===== //
bool HugeInteger::isZero() { return (_hiSize == 0); }
bool HugeInteger::operator==(const HugeInteger& hi) const {
    for (unsigned int i = 0; i < MAX_INTEGER; ++i) {
        if (_hugeInteger[i] != hi._hugeInteger[i]) {
            return false;
        }
    }
    return true;
}
bool HugeInteger::operator!=(const HugeInteger& hi) const {
    return !(*this == hi);
}
bool HugeInteger::operator>(const HugeInteger& hi) const {
    if (_hiSize > hi._hiSize) {
        return true;
    }
    // counts equal compare digits
    if (_hiSize == hi._hiSize) {
        for (int i = 0; i < _hiSize; ++i) {
            if (_hugeInteger[i] > hi._hugeInteger[i]) {
                return true;
            }
        }
    }
    return false;
}
bool HugeInteger::operator>=(const HugeInteger& hi) const {
    return (*this == hi || *this > hi);
}
bool HugeInteger::operator<(const HugeInteger& hi) const {
    if (_hiSize < hi._hiSize) {
        return true;
    }
    // counts equal compare digits
    if (_hiSize == hi._hiSize) {
        for (int i = 0; i < _hiSize; ++i) {
            if (_hugeInteger[i] < hi._hugeInteger[i]) {
                return true;
            }
        }
    }
    return false;
}
bool HugeInteger::operator<=(const HugeInteger& hi) const {
    return (*this == hi || *this < hi);
}
// ===== I/O OPERATIONS ===== //
void HugeInteger::input(const std::string& digit) {
    int* ptrHugeInteger = &_hugeInteger[0];

    for (unsigned int i = 0; i < digit.size(); ++i) {
        if (i < MAX_INTEGER) {
            *(ptrHugeInteger++) = static_cast<int>(digit[i]) - 48;
        } else {
            break;
        }
        ++_hiSize;
    }

    *ptrHugeInteger = TERMINATOR;

    ptrHugeInteger = nullptr;
}
std::ostream& HugeInteger::output(std::ostream& out) {
    for (int i = 0; i < _hiSize; ++i) {
        if (_hugeInteger[i] == TERMINATOR) {
            break;
        }
        out << _hugeInteger[i];
    }
    return out;
}
// ===== UTILITY FUNCTIONS ===== //
// reverses a given int array
void HugeInteger::reverse(int* arr, int count) {
    // reverse the final value
    for (int i = 0; i < count / 2; ++i) {
        int temp = arr[count - i - 1];
        arr[count - i - 1] = arr[i];
        arr[i] = temp;
    }
}
// print every element in array
void HugeInteger::quickPrint(int* a) {
    printf("\n");

    for (unsigned int i = 0; i < MAX_INTEGER; ++i) {
        std::cout << a[i];
    }
    std::cout << std::endl;
}
