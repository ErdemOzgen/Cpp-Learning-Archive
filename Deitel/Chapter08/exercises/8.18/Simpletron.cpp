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
#include "Simpletron.hpp"

/*
 * Program Entry Point
 */
void Simpletron::go() {
    while (true) {
        std::cout << "> ";
        std::cin >> word;

        if (word == -9999) { break; }

        instruction = word / 100;

        *(ptrReg++) = word;
    }

    // reset vars - avoid unexpected errors
    instruction = 0;
    word = 0;
    ptrReg = &reg[0];

    runProgram();
}

/*
 * Loops over register until exit condition is met
 */
void Simpletron::runProgram() {
    while (instruction != HALT) {
        processInstruction(*(ptrReg++));
    }
}

/*
 * Processes Simpletron instructions
 */
void Simpletron::processInstruction(int w) {
    // seperate word
    location = w % 100;
    instruction = w / 100;

    switch (instruction) {
        // read word from keyboard into location
        case READ:
            int newWord;

            std::cout << "> ";
            std::cin >> newWord;

            reg[location] = newWord;

            break;
        // write word from location to screen
        case WRITE:
            std::cout << reg[location] << std::endl;

            break;
        // load word from location to accumulator
        case LOAD:
            accumulator = reg[location];
            break;
        // store word from accumulator to location
        case STORE:
            reg[location] = accumulator;
            break;
        // add word from location to accumulator (result in accumulator)
        case ADD:
            accumulator += reg[location];
            break;
        // subtract word from location to accumulator (result in accumulator)
        case SUBTRACT:
            accumulator -= reg[location];
            break;
        // divide word from location to accumulator (result in accumulator)
        case DIVIDE:
            accumulator /= reg[location];
            break;
        // multiply word from location to accumulator (result in accumulator)
        case MULTIPLY:
            accumulator *= reg[location];
            break;
        // branch to location
        case BRANCH:
            ptrReg = &reg[location];
            break;
        // branch to location if accumulator is negative
        case BRANCHNEG:
            if (accumulator < 0) {
                ptrReg = &reg[location];
            }
            break;
        // branch to location is accumulator is zero
        case BRANCHZERO:
            if (accumulator == 0) {
                ptrReg = &reg[location];
            }
            break;
        // halt program - exit condition
        case HALT:
            break;
    }
}
