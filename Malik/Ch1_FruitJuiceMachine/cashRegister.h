
//************************************************************
// Author: D.S. Malik
// 
// class cashRegister
// This class specifies the members to implement a cash 
// register.
//************************************************************
  
class cashRegister
{
public:
    int getCurrentBalance() const;
       //Function to show the current amount in the cash 
       //register.
       //Postcondition: The value of cashOnHand is returned.

    void acceptAmount(int amountIn);
       //Function to receive the amount deposited by 
       //the customer and update the amount in the register.
       //Postcondition: cashOnHand = cashOnHand + amountIn;

    cashRegister(); 
       //Default constructor
       //Sets the cash in the register to 500 cents.
       //Postcondition: cashOnHand = 500.

    cashRegister(int cashIn); 
       //Constructor with a parameter.
       //Sets the cash in the register to a specific amount.
       //Postcondition: cashOnHand = cashIn;

private:
     int cashOnHand;     //variable to store the cash 
                         //in the register
};
