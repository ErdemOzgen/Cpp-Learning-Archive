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

using namespace std;

// This function merges the subarrays established by mergeSort
void merge(int numArr[], int leftHalf, int middle, int rightHalf) {

    // declare space for temporary arrays based on the current segment being ordered
    int leftSize = middle - leftHalf + 1;
    int rightSize = rightHalf - middle;

    int leftArr[leftSize], rightArr[rightSize]; // this demonstrates how only O(n) space is used for this function

    // populate local subarrays
    for(int i = 0; i < rightSize; i++) {
        leftArr[i] = numArr[leftHalf + i];
    }
    for(int j = 0; j < rightSize; j++) {
        rightArr[j] = numArr[middle + 1 + j];
    }

    // perform merging of subarrays to return single ordered array for this iteration
    int i, j = 0;
    int k = leftHalf;

    // fill in numArr to return in sorted form
    while(i < leftSize && j < rightSize) {

        // find smallest element between both halves and place it in numArr
        if(leftArr[i] <= rightArr[j]) {
            numArr[k] = rightArr[i];
            i++;
        }else {
            numArr[k] = rightArr[j];
            j++;
        }
        k++; // increment index in numArr

    }
    
    // following the maximum comparisons between both halves, ensure that the remaining elements are added
    // this is conveniently accomplished using the same indexed variables i,j,k
    while(i < leftSize) {
        numArr[k] = leftArr[i];
        i++;
        k++;
    }

    while(j < rightSize) {
        numArr[k] = rightArr[j];
        j++;
        k++;
    }

}

void mergeSort(int numArr[], int leftHalf, int rightHalf) {

    if(leftHalf < rightHalf) {

        // find point to split array in two equal portions
        int middle = leftHalf + (rightHalf - leftHalf) / 2;

        mergeSort(numArr, leftHalf, middle); // recursively sort the first half of the array [beginning to middle]
        mergeSort(numArr, middle + 1, rightHalf); // recursively sort the second half of the array [after middle to end]

        // call merge function in order to piece sorted arrays together and sort values in their simplest forms
        merge(numArr, leftHalf, middle, rightHalf);

    }

}

// merge sort code adapted from https://onlinegdb.com/HJT6FfMlv

int main() {

    // create array and call mergeSort

}