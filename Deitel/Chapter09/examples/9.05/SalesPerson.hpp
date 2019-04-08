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

class SalesPerson {
 public:
    static const int monthsPerYear = 12;

    SalesPerson();

    void getSalesFromUser();
    void setSales(int, double);
    void printAnnualSales();

 private:
    double totalAnnualSales();
    double sales[monthsPerYear];
};
