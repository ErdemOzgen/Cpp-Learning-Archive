#include <cassert>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <set>
#include <time.h>
#include <vector>

using namespace std;

// P-2.1
unsigned numberOf2s(unsigned x) {
	assert (x > 2);
	unsigned num = 0;
	while (x >= 2) {
		num++;
		x = x >> 1;
	}
	return num;
}

void P_2_1() {
	cout << "Check 3: ";
	cout << numberOf2s(3) << endl;
	cout << "Check 30: ";
	cout << numberOf2s(30) << endl;

}


// P-2.2 - should have used classes!
enum DENOMS {	// Number of cents
	HUND = 10000,
	FIFT = 5000,
	TWEN = 2000,
	TENS = 1000,
	FIVS = 500,
	ONES = 100,
	QUAR = 25,
	DIME = 10,
	NICK = 5,
	PENN = 1
};
ostream& operator<<(ostream& os, DENOMS d) {
	switch (d) {
		case HUND	: os << " Hundreds"; 	break;
		case FIFT	: os << " Fifties"; 	break;
		case TWEN	: os << " Twenties"; 	break;
		case TENS	: os << " Tens"; 		break;
		case FIVS	: os << " Fives"; 		break;
		case ONES	: os << " Ones"; 		break;
		case QUAR	: os << " Quarters"; 	break;
		case DIME	: os << " Dimes"; 		break;
		case NICK	: os << " Nickels"; 	break;
		case PENN	: os << " Pennies"; 	break;
		default		: os.setstate(ios_base::failbit);
	}
	return os;
}

void change(double amount) {
	int cash = int(amount*100);
	// We'll use greedy algorithm:
	int bills = 0;

	bills = floor(cash / HUND);
	cash = (cash - bills*HUND);
	cout << bills << HUND << endl;

	bills = floor(cash / FIFT);
	cash = cash - bills*FIFT;
	cout << bills << FIFT << endl;

	bills = floor(cash / TWEN);
	cash = cash - bills*TWEN;
	cout << bills << TWEN << endl;

	bills = floor(cash / TENS);
	cash = cash - bills*TENS;
	cout << bills << TENS << endl;	

	bills = floor(cash / FIVS);
	cash = cash - bills*FIVS;
	cout << bills << FIVS << endl;

	bills = floor(cash / ONES);
	cash = cash - bills*ONES;
	cout << bills << ONES << endl;

	bills = floor(cash / QUAR);
	cash = cash - bills*QUAR;
	cout << bills << QUAR << endl;

	bills = floor(cash / DIME);
	cash = cash - bills*DIME;
	cout << bills << DIME << endl;

	bills = floor(cash / NICK);
	cash = cash - bills*NICK;

	cout << cash << PENN << endl;



}

void P_2_2() {
	cout << "Change for $1001.00:\n";
	change(1001.00); cout << endl;
	cout << "Change for $0:\n";
	change(0); cout << endl;
	cout << "Change for $10:\n";
	change(10.00); cout << endl;
	cout << "Change for $.01:\n";
	change(0.01); cout << endl;
	cout << "Change for $1:\n";
	change(1); cout << endl;
	cout << "Change for $296.99:\n";
	change(296.99); cout << endl;

}

// P-2.3
class Complex {
public:
	Complex(double r = 0, double i = 0) : R(r), I(i) {};
public:
	friend std::ostream& operator<<(ostream& os, const Complex& obj) {
		os << obj.R << ((obj.I >= 0) ? "+" : "") << obj.I << 'i';
		return os;
	}
	friend Complex operator+(Complex lhs, const Complex& rhs) {
		lhs.R += rhs.R;
		lhs.I += rhs.I;
		return lhs;
	}
	friend Complex operator-(Complex lhs, const Complex& rhs) {
		lhs.R -= rhs.R;
		lhs.I -= rhs.I;
		return lhs;
	}
	friend Complex operator*(Complex lhs, const Complex& rhs) {
		// (lR + i*lI)*(rR + i*rI) = (lR*rR - lI*rI) + i*(lR*rI + lI*rR)
		lhs.R = lhs.R*rhs.R - lhs.I*rhs.I;
		lhs.I = lhs.R*rhs.I + lhs.I*rhs.R;
		return lhs;
	}
protected:
	double R;
	double I;
};

template <typename T>
class Vector{
public:
	Vector(int len = 0, int init = 0);
	Vector(vector<T> v);
	Vector(Complex c, int len = 1);
public:
	// Why can't I use prototypes here and the declaration later???
	friend ostream& operator<<(ostream& os, const Vector<T>& obj) {
		for (typename vector<T>::const_iterator it = obj.buffer.begin(); it != obj.buffer.end(); ++it) {
			os << *it << ' ';
		}
		return os;
	}

	friend Vector<T> operator+(Vector<T> lhs, const Vector<T>& rhs){
		assert(lhs.buffer.size() == rhs.buffer.size());
		typename std::vector<T>::iterator itL = lhs.buffer.begin();
		typename std::vector<T>::const_iterator itR = rhs.buffer.begin();
		for (; itL != lhs.buffer.end() || itR != rhs.buffer.end(); ++itL, ++itR) {
			*itL += *itR;
		}
		return lhs;
	}
	friend Vector<T> operator-(Vector<T> lhs, const Vector<T>& rhs) {
		assert(lhs.buffer.size() == rhs.buffer.size());
		typename std::vector<T>::iterator itL = lhs.buffer.begin();
		typename std::vector<T>::const_iterator itR = rhs.buffer.begin();
		for (; itL != lhs.buffer.end() || itR != rhs.buffer.end(); ++itL, ++itR) {
			*itL -= *itR;
		}
		return lhs;
	}
	friend Vector<T> operator*(Vector<T> lhs, const Vector<T>& rhs) {
		assert(lhs.buffer.size() == rhs.buffer.size());
		typename std::vector<T>::iterator itL = lhs.buffer.begin();
		typename std::vector<T>::const_iterator itR = rhs.buffer.begin();
		for (; itL != lhs.buffer.end() || itR != rhs.buffer.end(); ++itL, ++itR) {
			*itL *= *itR;
		}
		return lhs;
	}
	friend Vector<T> operator*(Vector<T> lhs, const T& rhs) {
		typename std::vector<T>::iterator itL = lhs.buffer.begin();
		for (; itL != lhs.buffer.end(); ++itL) {
			*itL = *itL * rhs;
		}
		return lhs;
	}
	// unsigned size() {return buffer.size();}
protected:
	std::vector<T> buffer;
};

