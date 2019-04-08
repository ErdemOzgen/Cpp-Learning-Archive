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

class Simpletron {
 private:
    int reg[100];  // memory register
    int *ptrReg;   // pointer to current memory location

    int word;         // user defined instructions
    int instruction;  // currently processed instruction
    int location;     // currently processed location
    int accumulator;  // temp register

    // operation codes
    static const int READ = 10;
    static const int WRITE = 11;

    static const int LOAD = 20;
    static const int STORE = 21;

    static const int ADD = 30;
    static const int SUBTRACT = 31;
    static const int DIVIDE = 32;
    static const int MULTIPLY = 33;

    static const int BRANCH = 40;
    static const int BRANCHNEG = 41;
    static const int BRANCHZERO = 42;

    static const int HALT = 43;

    void addInstruction(int);      // add instruction to register
    void runProgram();             // runs simpletron program
    void processInstruction(int);  // processes instruction

 public:
    Simpletron() : word(0), instruction(0), location(0), accumulator(0) { ptrReg = &reg[0]; }
    ~Simpletron() {}

    void go();
};
