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
    static const size_t LIMIT = 1000;  // memory limit

    bool debug = false;

    int* reg = nullptr;      // memory register
    int* ptrReg = nullptr;   // pointer to current memory location
    int* ptrRegS = nullptr;  // pointer for working with strings

    int instructionRegister;  // holding space for words
    int instructionCounter;   // currently processed location
    int operationCode;        // currently processed instruction
    int operand;              // memory location of current instruction
    int accumulator;          // temp register

    int len;    // string length
    int ascii;  // 4 digit 2 char representation

    std::string simpleString;  // Simpletron string

    // operation codes
    static const int READ = 0x0A;         // read int
    static const int WRITE = 0x0B;        // write value
    static const int NEWLINE = 0x0C;      // write newline
    static const int READFLOAT = 0x0D;    // read float
    static const int WRITEFLOAT = 0x0E;   // write float
    static const int READSTRING = 0x0F;   // read stringa
    static const int WRITESTRING = 0x10;  // write string

    static const int LOAD = 0x14;   // load value into accumulator
    static const int STORE = 0x15;  // store value from accumulator

    static const int ADD = 0x1E;
    static const int SUBTRACT = 0x1F;
    static const int DIVIDE = 0x20;
    static const int MULTIPLY = 0x21;
    static const int MODULUS = 0x22;
    static const int EXPONENT = 0x23;

    static const int BRANCH = 0x28;      // branch to memory location
    static const int BRANCHNEG = 0x29;   // branch if accumulator negative
    static const int BRANCHZERO = 0x2A;  // branch if accumulator zero

    static const int HALT = 0x2B;
    static const int DEBUG = 0x2C;

    void addInstruction(int);   // add instruction to register
    void runProgram();          // runs simpletron program
    void processInstruction();  // processes instruction
    void processString(int);    // process strings

    void printGreeting();
    void printError(std::string);
    void printDump();

 public:
    Simpletron()
        : instructionRegister(0),
          instructionCounter(0),
          operationCode(0),
          operand(0),
          accumulator(0),
          len(0),
          ascii(0) {
        reg = new int[LIMIT]();
        ptrReg = &reg[0];
    }

    ~Simpletron() {
        if (reg != nullptr) {
            delete[] reg;
        }
        if (ptrReg != nullptr) {
            ptrReg = nullptr;
        }
        if (ptrRegS != nullptr) {
            ptrRegS = nullptr;
        }
    }

    void go();
};
