#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <regex>
#include <set>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>

#include "progression.hpp"

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

class RuntimeException { // generic run-time exception 
private:
	string errorMsg; 
public:
	RuntimeException(const string& err = "Unknown Error!") { errorMsg = err; }
	string getMessage() const { return errorMsg; } 
};

class ParallelException : public RuntimeException {
public:
	ParallelException(const string& err) : RuntimeException(err) {}
};

// C-2.1
void C_2_1 () {
	cout << "// C-2.1\n \
void C_2_1 () {\n \
	cout << \"This program only outputs itself without the headers and stuff\";\n \
	cout << endl;\n \
}";
	cout << endl;
}

// C-2.3
void C_2_3 () {
	if (rand() % 100 > 100) {
		cout << "This is the part that might have something \"Useful\"";
	}
}

// C-2.4
class Line {
public:
	Line(double A = 1.0, double B = 0.0) : a(A), b(B) {}
	~Line() {};
	double intersect (const Line& l);
	void printParams();
public: // Easier access for now
	double a;
	double b;
};

void Line::printParams() {
	cout << a << ',' << b;
}

bool isParallel(Line A, Line B) {
	if (A.a == B.a) {
		throw ParallelException("Lines are parallel!");
		return true;
	} else {
		return false;
	}
}

double findXIntersect(Line A, Line B) {
	return ((B.b - A.b) / (A.a - B.a));
}

double Line::intersect(const Line& l) {
	try {
		if (!isParallel(*this, l))
			return findXIntersect(*this, l);
	} catch (ParallelException& pe) {
		cout << pe.getMessage() << endl;
	} catch (RuntimeException& re) {
		cout << re.getMessage() << endl;
	}
	return 0;
}

void C_2_4() {
	Line *lineA = new Line(2.1, 3.1);
	Line *lineB = new Line (2.1, 4.0);
	Line *lineC = new Line (1, 0);
	cout << '(';
	lineA->printParams(); cout << '+';
	lineB->printParams(); cout << ')';
	cout << ':';
	cout << lineA->intersect(*lineB) << endl;
	cout << '(';
	lineB->printParams(); cout << '+';
	lineC->printParams(); cout << ')';
	cout << ':';
	cout << lineB->intersect(*lineC) << endl;
	cout << '(';
	lineC->printParams(); cout << '+';
	lineA->printParams(); cout << ')';
	cout << ':';
	cout << lineC->intersect(*lineA) << endl;
}


// C-2.5
class AbsProgression : public Progression {
public:
	AbsProgression(long f = 2, long s = 200);
protected:
	virtual long firstValue();
	virtual long nextValue();
protected:
	long second;
	long prev;
};

AbsProgression::AbsProgression(long f, long s)
	: Progression(f), second(s), prev(abs(second + first)) {}

long AbsProgression::firstValue() {
	cur = first;
	prev = abs(second + first);
	return cur;
}

long AbsProgression::nextValue() {
	long temp = prev;
	prev = cur;
	cur = abs(cur - temp);
	return cur;
}

void C_2_5 () {
	Progression * prog;
	cout << "Absolute difference progression with default start:\n";
	prog = new AbsProgression();
	prog->printProgression(10);
}

// C-2.6
class SqrtProgression : public Progression {
public:
	SqrtProgression(double f = 65536) : first(f), cur(f) {}
protected:
	virtual long firstValue();
	virtual long nextValue();
protected:
	double first;
	double cur;
};

long SqrtProgression::firstValue() {
	cur = first;
	return long(cur);
}

long SqrtProgression::nextValue() {
	cur = sqrt(cur);
	return long(cur);
}

void C_2_6() {
	Progression * prog;
	cout << "Absolute difference progression with default start:\n";
	prog = new SqrtProgression(129);
	prog->printProgression(10);
}

// C-2.7
class A {
public:
	A(long X = 0) : x(X) {}
	long getX() {
		return this->x;
	}
	void setX(long x) {
		this->x = x;
	}
	virtual long getParentX() {return x;}
	virtual void setParentX(long x) {this->x = x;}
protected:
	long x;
};


class B : public A {
public:
	B(long X = 0) : x(X) {}
	long getX() {
		return this->x;
	}
	void setX(long x) {
		this->x = x;
	}
	virtual long getParentX() {
		return A::getX();
	}
	virtual void setParentX(long x) {
		A::setX(x);
	}
protected:
	long x;
};


class C : public B {
public:
	C(long X = 0) : x(X) {}
	long getX() {
		return this->x;
	}
	void setX(long x) {
		this->x = x;
	}
	virtual long getParentX() {
		return B::getX();
	}
	virtual void setParentX(long x) {
		B::setX(x);
	}
	void setGrandParentX(long x) {
		A::setX(x);
	}
protected:
	long x;
};

void C_2_7() {
	C *obj = new C(3);
	obj->setParentX(2);
	obj->setGrandParentX(1);

	cout << obj->getX() << endl;
	cout << obj->getParentX() << endl;
	cout << obj->B::getParentX() << endl;

	obj->A::setX(100);
	cout << obj->A::getX() << endl;
	cout << obj->B::getX() << endl;
	cout << obj->getX() << endl;
	
}

// C-2.8
// Prototypes:
class Packet;
class User;
class Internet;

class Packet {
public:
	Packet(User *r = NULL, User *s = NULL, string m = "")
		: message(m), recepient(r), sender(s) {}
public:
	string message;
	User *recepient;
	User *sender;
};

