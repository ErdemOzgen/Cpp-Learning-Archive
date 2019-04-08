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

#include <string>

class HeartRates {
 private:
    std::string firstName;
    std::string lastName;
    int month = 1;
    int day = 1;
    int year = 1900;
    int ageInYears = 0;

 public:
    HeartRates(const std::string &, const std::string &, int, int, int);

    // SETTERS
    void setFirstName(const std::string &);
    void setLastName(const std::string &);
    void setDOB(int, int, int);
    void setMonth(int);
    void setDay(int);
    void setYear(int);
    void setAge();

    // GETTERS
    std::string getFirstName() const;
    std::string getLastName() const;
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    int getAge() const;
    int getMaximumHeartRate() const;
    void getTargetHeartRate() const;

    void displayInformation() const;
};
