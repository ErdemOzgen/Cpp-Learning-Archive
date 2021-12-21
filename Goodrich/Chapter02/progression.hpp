#ifndef PROGRESSION_H
#define PROGRESSION_H

using namespace std;

// Base class:
class Progression {
public:
	Progression (long f = 0) : first(f), cur(f) {}
	virtual ~Progression() {};
	void printProgression(int n);
protected:
	virtual long firstValue();		// reset
	virtual long nextValue() = 0;		// advance
protected:
	long first;
	long cur;
};

void Progression::printProgression(int n) {
	cout << firstValue();
	for (int i = 2; i <= n; i++) {
		cout << ' ' << nextValue();
	}
	cout << endl;
}

long Progression::firstValue() {
	cur = first;
	return cur;
}
long Progression::nextValue() {
	return ++cur;
}

// Arithmetic subclass:
class ArithProgression : public Progression {
public:
	ArithProgression(long i = 1);
protected:
	virtual long nextValue();
protected:
	long inc;	// increment
};

// Constructor:
ArithProgression::ArithProgression(long i) : Progression(), inc(i) {}

// advance by adding:
long ArithProgression::nextValue() {
	cur += inc;
	return cur;
}

// Geometric subclass
class GeomProgression : public Progression{
public:
	GeomProgression(long b = 2);
protected: 
	virtual long nextValue();
protected:
	long base;
};

// constructor
GeomProgression::GeomProgression(long b) : Progression(1), base(b) {} 

long GeomProgression::nextValue() {
	cur *= base;
	return cur;
}

// Fibonacci subclass:
class FibonacciProgression : public Progression {
public:
	FibonacciProgression(long f = 0, long s = 1);
protected:
	virtual long firstValue();
	virtual long nextValue();
protected:
	long second;
	long prev;
};

FibonacciProgression::FibonacciProgression(long f, long s)
	: Progression(f), second(s), prev(second-first) {}

long FibonacciProgression::firstValue() {
	cur = first;
	prev = second - first;
	return cur;
}

long FibonacciProgression::nextValue() {
	long temp = prev;
	prev = cur;
	cur += temp;
	return cur;
}



#endif