const Packet *emptyPacket = new Packet();
/*emptyPacket.recepient = NULL;
emptyPacket.sender = NULL;
emptyPacket.message = "";*/

// Classes:
class User {
public:
	User(bool r = false) : req(r) {};
public:
	bool push (Packet p);
	Packet pop (bool ready, bool ack);	// Once request comes, if the queue is not empty send packet and wait for ack
	bool requestTx () {return req;}
	void addMessage(User * u, string message);
protected:
	queue<Packet> txMessages;		// Has to be FIFO
	vector<Packet> rxMessages;		// Order doesn't matter
	bool req;

};

bool User::push(Packet p) {
	rxMessages.push_back(p);
	return true;	// Tell everyone that the message was received
}

Packet User::pop(bool ready, bool ack) {
	if (this->req == false) {
		return *emptyPacket;
	}
	// If Internet is requesting the data
	if (ready && !txMessages.empty()) {
		// and previous data was received:
		if (ack) {
			// remove the current, and return the next:
			txMessages.pop();
			if (txMessages.empty()) {
				this->req = 0;
				return *emptyPacket;
			}
		}
		return txMessages.front();
	} else {
		this->req = 0;
		return *emptyPacket;
	}
}

class Internet {
public:
	Internet (bool r = true) : req(r) {};
	virtual void process();	// Constantly monitors users
	void addUser(User * u) {users.push_back(u);}
public:
	bool req;		// request for packets
	vector<User*> users;
};

void Internet::process() {
	while (true) {	// Constantly monitor
		// Scan through users:
		for (vector<User*>::iterator it = users.begin(); it != users.end(); ++it) {
			// Check if there is something to transmitt:
			while ((*it)->requestTx()) {
				// try poping:
				bool ack = false;
				Packet p;
				do {
					p = (*it)->pop(true, ack);
					ack = p.recepient->push(p);
				} while (!ack);
			}
		}
	}
}

// C-2.9
vector<string> getElements(string formula) {
	string temp;
	vector<string> elements;
	temp = formula[0];
	for (int i = 1, len = formula.length(); i < len; i++) {
		// No spaces:
		if (formula[i] == ' ' || formula[i] == '\t') {
			continue;
		} else if (formula[i] == '+' || formula[i] == '-') {
			elements.push_back(temp);
			temp = formula[i];
		} else {
			temp = temp + formula[i];
		}
	}
	elements.push_back(temp);
	return elements;
}

int getCoeff(string element, char var) {
	// int coeff;
	int i = 0;
	string coeff = "";
	while (element[i] != var) {
		coeff += element[i];
		i++;
	}
	//cout << "\n*** " << coeff << " ***\n";
	// cout << "c: " << coeff << endl;
	if (coeff == "+") {
		return 1;
	} else if (coeff == "-") {
		return -1;
	}else {
		return atoi(coeff.c_str());
	}
}

int getPower(string element, char var) {
	// Find the variable:
	int i = 0;
	string power = "";
	int len = element.length();
	while (element[i] != var) {
		i++;
	}
	i++;
	if (element[i] != '^')
		return 1;
	else {
		while (i < len) {
			i++;
			power += element[i];
		}
	}
	// cout << "p: " << power << endl;
	return atoi(power.c_str());
}

string elementDerivative(string element, string var) {
	int coeff, power;
	string buffer = "";
	char charBuf[33];
	coeff = getCoeff(element, var[0]);
	power = getPower(element, var[0]);
	// cout << coeff << ' ' << power << endl;
	coeff *= power;
	power--;

	//cout << ((coeff >= 0) ? "+" : "") <<  coeff << var << '^' << power;

	if (power == -1)
		buffer = "";
	else {
		// Coefficient first:
		sprintf(charBuf,"%d",coeff);
		// itoa(coeff, charBuf, 10)
		buffer += (coeff >= 0) ? "+" : "";
		buffer += string(charBuf);
		// power:
		sprintf(charBuf,"%d",power);
		// itoa(power, charBuf, 10);
		buffer += (power == 0) ? "" :
			"*" + var + ((power == 1) ? "" : "^"+string(charBuf));
		}

	return buffer;
	//cout << "";
}

std::ostream& operator<<(std::ostream& os, const vector<string>& obj) {
	os << "{ ";
	for (vector<string>::const_iterator it = obj.begin(); it != obj.end(); ++it) {
		os << *it << ' ';
	}
	os << '}';
	return os;
}

void derivate(string polynomial, string var) {
	vector<string> el = getElements(polynomial);
	// cout << el << ": ";
	cout << polynomial << ":\n\t";
	for (vector<string>::iterator it = el.begin(); it != el.end(); ++it) {
		cout << elementDerivative(*it, var);
	}
}

void C_2_9() {
	string poly;

	poly = "x^2 - 3*x";
	derivate (poly, "x"); cout << endl;

	poly = "3 + 2*x + x^2";
	derivate (poly, "x"); cout << endl;
}

int main() {
	srand (time(NULL));
	cout << "*****************C-2.1*****************\n";
	C_2_1();
	cout << "*****************C-2.3*****************\n";
	C_2_3();
	cout << "*****************C-2.4*****************\n";
	C_2_4();
	cout << "*****************C-2.5*****************\n";
	C_2_5();
	cout << "*****************C-2.6*****************\n";
	C_2_6();
	cout << "*****************C-2.7*****************\n";
	C_2_7();
	cout << "*****************C-2.8*****************\n";
	cout << "C-2.8 Code ready, Simulator is not :)\n";
	cout << "*****************C-2.9*****************\n";
	C_2_9();
}




