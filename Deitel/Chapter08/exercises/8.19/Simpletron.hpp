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

#include <iomanip>
#include <iostream>
#include <string>

class Simpletron {
 private:
    static const size_t LIMIT = 100;  // memory limit

    int* reg;     // memory register
    int* ptrReg;  // pointer to current memory location

    int instructionRegister;  // holding space for words
    int instructionCounter;   // currently processed location
    int operationCode;        // currently processed instruction
    int operand;              // memory location of current instruction
    int accumulator;          // temp register

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

    void addInstruction(int);   // add instruction to register
    void runProgram();          // runs simpletron program
    void processInstruction();  // processes instruction

    void printGreeting();
    void printError(std::string);
    void printDump();

 public:
    Simpletron()
        : instructionRegister(0),
          instructionCounter(0),
          operationCode(0),
          operand(0),
          accumulator(0) {
        reg = new int[LIMIT]();
        ptrReg = &reg[0];
    }

    ~Simpletron() {
        if (reg != nullptr) {
            delete[] reg;
        }
    }

    void go();
};
