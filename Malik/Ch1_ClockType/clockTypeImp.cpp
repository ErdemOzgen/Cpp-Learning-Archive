
//**********************************************************
// Author: D.S. Malik
//
// Implementation file clockTypeImp.cpp 
// This file contains the definitions of the functions to 
// implement the operations of the classes clockType. 
//**********************************************************
  
#include <iostream>
#include "clockType.h"

using namespace std;

void clockType::setTime(int hours, int minutes, int seconds)
{
	if (0 <= hours && hours < 24)
	    hr = hours;
	else 
	    hr = 0;

	if (0 <= minutes && minutes < 60)
	    min = minutes;
	else 
	    min = 0;

	if (0 <= seconds && seconds < 60)
	    sec = seconds;
	else 
	    sec = 0;
}

void clockType::getTime(int& hours, int& minutes, int& seconds) const
{
	hours = hr;
	minutes = min;
	seconds = sec;
}

void clockType::incrementHours()
{
	hr++;
	if(hr > 23)
 	   hr = 0;
}

void clockType::incrementMinutes()
{
	min++;
	if (min > 59)
	{
	    min = 0;
	    incrementHours();
	}
}

void clockType::incrementSeconds()
{
	sec++;

	if (sec > 59)
	{
	    sec = 0;
	    incrementMinutes();
	}
}

void clockType::printTime() const
{
	if (hr < 10)
	    cout << "0";
	cout << hr << ":";

	if (min < 10)
	    cout << "0";
	cout << min << ":";

	if (sec < 10)
	   cout << "0";
	cout << sec;
}

bool clockType::equalTime(const clockType& otherClock) const
{
	return (this->hr == otherClock.hr 
		    && min == otherClock.min 
		    && sec == otherClock.sec);
}

clockType::clockType(int hours, int minutes, int seconds)
{
    if (0 <= hours && hours < 24)
        hr = hours;
    else 
        hr = 0;

    if (0 <= minutes && minutes < 60)
        min = minutes;
    else 
        min = 0;

    if (0 <= seconds && seconds < 60)
        sec = seconds;
    else 
        sec = 0;
}

clockType::clockType()  //default constructor
{
    hr = 0;
    min = 0;
    sec = 0;
}