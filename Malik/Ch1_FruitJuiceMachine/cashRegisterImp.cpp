
//**********************************************************
// Author: D.S. Malik
//
// Implementation file cashRegisterImp.cpp 
// This file contains the definitions of the functions to 
// implement the operations of the class cashRegister. 
//**********************************************************
  
#include <iostream>
#include "cashRegister.h"

using namespace std;

int cashRegister::getCurrentBalance() const
{
    return cashOnHand;
}

void cashRegister::acceptAmount(int amountIn)
{
    cashOnHand = cashOnHand + amountIn;
}

cashRegister::cashRegister()
{
    cashOnHand = 500;
}

cashRegister::cashRegister(int cashIn)
{
    if (cashIn >= 0)
        cashOnHand = cashIn;
    else
        cashOnHand = 500;
}
