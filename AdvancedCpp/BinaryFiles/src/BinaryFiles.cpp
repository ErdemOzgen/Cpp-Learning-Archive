//============================================================================
// Name        : Binary.cpp
// Author      : ErdemOzgen
// Version     :1.0.0
// Copyright   : MIT License
// Description : Binary read  in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#pragma pack(push, 1) //https://stackoverflow.com/a/3318475
// https://docs.microsoft.com/en-us/cpp/preprocessor/pack?view=msvc-170#examples

struct Person {
	char name[50];
	int age;
	double height;
};

#pragma pack(pop)

int main() {

	Person someone = { "Frodo", 220, 0.8 };

	string fileName = "test.bin";

	//// Write binary file ////////////////

	ofstream outputFile;

	outputFile.open(fileName, ios::binary);

	if (outputFile.is_open()) {

		outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));

		outputFile.close();
	} else {
		cout << "Could not create file " + fileName;
	}

	//// Read binary file ////////////////

	Person someoneElse = {};

	ifstream inputFile;

	inputFile.open(fileName, ios::binary);

	if (inputFile.is_open()) {

		inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));

		inputFile.close();
	} else {
		cout << "Could not read file " + fileName;
	}

	cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.height << endl;

	return 0;
}
