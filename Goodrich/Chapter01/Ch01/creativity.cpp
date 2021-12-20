#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

template <typename T>
void swap (T *A, T *B) {
	T temp = *A;
	*A = *B;
	*B = temp;
}

template <typename T>
void printArray (T ar[], int len) {
	for (int i = 0; i < len; i++) {
		cout << ar[i] << '\t';
	}
	cout << endl;
}

template <typename T>
void printVector (vector<T> v) {
	for (typename vector<T>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << '\t';
	}
	cout << endl;
}

// C-1.1	Writing C++ instead of pseudo
void reverseArray (int ar[], int len) {
	int stop = floor(len / 2);
	for (int i = 0; i < stop; i++) {
		// cout << ar[i] << endl;
		swap <int>(ar[i], ar[len-i-1]);
		// cout << ar[i] <<endl;
	}
}

void C_1_1 () {
	int ar1[11] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int ar2[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

	printArray<int>(ar1,11);
	reverseArray(ar1, 11);
	printArray<int>(ar1,11);
	cout << endl;
	printArray<int>(ar2,10);
	reverseArray(ar2, 10);
	printArray<int>(ar2,10);
}

// C-1.2
bool evenPair(int ar[], int len) {
	for (int i = 0; i < len; i++) {
		if (ar[i] % 2 == 0) return true;
	}
	return false;
}

void C_1_2() {
	int ar1[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
	int ar2[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 20};

	cout << (evenPair(ar1, 10) ? "THERE IS EVEN" : "THERE IS NO EVEN") << endl;
	cout << (evenPair(ar2, 10) ? "THERE IS EVEN" : "THERE IS NO EVEN") << endl;
}

// C-1.3
bool allDistinct (vector <int> ar) {
	// We will cheat - we will use set:
	set<int> s;
	s.insert(ar.begin(), ar.end());
	if (s.size() != ar.size()) return false;	// If sizes of array and set are different somethings is repeated
	else return true;
}

void C_1_3 () {
	int ar1[11] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int ar2[11] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0};

	vector<int> A, B;
	A.insert(A.begin(), ar1, ar1+11);
	B.insert(B.begin(), ar2, ar2+11);

	cout << (allDistinct(A) ? "TRUE" : "FALSE") << endl;
	cout << (allDistinct(B) ? "TRUE" : "FALSE") << endl;
}

// C-1.4
void printOdd(vector<int> ar) {
	for (vector<int>::iterator it = ar.begin(); it != ar.end(); ++it) {
		if (*it % 2) 
			cout << *it << ' ';
	}
	cout << endl;
}

void C_1_4() {
	int ar1[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
	int ar2[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 21};
	vector<int> A, B;
	A.insert(A.begin(), ar1, ar1+10);
	B.insert(B.begin(), ar2, ar2+10);
	printOdd(A);
	printOdd(B);
}

// C-1.5
#define RANGE_MIN	1
#define RANGE_MAX	52
void shuffle(int ar[RANGE_MAX]) {
	for (int i = 0; i < RANGE_MAX; i++) {
		int index = rand() % (RANGE_MAX-i) + i;	// from index i+1 to 51
		// cout << index << endl;
		swap(ar[i], ar[index]);
	}
}

void C_1_5() {
	int A[RANGE_MAX];
	for (int i = 0; i < RANGE_MAX; i++) {
		A[i] = i+1;
	}

	// printArray<int>(A, RANGE_MAX);
	int tests = 10;
	while (tests--) {
		shuffle(A);
		cout << "TEST:\t";
		printArray<int>(A, RANGE_MAX);
		cout << endl;
	}
}

// C-1.6
void charCombination (char str[], int len) {
	// int len = strlen(str);
	// cout << len << endl;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			cout << str[(i+j)%len];
		}
		cout << endl;
		for (int j = len-1; j >= 0; j--) {
			cout << str[(i+j)%len];
		}
		cout << endl;
	}
}

void C_1_6() {
	char word[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
	charCombination(word, 6);
	// char word[3] = {'a', 'b', 'c'};
	// charCombination(word, 3);
}

// C-1.7
vector<string> getLines() {
	vector<string> str;
	string myStr;
	cout << "Please, enter the strings (0 to stop):\n";
	do {
		getline(cin, myStr);
		str.push_back(myStr);
	} while (myStr != "0");
	str.pop_back();
	return str;
}

void C_1_7() {
	vector<string> str = getLines();
	for (vector<string>::reverse_iterator it = str.rbegin(); it != str.rend(); ++it) {
		cout << *it << endl;
	}
}

// C-1.8
/*vector<double>*/ void mult(vector<double> &a, vector<double> b) {
	// Destructive for a!
	assert(a.size() == b.size()); // Optional
	vector<double>::iterator aIt = a.begin();
	vector<double>::iterator bIt = b.begin();
	// vector<double>c;
	do {
		// c.push_back(*aIt * *bIt);
		*aIt = *aIt * *bIt;
		++aIt;
		++bIt;
	} while (aIt != a.end() || bIt != b.end());
	// return c;
}

void C_1_8() {
	double A[] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
	double B[] = {0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0};
	vector<double> a, b/*, c*/;
	a.insert(a.begin(), A, A+9);
	b.insert(b.begin(), B, B+9);
	/*c = */ mult(a,b);
	printVector<double>(a);
}

// C-1.9
class Vector2 {
// Not sure if understood the question right - do we store data and access it using x and y?
private:
	vector< vector<double> > vec;
public:
	Vector2(double x, double y);
	const Vector2 operator+(const Vector2 &A);
	const Vector2 operator*(const double &A);
	const double operator*(const Vector2 &A);
};

// C-1.10
long pow2(int i) {
	if (i < 0) {
		return 0;
	} else {
		return (long(1) << i);
	}
}

void C_1_10() {
	int i = 10;
	cout << pow2(i) << endl;
}

// C-1.11
int gcd(int n, int m) {
	assert(n > m);
	int temp;
	while (m != 0) {
		temp = n % m;
		n = m;
		m = temp;
	}
	return n;
}

void C_1_11() {
	int n = 80844;
	int m = 25320;
	cout << gcd(n, m) << endl;
}

int main() {
	srand (time(NULL));
	cout << "*****************C-1.1*****************\n";
	C_1_1();
	cout << "*****************C-1.2*****************\n";
	C_1_2();
	cout << "*****************C-1.3*****************\n";
	C_1_3();
	cout << "*****************C-1.4*****************\n";
	C_1_4();
	cout << "*****************C-1.5*****************\n";
	C_1_5();
	cout << "*****************C-1.6*****************\n";
	C_1_6();
	cout << "*****************C-1.7*****************\n";
	C_1_7();
	cout << "*****************C-1.8*****************\n";
	C_1_8();
	cout << "*****************C-1.10*****************\n";
	C_1_10();
	cout << "*****************C-1.11*****************\n";
	C_1_11();
}




