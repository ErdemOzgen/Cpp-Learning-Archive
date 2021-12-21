#include <cassert>
#include <cstdlib>
#include <iostream>
#include <set>
#include <time.h>
#include <vector>

using namespace std;

// P-1.1
void P_1_1() {
	const int REPEATS = 100;
	const string STR = "I will always use object-oriented design.\n";
	const int len = STR.length();
	string str;
	char rChar;
	int pos;
	int count = 0;
	for (int i = 0; i < REPEATS; i++) {
		str = STR;
		rChar = char(rand()%25) + 'a';
		pos = rand() % (len-1);
		// cout << pos << '\t';
		if (rand()%100 < 8 && count < 8){
			str.replace(pos, 1, &rChar);
			cout << i+1 << ".*\t" << str;
			count++;
		} else {
			cout << i+1 << ".\t" << str;
		}
		
	}
}


// P-1.2
bool isLeap(int year) {
	if (year % 4 != 0) {
		return false;
	} else if (year % 100 != 0) {
		return true;
	} else if (year % 400 != 0) {
		return false;
	} else {
		return true;
	}

}

int printMonth(int month, int offset, bool leap, int startDay = 0){
	// month	-> 0=January, ..., 11=December
	// offset	-> up to 6 blanks - start day of the month
	// leap		-> For february only
	// startDay	-> 0=Sunday, ..., 6=Saturday - start day of the week
	// 		return the offset for the next month
	assert (month < 12);
	assert (offset < 7);
	assert (startDay < 7);
	int days;	// Number of days in a month
	const string weekDays = "SMTWTFS";
	switch (month) {
		case 0:
		case 2:
		case 4:
		case 6:
		case 7:
		case 9:
		case 11:
			days = 31;
			break;
		case 1:
			days = leap ? 29 : 28;
			break;
		default:
			days = 30;
	}

	// Print weekdays labels:
	for (int i = 0; i < 7; i++) {
		cout << weekDays[(i+startDay)%7] << '\t';
	}
	cout << endl;
	
	int nl = 0;	// To keep track when to go to *new line*
	// Create offset:
	for (int j = 0; j < offset; j++) {
		cout << '\t';
		nl++;
	}
	// Start printing days:
	for (int i = 0; i < days; i++) {
		if (nl >= 7) {
			nl = 0;
			cout << endl;
		}
		cout << i+1 << '\t';
		nl++;
	}
	cout << endl << endl;
	return (nl%7);
}

void printYear(int offset, int year) {
	bool leap = isLeap(year);
	const string months[12] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	// cout << months[int(leap)];
	for (int i = 0; i < 12; i++) {
		cout << "\t\t" << months[i] << endl;
		offset = printMonth(i, offset, leap);
		cout << endl;
	}
}

int convertDay(string day) {
	if (day ==  "Sunday") 			return 0;
	else if (day == "Monday") 		return 1;
	else if (day == "Tuesday") 		return 2;
	else if (day == "Wednesday") 	return 3;
	else if (day == "Thursday") 	return 4;
	else if (day == "Friday") 		return 5;
	else if (day == "Saturday") 	return 6;
	else 							return -1;
}

void P_1_2() {
	int year;
	int offset;
	string dayAnswer;
	cout << "Please, enter the year: ";
	cin >> year;
	cout << "Please, enter the start day: ";
	cin >> dayAnswer;
	offset = convertDay(dayAnswer);
	while (offset == -1) {
		cout << "Valid response is the day of the week (capitalized)\n";
		cout << "Please, enter the start day: ";
		cin >> dayAnswer;
		offset = convertDay(dayAnswer);
	}
	printYear(offset, year);
}

// P_1_3
int generateBirthday() {
	return rand() % 365 + 1;	// Generate number from 1 to 365
}

float birthday(int people, int trials) {
	int pairs = 0;	// number of trials that had duplicates
	for (int i = 0; i < trials; i++) {
		// vector<int> bdaysV;	// vector with all birthdays
		set<int> bdaysS;	// set with unique birthdays
		pair<set<int>::iterator,bool> ret;
		for (int j = 0; j < people; j++) {
			// bdaysV.push_back(generateBirthday());
			ret = bdaysS.insert(generateBirthday());
			if (ret.second == false) {	// If already existed, same birthdays
				pairs++;
				break;	// go to next trial
			}
		}
		/*
		bdaysS.insert(bdaysV.begin(), bdaysV.end());
		if (bdaysS.size() != bdaysV.size()) {
			pairs++;
		}
		*/
	}
	return float(pairs) / float(trials);
}

void P_1_3() {
	const int nums = 20;
	const int step = 5;
	const int start = 5;
	int n;
	n = start;
	// vector<float> perc;
	for (int i = 0; i < nums; i++) {
		// perc.push_back(birthday(n, 100));
		cout << n << ":\t" << birthday(n, 1000)*100 << '%' << endl;
		n = n + step;
	}
	// const int n[] = {
	// 	5, 10, 15, 20, 25, 30, 35, 40, 45, 50,
	// 	55, 60, 65, 70, 75, 80, 85, 90, 95, 100};

}

int main() {
	srand(time(NULL));
	cout << "\n*****************P-1.1*****************\n";
	P_1_1();
	cout << "\n*****************P-1.2*****************\n";
	P_1_2();
	cout << "\n*****************P-1.3*****************\n";
	P_1_3();
}


