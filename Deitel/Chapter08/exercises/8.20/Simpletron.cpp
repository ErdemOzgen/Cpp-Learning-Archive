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
    printGreeting();

    while (true) {
        std::cout << std::setw(2) << std::setfill('0') << instructionCounter++
                  << " ? ";
        std::cin >> instructionRegister;

        if (instructionRegister == -99999) {
            break;
        } else if (instructionRegister > 9999 || instructionRegister < -9999) {
            --instructionCounter;
            continue;
        }

        *(ptrReg++) = instructionRegister;
    }

    // reset vars - avoid unexpected errors
    instructionCounter = 0;
    instructionRegister = 0;
    ptrReg = &reg[0];

    std::cout << std::setw(0) << "\n*** Program loading completed ***"
              << "\n*** Program execution begins ***\n"
              << std::endl;

    runProgram();
}
/*
 * Prints greeting on program execution
 */
void Simpletron::printGreeting() {
    std::cout << "*** Welcome to Simpletron! ***"
              << "\n\n*** Please enter your program one instruction ***"
              << "\n*** (or data word) at a time. I will type the ***"
              << "\n*** location number and a question mark(?). ***"
              << "\n*** You then type the word for that instructionCounter. ***"
              << "\n*** Type the sentinel -99999 to stop entering ***"
              << "\n*** your program. ***\n"
              << std::endl;
}
/*
 * Loops over register until exit condition is met
 */
void Simpletron::runProgram() {
    while (operationCode != HALT) {
        instructionRegister = *(ptrReg++);

        processInstruction();
    }
}
/*
 * Processes Simpletron instructions
 */
void Simpletron::processInstruction() {
    // seperate word
    operand = instructionRegister % 100;
    operationCode = instructionRegister / 100;

    switch (operationCode) {
        // read int from keyboard into operand
        case READ:
            std::cout << "> ";
            std::cin >> instructionRegister;

            reg[operand] = instructionRegister;

            break;
        // write int from operand to screen
        case WRITE:
            std::cout << reg[operand] << std::endl;

            break;
        // write a newline
        case NEWLINE:
            std::cout << std::endl;
            break;
        // read a float
        case READFLOAT:
            float val;

            std::cout << "> ";
            std::cin >> val;

            std::cout << val << " " << static_cast<int>(val) << " "
                      << (val - static_cast<int>(val)) * 100 << std::endl;

            break;
        // write a float
        case WRITEFLOAT:
            break;
        // read a string
        case READSTRING:
            std::cin.ignore();

            std::cout << "> ";
            std::getline(std::cin, simpleString);

            processString(operand);

            break;
        // write a string
        case WRITESTRING:
            ptrRegS = &reg[operand];

            len = *ptrRegS % 100;

            printf("%c", *(ptrRegS++) % 100);  // print first char

            for (int i = operand + 1;
                 i <= operand + (len / 2) && *ptrRegS != '\0'; ++i, ptrRegS++) {
                printf("%c%c", *ptrRegS / 100, *ptrRegS % 100);
            }
            std::cout << std::endl;

            ptrRegS = nullptr;
            len = 0;

            break;
        // load word from operand to accumulator
        case LOAD:
            accumulator = reg[operand];
            break;
        // store word from accumulator to operand
        case STORE:
            reg[operand] = accumulator;
            break;
        // add word from operand to accumulator (result in accumulator)
        case ADD:
            accumulator += reg[operand];
            break;
        // subtract word from operand to accumulator (result in accumulator)
        case SUBTRACT:
            accumulator -= reg[operand];
            break;
        // divide word from operand to accumulator (result in accumulator)
        case DIVIDE:
            if (accumulator == 0 || reg[operand] == 0) {
                printError("Attempt to divide by zero");
                operationCode = HALT;
            } else {
                accumulator /= reg[operand];
            }
            break;
        // multiply word from operand to accumulator (result in accumulator)
        case MULTIPLY:
            accumulator *= reg[operand];
            break;
        // modulus word from operand to accumulator (result in accumulator)
        case MODULUS:
            accumulator = (accumulator % reg[operand]);
            break;
        // accumulator ^ word (result in accumulator)
        case EXPONENT:
            for (int i = 1; i < reg[operand]; ++i) {
                accumulator *= accumulator;
            }
            break;
        // branch to operand
        case BRANCH:
            ptrReg = &reg[operand];
            processInstruction();
            break;
        // branch to operand if accumulator is negative
        case BRANCHNEG:
            if (accumulator < 0) {
                ptrReg = &reg[operand];
                processInstruction();
            }
            break;
        // branch to operand is accumulator is zero
        case BRANCHZERO:
            if (accumulator == 0) {
                ptrReg = &reg[operand];
                processInstruction();
            }
            break;
        // halt program - exit condition
        case HALT:
            break;
        // turn on/off debugging mode
        case DEBUG:
            if (operand == 1 || operand == 0) {
                debug = operand;
            }
            break;
        default:
            printError("Unknown Instruction");
            operationCode = HALT;
            break;
    }

    if (debug) {
        printDump();
    }
}

/*
 * Splits and stores the given string in the register
 */
void Simpletron::processString(int operand) {
    ptrRegS = &reg[operand];
    len = simpleString.length();

    // convert to UPPERCASE (can only store chars as 2 digit integers)
    for (int i = 0; i < len; ++i) {
        if (simpleString[i] > 90) {
            simpleString[i] = simpleString[i] - 32;
        }
    }

    ascii = (len * 100) + simpleString[0];

    *(ptrRegS++) = ascii;

    for (int i = 1; i < len; i += 2) {
        // ensure don't exceed bounds of string
        if (i + 1 <= len) {
            ascii = (simpleString[i] * 100) + simpleString[i + 1];
        } else {  // last char (add null terminator)
            ascii = simpleString[i] * 100;
        }

        *(ptrRegS++) = ascii;
    }

    ptrRegS = nullptr;
    len = 0;
    ascii = 0;
}
/*
 * Prints an error message
 */
void Simpletron::printError(std::string error) {
    std::cout << "*** " << error << " ***"
              << "\n*** Simpletron execution abnormally terminated ***"
              << std::endl;

    printDump();
}
/*
 * Prints a memory dump
 */
void Simpletron::printDump() {
    std::cout << std::setfill('0') << "\nREGISTERS:\n"
              << "\naccumulator          " << std::showpos << std::setw(4)
              << accumulator << "\ninstructionCounter   " << std::noshowpos
              << instructionCounter << "\ninstructionRegister  " << std::showpos
              << std::setw(4) << instructionRegister
              << "\noperationCode        " << std::noshowpos << operationCode
              << "\noperand              " << operand << "\n\nMEMORY:\n"
              << "  ";

    int* ptrReg = &reg[0];  // local ptrReg to avoid resetting main

    for (int i = 0; i < 10; ++i) {
        std::cout << std::setfill(' ') << std::right << std::setw(5) << i
                  << " ";
    }

    std::cout << std::endl;

    // for(int i=0; i<LIMIT/10; ++i){
    for (int i = 0; i < 10; ++i) {
        std::cout << std::right << std::setfill('0') << std::noshowpos
                  << std::setw(3) << i * 10 << " ";
        for (int j = 0; j < 10; ++j) {
            std::cout << std::left << std::showpos << std::setw(5)
                      << std::setfill('0') << *(ptrReg++) << " ";
        }
        std::cout << std::endl;
    }
}
