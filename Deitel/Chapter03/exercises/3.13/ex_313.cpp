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
#include <iostream>

#include "Invoice.hpp"

int main(int argc, const char *argv[]) {
    Invoice invoice1("12345", "Hammer", 12, 6);

    std::cout << "Part Number: " << invoice1.getPartNumber();
    std::cout << "\nPart Description: " << invoice1.getPartDescription();
    std::cout << "\n"
              << invoice1.getItemQuantity() << " x "
              << invoice1.getPricePerItem();
    std::cout << " = " << invoice1.getInvoiceAmount() << std::endl;

    return 0;
}