template <typename T>
Vector<T>::Vector(int len, int init) {
	assert (init == 0 || init == 1);
	for (int i = 0; i < len; i++) {
		buffer.push_back(T(init));
	}
}
template <typename T>
Vector<T>::Vector(vector<T> v) {
	this->buffer = v;
}
template <typename T>
Vector<T>::Vector(Complex c, int len) {
	for (int i = 0; i < len; i++) {
		buffer.push_back(c);
	}
}


/*
template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& obj) {
	for (typename vector<T>::const_iterator it = obj.buffer.begin(); it != obj.buffer.end(); ++it) {
		os << *it << ' ';
	}
	return os;
}

template <typename T>
Vector<T> operator+(Vector<T> lhs, const Vector<T>& rhs) {
	assert(lhs.size() == rhs.size());
	for (typename vector<T>::iterator itL = lhs.buffer.begin(), itR = rhs.buffer.begin(); \
		itL != lhs.buffer.end() || itR != rhs.buffer.end(); 
		++itL, ++itR) {
		*itL += *itR;
	}
	return lhs;
}
*/

void P_2_3 () {
	Vector<int> *v1 = new Vector<int>(10, 0);
	Vector<int> *v2 = new Vector<int>(10, 1);
	cout << *v1 << endl;
	cout << *v2 << endl;

	cout << *v1 + *v2 << endl;

	Complex *c = new Complex(2, 3);
	Vector<Complex> *v3 = new Vector<Complex>(*c, 10);
	Complex *d = new Complex (-1, 4);
	cout << *v3 * *d << endl;
}

// P-2.5
class Polygon {
public:
	Polygon(double b = 0) : base(b) {};
	virtual ~Polygon() {};
public:
	virtual double area() = 0;
	virtual double perimeter() = 0;
protected:
	double base;
};

class Triangle : public Polygon {
public:
	Triangle(double A = 0.0, double B = 0.0, double C = 0) : a(A), b(B) {base = C;}
public:
	virtual double area ();
	virtual double perimeter ();
protected:
	double a;
	double b;
private:
	double ar;
	double per;
};

double Triangle::perimeter() {
	this->per = a+b+base;
	return per;
}

double Triangle::area() {
	double s = this->perimeter()/2;
	this->ar = sqrt(s*(s-a)*(s-b)*(s-base));
	return ar;
}

void P_2_5() {
	Triangle *t = new Triangle(3, 4, 5);
	cout << "The perimeter is: " << t->perimeter() << endl;
	cout << "The area is: " << t->area() << endl;
}

// P-2.6
short getLetter(char l) {
	if (l >= 'a' && l <= 'z') {
		return short(l - 'a');
	} else if (l >= 'A' && l <= 'Z') {
		return short(l - 'A');
	} else {
		return -1;
	}
}

void letterNum(int alphabet[26], ifstream& file) {
	string line;
	if (file.is_open()) {
		while (getline(file, line)) {
			for (int i = 0; i < line.length(); i++) {
				short num = getLetter(line[i]);
				if (num != -1) {
					alphabet[num]++;
				}
			}
		}
	}
}

void drawStars(int n) {
	for (int i = 0; i < n; i++)
		cout <<'*';
}

void drawHistNorm(const int alphabet[26]) {
	int total = 0;
	int max = 0;
	const int row = 48;
	// Get the total/max:
	for (int i = 0; i < 26; i++) {
		total += alphabet[i];
		if (max < alphabet[i]) max = alphabet[i];
	}
	
	cout << "Letter statistic (normalized)\n";
	for (int i = 0; i < 26; i++) {
		cout << char(i+'a') << ": ";
		printf("%.2f%%\t", alphabet[i]*100.0/total);
		// drawStars(alphabet[i]*1000/total);
		drawStars((alphabet[i]*row)/max);
		cout << endl;
	}
}

void drawHist(const int alphabet[26]) {
	cout << "Letter statistic (not normalized)\n";
	for (int i = 0; i < 26; i++) {
		cout << char(i+'a') << ":\t";
		drawStars(alphabet[i]);
		cout << endl;
	}
}

void P_2_6() {
	// Get the file name:
	string fName;
	cout << "Please, enter the file name: ";
	cin >> fName;
	// Get the letters:
	int alphabet[26] = {0};
	ifstream iFile (&(fName[0]));
	letterNum(alphabet, iFile);
	// drawHist(alphabet);	
	drawHistNorm(alphabet);
}

int main() {
	srand(time(NULL));
	cout << "\n*****************P-2.1*****************\n";
	P_2_1();
	cout << "\n*****************P-2.2*****************\n";
	P_2_2();
	cout << "\n*****************P-2.3*****************\n";
	P_2_3();
	cout << "\n*****************P-2.5*****************\n";
	P_2_5();
	cout << "\n*****************P-2.6*****************\n";
	P_2_6();


}


