
//**********************************************************
// Author: D.S. Malik
//
// Implementation file dispenserTypeImp.cpp 
// This file contains the definitions of the functions to 
// implement the operations of the class dispenserType.
//**********************************************************
 
#include <iostream>
#include "dispenserType.h"

using namespace std;

int dispenserType::getNoOfItems() const
{
    return numberOfItems;
}

int dispenserType::getCost() const
{
    return cost;
}

void dispenserType::makeSale()
{
    numberOfItems--;
}

dispenserType::dispenserType()
{
    numberOfItems = 50;
    cost = 50;
}

dispenserType::dispenserType(int setNoOfItems, int setCost)
{
    if (setNoOfItems >= 0)
         numberOfItems = setNoOfItems;
    else    
        numberOfItems = 50;

    if (setCost >= 0)
        cost = setCost;
    else
        cost = 50;
}
