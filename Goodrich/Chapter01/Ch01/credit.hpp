
#ifndef CREDIT_CARD_H			// avoid repeated expansion
#define CREDIT_CARD_H

#include <string> 				// provides string
#include <iostream>				// provides ostream

class CreditCard { 
public:
	// constructor:
	CreditCard(const std::string& no, const std::string& nm, int lim, double bal=0);

	// accessors:
	std::string	getNumber() const	{return number;}
	std::string	getName() const 	{return name;}
	double getBalance() const 		{return balance;}
	int getLimit() const			{return limit;}
	
	bool chargeIt(double price);		// Make a charge
	void makePayment(double payment); 	// Make a payment
private:
// private member data 
std::string	number;				// credit card number 
std::string name;				// card owner’s name 
int 		limit;				// credit limit
double		balance;			// credit card balance
};

// printing:
std::ostream& operator<<(std::ostream& out, const CreditCard& c);
#endif