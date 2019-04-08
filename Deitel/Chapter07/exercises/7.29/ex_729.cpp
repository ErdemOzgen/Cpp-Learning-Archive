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
#include <math.h>
#include <iostream>

void sieveOfEratosthenes(int[], int);

static const int limit = 1000;

int main(int argc, const char *argv[]) {
    int arrPrimes[limit + 1];

    for (int i = 0; i < limit; ++i) {
        arrPrimes[i] = 1;
    }

    sieveOfEratosthenes(arrPrimes, limit);

    for (int i = 2; i < limit; ++i) {
        if (arrPrimes[i] == 1) { std::cout << i << " "; }
    }

    std::cout << std::endl;

    return 0;
}
// sieve of erathosthene
void sieveOfEratosthenes(int arrPrimes[], int limit) {
    // outer loop only needs to loop to sqrt of limit
    for (int p = 2; p <= static_cast<int>(sqrt(limit)); ++p) {
        // if not changed then is prime
        if (arrPrimes[p] == 1) {
            // update all multiples of p starting at square of last found prime
            for (int i = p * p; i <= limit; i += p) {
                arrPrimes[i] = 0;
            }
        }
    }
}
