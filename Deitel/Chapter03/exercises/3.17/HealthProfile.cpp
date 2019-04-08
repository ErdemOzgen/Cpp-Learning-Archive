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
#include <string>

#include "HealthProfile.hpp"

HealthProfile::HealthProfile(const std::string &fName, const std::string &lName,
                             const std::string &g, int m, int d, int y, double h,
                             double w) {
    setFirstName(fName);
    setLastName(lName);
    setGender(g);
    setDOB(m, d, y);
    setHeight(h);
    setWeight(w);
    setAge();
}
// SETTERS
void HealthProfile::setFirstName(const std::string &fName) {
    firstName = (fName.length() > 0) ? fName : "FirstName";
}
void HealthProfile::setLastName(const std::string &lName) {
    lastName = (lName.length() > 0) ? lName : "LastName";
}
void HealthProfile::setGender(const std::string &g) {
    gender = (g == "Male" || g == "Female") ? g : "Undefined";
}
void HealthProfile::setDOB(int m, int d, int y) {
    setMonth(m);
    setDay(d);
    setYear(y);
}
void HealthProfile::setMonth(int m) { month = (m > 0 && m <= 12) ? m : 1; }
void HealthProfile::setDay(int d) { day = (d > 0 && d <= 31) ? d : 1; }
void HealthProfile::setYear(int y) { year = y; }
void HealthProfile::setAge() {
    int cDay, cMonth, cYear;

    std::cout << "Enter the current date (mm dd yyyy): ";
    std::cin >> cMonth >> cDay >> cYear;

    if (cMonth < getMonth()) {
        ageInYears = (cYear - getYear()) - 1;
    } else if (cMonth > getMonth()) {
        ageInYears = cYear - getYear();
    } else {
        if (cDay < getDay()) {
            ageInYears = (cYear - getYear()) - 1;
        } else {
            ageInYears = cYear - getYear();
        }
    }
}
void HealthProfile::setHeight(int h) { height = h; }
void HealthProfile::setWeight(int w) { weight = w; }
// GETTERS
std::string HealthProfile::getFirstName() const { return firstName; }
std::string HealthProfile::getLastName() const { return lastName; }
std::string HealthProfile::getGender() const { return gender; }
int HealthProfile::getMonth() const { return month; }
int HealthProfile::getDay() const { return day; }
int HealthProfile::getYear() const { return year; }
void HealthProfile::getDOB() const {
    std::cout << getMonth() << "/" << getDay() << "/" << getYear() << std::endl;
}
int HealthProfile::getAge() {
    if (ageInYears == 0) {
        setAge();
    }

    return ageInYears;
}
double HealthProfile::getHeight() const { return height; }
double HealthProfile::getWeight() const { return weight; }
double HealthProfile::getBMI() const {
    return ((getWeight() * 703) / (getHeight() * getHeight()));
}
// returns a persons target heart rate
void HealthProfile::getTargetHeartRate() {
    std::cout << "Your Target Heart Rate: ";
    std::cout << 0.5 * getMaxHeartRate() << " - " << 0.85 * getMaxHeartRate()
              << std::endl;
}
int HealthProfile::getMaxHeartRate() { return 220 - getAge(); }
void HealthProfile::showHealthProfile() {
    std::cout << "HEALTH PROFILE FOR: " << getFirstName() << " "
              << getLastName() << std::endl;
    std::cout << "Gender: " << getGender() << std::endl;
    std::cout << "Age: " << getAge() << std::endl;
    std::cout << "BMI: " << getBMI() << std::endl;
    getTargetHeartRate();
    std::cout << "Max Heart Rate: " << getMaxHeartRate() << std::endl;
    printBMIInfo();
}
void HealthProfile::printBMIInfo() const {
    std::cout << "\nBMI VALUES" << std::endl;
    std::cout << "Underweight: less than 18.5" << std::endl;
    std::cout << "Normal:      between 18.5 and 24.9" << std::endl;
    std::cout << "Overweight:  between 25 and 29.9" << std::endl;
    std::cout << "Obese:       30 or greater\n" << std::endl;
}
