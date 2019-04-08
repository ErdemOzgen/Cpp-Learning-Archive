/*
 * =====================================================================================
 *
 *       Filename:  
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thanks to github you know it
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author: Mahmut Erdem ÖZGEN   m.erdemozgen@gmail.com
 *   
 *
 * =====================================================================================
 */
#pragma once

#include <string>

class Invoice {
 private:
    std::string partNumber;
    std::string partDescription;

    int itemQuantity;
    int pricePerItem;

 public:
    Invoice(const std::string &, const std::string &, int, int);

    // SETTERS
    void setPartNumber(const std::string &);
    void setPartDescription(const std::string &);
    void setItemQuantity(int);
    void setPricePerItem(int);

    // GETTERS
    std::string getPartNumber() const;
    std::string getPartDescription() const;
    int getItemQuantity() const;
    int getPricePerItem() const;

    int getInvoiceAmount() const;
};
