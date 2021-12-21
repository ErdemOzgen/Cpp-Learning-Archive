#pragma once
#include <string>				// provides string
#include <iostream>				// provides ostream

class CreditCard {
public:
  CreditCard(const std::string& no,		// constructor
  	const std::string& nm, int lim, double bal=0);
  						// accessor functions
  std::string   getNumber() const	{ return number; }
  std::string   getName() const		{ return name; }
  double   	getBalance() const	{ return balance; }
  int      	getLimit() const	{ return limit; }

  bool chargeIt(double price); 			// make a charge 
  void makePayment(double payment);		// make a payment
private:                                	// private member data
  std::string   number;				// credit card number
  std::string   name;				// card owner's name
  int       	limit;				// credit limit
  double    	balance;			// credit card balance
};
  						// print card information
std::ostream& operator<<(std::ostream& out, const CreditCard& c);
