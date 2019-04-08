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
#include "SalaryCalculator.hpp"

SalaryCalculator::SalaryCalculator() {}
// SETTERS
void SalaryCalculator::setManagerRate(double rate) {
    if (rate > 0.0f) {
        managerRate = rate;
    } else {
        std::cout << "Manager rate must be > 0.0" << std::endl;
    }
}
void SalaryCalculator::setHourlyRate(double rate) {
    if (rate > 0.0f) {
        hourlyRate = rate;
    } else {
        std::cout << "Hourly rate must be > 0.0" << std::endl;
    }
}
void SalaryCalculator::setWeeklySales(double sales) {
    weeklySales = sales;

    if (sales == 0.0f) {
        std::cout << "\nPoor thing. You sold nothing all week :(\n"
                  << std::endl;
    }
}
void SalaryCalculator::setHoursWorked(double hw) {
    if (hw >= 0.0f) {
        hoursWorked = hw;
    } else {
        std::cout << "Hours worked must be >= 0.0" << std::endl;
    }
}
void SalaryCalculator::setEmployeeCode(int emp) {
    if (emp >= 1 && emp <= 4) {
        employeeCode = emp;
    } else {
        std::cout << "Invalid employee code (1-4)" << std::endl;
    }
}
void SalaryCalculator::setPiecesProduced(int pieces) {
    piecesProduced = pieces;

    if (pieces == 0.0f) {
        std::cout << "\nPoor little fella made nothing this week :(\n"
                  << std::endl;
    }
}
void SalaryCalculator::inputSalaries() {
    int iValue = 0;

    std::cout << "Salary Calculator" << std::endl;

    while (iValue != -1) {
        std::cout << "Enter an employee number (1-4). -1 to quit: ";
        std::cin >> iValue;

        if (iValue != -1) {
            setEmployeeCode(iValue);
        }

        if (iValue >= 1 && iValue <= 4) {
            calculateSalary();
            reset();
        }
    }
}
double SalaryCalculator::calculateSalary() {
    double dValue = 0.0f;

    switch (getEmployeeCode()) {
        // MANAGER
        case 1:
            std::cout << "\nEnter manager weekly salary: ";
            std::cin >> dValue;

            setManagerRate(dValue);

            printf("Manager Salary: $%.2f\n\n", getManagerRate());

            break;
        // HOURLY PAY
        case 2:
            std::cout << "\nEnter hourly rate: ";
            std::cin >> dValue;

            if (dValue > 0.0f) {
                setHourlyRate(dValue);

                std::cout << "Enter hours worked: ";
                std::cin >> dValue;

                setHoursWorked(dValue);

                dValue = getHourlyRate();

                dValue *=
                    (getHoursWorked() <= 40.0f) ? getHoursWorked() : 40.0f;

                if (getHoursWorked() > 40.0f) {
                    dValue += ((getHoursWorked() - 40.0f) *
                               (getHourlyRate() * HOURLY_OVERTIME));
                }

                printf("Hourly Worker Salary: $%.2f\n\n", dValue);
            }
            break;
        // COMMISSION
        case 3:
            std::cout << "\nEnter gross weekly sales: ";
            std::cin >> dValue;

            setWeeklySales(dValue);

            dValue = COMMISSION_BASE + (getWeeklySales() * COMMISSION_RATE);

            printf("Commission Worker Salary: $%.2f\n\n", dValue);
            break;
        // PIECE WORK
        case 4:
            std::cout << "\nEnter pieces produced: ";
            std::cin >> dValue;

            setPiecesProduced(dValue);

            printf("Piece Worker Salary: $%.2f\n\n",
                   getPiecesProduced() * PIECE_RATE);
            break;
        default:
            std::cout << "Incorrect employee code entered" << std::endl;
            break;
    }
    return dValue;
}
void SalaryCalculator::reset() {
    managerRate = 0.0f;
    hourlyRate = 0.0f;
    weeklySales = 0.0f;
    hoursWorked = 0.0f;

    employeeCode = 0;
    piecesProduced = 0;
}
