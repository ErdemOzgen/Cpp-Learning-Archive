#include <iostream>

using namespace std;

unsigned long long factorial(int n) {
	if (n == 0) return 1;
	else return n*factorial(n-1);
}

int main() {
	cout << factorial (5) << endl;
}