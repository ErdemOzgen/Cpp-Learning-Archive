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
#include <stdexcept>

class B {};
class D : public B, public std::runtime_error {
 public:
    D() : std::runtime_error("runtime_error D") {}
};

int main(int argc, const char *argv[]) {
    D derived;

    try {
        throw derived;
    } catch (B &b) {
        std::cout << "Caught base class" << std::endl;
    } catch (D &d) {
        std::cout << "caught derived class" << std::endl;
        std::cout << d.what() << std::endl;
    }

    return 0;
}
