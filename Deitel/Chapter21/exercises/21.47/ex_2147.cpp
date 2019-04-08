/*
 * =============================================================================
 *
 *       Filename:  ex_2147.cpp
 *
 *    Description:  Exercise 21.47 - Writing the Word Equivalent of a Check
 *                  Amount
 *
 *        Version:  1.0
 *        Created:  07/06/18 16:52:20
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =============================================================================
 */
#include <stdio.h>
#include <string.h>

const char* single[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
const char* two[] = {"TEN", "ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN", "FIFTEEN",
                     "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN"};
const char* tens[] = {"", "", "TWENTY", "THIRTY", "FOURTY", "FIFTY", "SIXTY",
                      "SEVENTY", "EIGHTY", "NINETY"};
const char* tens_pow[] = {"", "HUNDRED", "THOUSAND", "MILLION", "BILLION", "TRILLION"};

/**
 * Prints the word equivalent of a single digit
 * @param const char*
 */
void printSingle(const char* n) {
    printf("%s ", single[*n - '0']);
}  // end method printSingle

/**
 * Prints the word equivalent of a double digit 10-99
 * @param const char*
 */
void printDouble(const char* n) {
        if (*n == '0') {
            if (*(n + 1) == '0') {
                printf("ONLY");
            } else {
                printSingle(n);
                printSingle(++n);
            }
        } else if (*n == '1') {
            printf("%s ", two[*(++n) - '0']);
        } else {
            printf("%s ", tens[*(n++) - '0']);
            if (*n != '0') { printSingle(n); }
        }
}  // end method printDouble

/**
 * Prints the word equivalent of triple digit numbers 100-999
 * Triple digits are always x HUNDRED ...
 * @param const char*
 */
void printTriple(const char* n) {
    if (*n != '0') {
        printSingle(n);
        printf("%s ", tens_pow[1]);
    }

    if (*(++n) != '0') {
        printDouble(n);
    } else if (*(n + 1) != '0') {
        printSingle(++n);
    }
}  // end method printTriple

/**
 * Gets the number of parts (counts ,) of the given cheque amount
 * @param const char*
 * @return unsigned int
 */
unsigned int getParts(const char* n) {
    unsigned int i = 1;

    while (static_cast<bool>(*n++)) {
        if (*n == ',') { ++i; }
    }

    return i;
}  // end method getParts

/**
 * Prints the given cheque part
 * @param const char*
 * @param size_t
 */
void printPart(const char* n, size_t len) {
    char part[len + 1];
    strncpy(part, (n - len), len);

    if (len == 3) {
        printTriple(part);
    } else if (len == 2) {
        printDouble(part);
    } else {
        printSingle(part);
    }
}  // end method printPart

/**
 * Prints the word equivalent of the given integer.
 * Assumes paramaters are correct.
 * @param const char*
 */
void printNumber(const char* n) {
    size_t LEN = strlen(n);

    // single digit
    if (LEN == 1) {
        printSingle(n);
    // double digit
    } else if (LEN == 2) {
        printDouble(n);
    // hundreds, thousands, millions, billions...
    } else {
        size_t PARTS = getParts(n);

        size_t len = 0;
        const char* temp = n;

        while (static_cast<bool>(*temp)) {
            if (PARTS > 1) {
                // triples
                if (*temp == ',') {

                    printPart(temp, len);

                    printf("%s ", tens_pow[PARTS]);

                    // reduce total parts on completion
                    --PARTS;
                    // point past delimiter
                    ++temp;
                    // reset length for next part
                    len = 0;
                }
            // hundreds and tens
            } else if (*temp == '.') {

                printPart(temp, len);

                if (*(++temp) != '0' || *(temp + 1) != '0') {
                    printf("AND ");
                }

                // remainder
                printDouble(temp);
            }
            ++len;
            ++temp;
        }
    }

    printf("\n");
}  // end method printNumber

/**
 * This is the main method.
 * @param argc.
 * @param argv[].
 * @return int.
 */
int main(int argc, char* argv[]) {
    char amount[255];

    while (true) {
        printf("Enter a cheque amount to convert (Ctrl-C to quit): ");
        fgets(amount, 255, stdin);
        //scanf("%s", &amount);

        printNumber(amount);
    }

    return 0;
}  // end method main
