
//************************************************************
// Author: D.S. Malik
// 
// class dispenserType
// This class specifies the members to implement a dispenser.
//************************************************************
  
class dispenserType
{
public:
    int getNoOfItems() const; 
      //Function to show the number of items in the machine.
      //Postcondition: The value of numberOfItems is returned.

    int getCost() const; 
      //Function to show the cost of the item.
      //Postcondition: The value of cost is returned.

    void makeSale();  
      //Function to reduce the number of items by 1.
      //Postcondition: numberOfItems--;

    dispenserType(); 
      //Default constructor 
      //Sets the cost and number of items in the dispenser
      //to 50.
      //Postcondition: numberOfItems = 50; cost = 50;

    dispenserType(int setNoOfItems, int setCost); 
      //Constructor with parameters 
      //Sets the cost and number of items in the dispenser
      //to the values specified by the user.
      //Postcondition: numberOfItems = setNoOfItems;
      //               cost = setCost;


private:
    int numberOfItems;     //variable to store the number of 
                           //items in the dispenser
    int cost;  //variable to store the cost of an item
};
