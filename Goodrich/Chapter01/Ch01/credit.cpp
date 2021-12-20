#include "credit.hpp"	// Credit card data structure

using namespace std;	// std::

// Create some more credit structures:
CreditCard::CreditCard(const string& no, const string& nm, int lim, double bal) {
	this->number = no;
	this->name = nm;
	this->limit = lim;
	this->balance = bal;
}

bool CreditCard::chargeIt (double price) {
	if (price + balance > double(limit)) {
		return false;
	} else {
		balance += price;
		return true;
	}
}

void CreditCard::makePayment (double payment) {
	balance -= payment;
}

ostream& operator<<(ostream& out, const CreditCard& c) {
	out	<< "Number = " << c.getNumber() << endl
		<< "Name = " << c.getName() << endl
		<< "Balance = " << c.getBalance() << endl
		<< "Limit = " << c.getLimit() <<endl;
	return out;
}