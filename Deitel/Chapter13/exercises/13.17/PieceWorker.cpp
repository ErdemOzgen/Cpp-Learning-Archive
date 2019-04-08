/*
 * =====================================================================================
 *
 *       Filename:  PieceWorker.cpp
 *
 *    Description:  Exercise 13.17 - Payroll System Modification
 *
 *        Version:  1.0
 *        Created:  01/09/16 21:26:36
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#include <string>

#include "PieceWorker.hpp"

PieceWorker::PieceWorker(const std::string& first, const std::string& last,
                         const std::string& ssn, double pieces, double wage)
    : Employee(first, last, ssn) {
    setPieces(pieces);
    setWage(wage);
}
// set pieces
void PieceWorker::setPieces(double p) {
    if (p >= 0.0f) {
        pieces = p;
    } else {
        throw std::invalid_argument("Pieces produced must be >= 0.0f");
    }
}
// get pieces
double PieceWorker::getPieces() const { return pieces; }
// set wage
void PieceWorker::setWage(double w) {
    if (w > 0.0f) {
        wage = w;
    } else {
        throw std::invalid_argument("Wage must be > 0.0f");
    }
}
// get wage
double PieceWorker::getWage() const { return wage; }
// calculate earnings
double PieceWorker::earnings() const { return getPieces() * getWage(); }
// print PieceWorker's information
void PieceWorker::print() const {
    std::cout << "Piece Worker: ";
    Employee::print();
    std::cout << "\nwages: $" << getWage() << "\npieces: " << getPieces();
}
