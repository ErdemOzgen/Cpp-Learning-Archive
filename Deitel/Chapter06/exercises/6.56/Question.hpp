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

// represents a single question
template <typename T>

struct Question {
    T num1;
    T num2;

    void init(T n1, T n2) {
        num1 = n1;
        num2 = n2;
    }

    T multiply() { return num1 * num2; }

    T add() { return num1 + num2; }

    T subtract() { return num1 - num2; }

    T divide() {
        // prevent divide by zero
        num1 = (num1 == 0 ? 1 : num1);
        num2 = (num2 == 0 ? 1 : num2);

        double scale = 0.01;
        return static_cast<int>((num1 / num2) / scale) * scale;
    }
};
