//============================================================================
// Name        : BasicException.cpp
// Author      : ErdemOzgen
// Version     :1.0.0
// Copyright   : MIT License
// Description : BasicException  C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

void mightGoWrong() {

	bool error1 = true;
	bool error2 = true;
    bool error3 = true;
	if(error1) {
		throw "Something went wrong. Const Char * Catching";
	}

	if(error2) {
		throw string("Something else went wrong. String Catching");
	}
    if (error3) {
        throw 12; // int catching
    }

}

void usesMightGoWrong() {
	mightGoWrong();
}

void TryCatchingFunction(void (*erdem)()) { //https://stackoverflow.com/questions/9410/how-do-you-pass-a-function-as-a-parameter-in-c
    try {
        erdem();
    }
    catch(int e) {
        cout << "Error code: " << e << endl;
    }
    catch(char const * e) {
        cout << "Error message: " << e << endl;
    }
    catch(string &e) {
        cout << "string error message: " << e << endl;
    }

}


int main() {

    TryCatchingFunction(mightGoWrong);

	cout << "Still running" << endl;

	return 0;
}
