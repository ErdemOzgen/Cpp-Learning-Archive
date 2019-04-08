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

template <typename T>

T maximum(T value1, T value2, T value3) {
    T maximumValue = value1;

    if (value2 > maximumValue) {
        maximumValue = value2;
    }

    if (value3 > maximumValue) {
        maximumValue = value3;
    }

    return maximumValue;
}

