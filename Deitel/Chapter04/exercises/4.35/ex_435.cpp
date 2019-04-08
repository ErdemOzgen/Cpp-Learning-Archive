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
#include "EncryptionSystem.hpp"

int main(int argc, const char *argv[]) {
    EncryptionSystem es;

    int code = 0;

    std::cout << "Welcome to encryption/decryption system\n" << std::endl;
    std::cout << "Enter a 4 digit pass code to be encrypted: ";
    std::cin >> code;

    es.encrypt(code);

    std::cout << "\nEncrypted pass code: " << es.getEncPass() << "\n" << std::endl;

    std::cout << "Decrypted pass code: " << es.decrypt() << std::endl;

    return 0;
}
