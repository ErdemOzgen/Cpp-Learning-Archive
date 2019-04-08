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
#include <iostream>
#include <string>

#include "HeartRates.hpp"

HeartRates::HeartRates(const std::string &fName, const std::string &lName,
        int m, int d, int y) {
    setFirstName(fName);
    setLastName(lName);
    setDOB(m, d, y);
}

// SETTERS
void HeartRates::setFirstName(const std::string &fName) {
    firstName = (fName.length() > 0) ? fName : "FirstName";
}
void HeartRates::setLastName(const std::string &lName) {
    lastName = (lName.length() > 0) ? lName : "Surname";
}
void HeartRates::setDOB(int m, int d, int y) {
    setMonth(m);
    setDay(d);
    setYear(y);
    setAge();
}
void HeartRates::setMonth(int m) { month = (m > 0 && m <= 12) ? m : 1; }
void HeartRates::setDay(int d) { day = (d > 0 && d <= 31) ? d : 1; }
void HeartRates::setYear(int y) { year = y; }
void HeartRates::setAge() { ageInYears = getAge(); }

// GETTERS
std::string HeartRates::getFirstName() const { return firstName; }
std::string HeartRates::getLastName() const { return lastName; }
int HeartRates::getMonth() const { return month; }
int HeartRates::getDay() const { return day; }
int HeartRates::getYear() const { return year; }
int HeartRates::getAge() const {
    if (ageInYears > 0) {
        return ageInYears;
    }

    int cDay, cMonth, cYear;

    std::cout << "Enter the current date(mm dd yyyy): ";
    std::cin >> cMonth >> cDay >> cYear;

    if (cMonth < getMonth()) {
        return (cYear - getYear()) - 1;
    } else if (cMonth > getMonth()) {
        return cYear - getYear();
    } else {
        return ((cDay < getDay()) ? ((cYear - getYear()) - 1) : (cYear - getYear()));
    }
}
// returns a persons maximum heart rate in bpm
int HeartRates::getMaximumHeartRate() const { return 220 - getAge(); }
// returns a persons target heart rate
void HeartRates::getTargetHeartRate() const {
    std::cout << "Your Target Heart Rate: "
              << 0.5 * getMaximumHeartRate() << " - "
              << 0.85 * getMaximumHeartRate() << std::endl;
}
// displays person information
void HeartRates::displayInformation() const {
    std::cout << "\nName: " << getFirstName() << " " << getLastName()
              << std::endl;
    std::cout << "D.O.B: " << getMonth() << "/" << getDay() << "/" << getYear()
              << std::endl;
    std::cout << "Maximum Heart Rate: " << getMaximumHeartRate() << std::endl;
    getTargetHeartRate();
}
