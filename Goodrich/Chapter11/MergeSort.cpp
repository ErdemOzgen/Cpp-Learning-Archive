/*
 * =====================================================================================
 *
 *       Filename:  MergeSort.cpp
 *
 *    Description:  Implementing the Merge Sort
 *
 *        Version:  1.0
 *        Created:  January 25th, 2022
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author: Sebastian W. Tirado-Vélez   sebastianwtirado@gmail.com
 *   
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

// This function merges the subarrays established by mergeSort
void merge(int testArr[], int leftHalf, int middle, int rightHalf) {

    // declare space for temporary arrays based on the current segment being ordered
    int leftSize = middle - leftHalf + 1;
    int rightSize = rightHalf - middle;

    int leftArr[leftSize], rightArr[rightSize]; // this demonstrates how only O(n) space is used for this function

    // populate local subarrays
    for(int i = 0; i < leftSize; i++) {
        leftArr[i] = testArr[leftHalf + i];
    }
    for(int j = 0; j < rightSize; j++) {
        rightArr[j] = testArr[middle + 1 + j];
    }

    // perform merging of subarrays to return single ordered array for this iteration
    int i = 0;
    int j = 0;
    int k = leftHalf;

    // fill in testArr to return in sorted form
    while(i < leftSize && j < rightSize) {

        // find smallest element between both halves and place it in testArr
        if(leftArr[i] <= rightArr[j]) {
            testArr[k] = leftArr[i];
            i++;
        }else {
            testArr[k] = rightArr[j];             
            j++;
        }
        k++; // increment index in testArr

    }
    
    // following the maximum comparisons between both halves, ensure that the remaining elements are added
    // this is conveniently accomplished using the same indexed variables i,j,k
    while(i < leftSize) {
        testArr[k] = leftArr[i];
        i++;
        k++;
    }

    while(j < rightSize) {
        testArr[k] = rightArr[j];
        j++;
        k++;
    }

}

void mergeSort(int testArr[], int leftHalf, int rightHalf) {

    if(leftHalf < rightHalf) {

        // find point to split array in two equal portions
        int middle = leftHalf + (rightHalf - leftHalf) / 2;
        mergeSort(testArr, leftHalf, middle); // recursively sort the first half of the array [beginning to middle]
        mergeSort(testArr, middle + 1, rightHalf); // recursively sort the second half of the array [after middle to end]

        // call merge function in order to piece sorted arrays together and sort values in their simplest forms
        merge(testArr, leftHalf, middle, rightHalf);

    }

}

// merge sort code adapted from https://onlinegdb.com/HJT6FfMlv

int main() {

    // create array of set size from user input and call mergeSort
    int testArr[5];

    std::cout << "Enter five numbers to be sorted\n(press 'enter' after each number): " << endl;

    int currentNumber = 0;
    for(int i = 0; i < sizeof(testArr) / sizeof(testArr[0]); i++) {

        cin >> testArr[i];
    }

    mergeSort(testArr, 0, 4); // call mergeSort with array and its initial beginning and end positions

    std::cout << "Array after Merge Sorted:" << endl;
    for(int i = 0; i < sizeof(testArr) / sizeof(testArr[0]); i++) {

        std::cout << testArr[i] << endl;

    }

    return 0;

}