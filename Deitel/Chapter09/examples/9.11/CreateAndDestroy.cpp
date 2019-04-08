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
#include "CreateAndDestroy.hpp"

CreateAndDestroy::CreateAndDestroy(int ID, std::string messageString) {
    objectID = ID;
    message = messageString;

    std::cout << "Object " << objectID << "  constructor runs  " << message
              << std::endl;
}
CreateAndDestroy::~CreateAndDestroy() {
    std::cout << (objectID == 1 || objectID == 6 ? "\n" : "");

    std::cout << "Object " << objectID << "  destructor runs  " << message
              << std::endl;
}
