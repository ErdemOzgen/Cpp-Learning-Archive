//============================================================================
// Name        : Fractal.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Bitmap.h"

using namespace std;
using namespace caveofprogramming;

int main() {

	Bitmap bitmap(800, 600);

	bitmap.write("test.bmp");

	cout << "Finished." << endl;
	return 0;
}
