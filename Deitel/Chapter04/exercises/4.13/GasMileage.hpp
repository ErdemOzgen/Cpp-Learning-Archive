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

class GasMileage {
 private:
    double milesDriven = 0.0f;
    double gallonsUsed = 0.0f;
    double tripMPG = 0.0f;
    double totalMPG = 0.0f;

 public:
    GasMileage();

    // SETTERS
    void setMilesDriven();
    void setGallonsUsed();
    void setTripMPG();
    void setTotalMPG();

    // GETTERS
    double getMilesDriven() const;
    double getGallonsUsed() const;
    double getTripMPG() const;
    double getTotalMPG() const;

    void run();
};
