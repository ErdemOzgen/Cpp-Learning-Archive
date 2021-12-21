#include <string>
#include <iostream>

using namespace std;

#include "./Passenger.hpp"
#include "./Vect.hpp"

void br() {
	cout << endl << "******************" << endl;
}

int main() {
	Passenger pass1("Zafar Takhirov", NO_PREF);
	pass1.print();
	Passenger pass2(pass1);
	pass2.print();

	br();

	Vect<int> a(100);
	Vect<int> b = a;
	Vect<int> c(a);

	c = a;
	c.print();

}