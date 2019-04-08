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
#include <random>

static const int LIMIT = 10;

void bucketSort(int[], int);
int getPlaces(int[], int);

int main(int argc, const char *argv[]) {
    int n[LIMIT];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 1000);

    for (int i = 0; i < LIMIT; ++i) {
        n[i] = dis(gen);
    }

    std::cout << "\nUnsorted" << std::endl;
    for (int i = 0; i < LIMIT; ++i) {
        std::cout << n[i] << std::endl;
    }

    bucketSort(n, LIMIT);

    std::cout << "\nSorted:" << std::endl;

    for (int i = 0; i < LIMIT; ++i) {
        std::cout << n[i] << std::endl;
    }

    return 0;
}
// bucket sort
void bucketSort(int n[], int LIMIT) {
    int places = getPlaces(n, LIMIT);
    int place = 10;

    // create bucket
    int bucket[10][LIMIT];

    while (places != 0) {
        // reset counters and buckets every turn
        int counters[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        for (int row = 0; row < 10; ++row) {
            for (int col = 0; col < LIMIT; ++col) {
                bucket[col][row] = 0;
            }
        }

        // 1 - place each array value into bucket
        for (int i = 0, row = 0; i < LIMIT; ++i) {
            row = n[i] % place;

            // adjust rows to be within range
            if (row > 9) { row /= (place / 10); }

            // account for single digits numbers
            // don't know why they don't automatically go into bucket 0
            if (n[i] < 9) { row = 0; }

            bucket[row][counters[row]] = n[i];

            ++counters[row];
        }

        // print bucket at each stage
        /*for(int row=0; row<10; ++row){
            std::cout << row << ": ";

            for(int col=0; col<LIMIT; ++col){

                std::cout << bucket[row][col] << " ";
            }
            std::cout << std::endl;
        }*/

        // 2 - Copy values back into array
        for (int row = 0, i = 0; row < 10; ++row) {
            for (int col = 0; col < LIMIT; ++col) {
                if (bucket[row][col] != 0) {
                    n[i] = bucket[row][col];
                    ++i;
                }
            }
        }
        // 3 - Repeat for subsequent digit positions until LIMIT reached
        place *= 10;
        --places;
    }
}
// returns number of places for maximum value
int getPlaces(int n[], int LIMIT) {
    int max = n[0];

    for (int i = 1; i < LIMIT; ++i) {
        if (n[i] > max) { max = n[i]; }
    }

    int count = 0;

    while (max != 0) {
        max /= 10;
        ++count;
    }

    return count;
}
