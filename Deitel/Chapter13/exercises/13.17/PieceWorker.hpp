/*
 * =====================================================================================
 *
 *       Filename:  PieceWorker.hpp
 *
 *    Description:  Exercise 13.17 - Payroll System Modification
 *
 *        Version:  1.0
 *        Created:  01/09/16 21:23:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siidney Watson - siidney.watson.work@gmail.com
 *   Organization:  LolaDog Studio
 *
 * =====================================================================================
 */
#pragma once

#include "Employee.hpp"

class PieceWorker : public Employee {
 public:
    PieceWorker(const std::string&, const std::string&, const std::string&,
                double = 0.0f, double = 0.0f);

    void setWage(double);
    double getWage() const;

    void setPieces(double);
    double getPieces() const;

    // overridden functions
    virtual double earnings() const;
    virtual void print() const;

 private:
    double wage;
    double pieces;
};
