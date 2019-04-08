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

class Count {
    friend void setX(Count &, int);

 public:
    Count() : x(0) {}
    ~Count() {}

    // output x
    void print() const { std::cout << x << std::endl; }

 private:
    int x;
};
// function setX can modify private data of Count
// because setX is declared as a friend of Count
void setX(Count &c, int val) { c.x = val; }

int main(int argc, const char *argv[]) {
    Count counter;

    std::cout << "counter.x after instantiation: ";
    counter.print();

    setX(counter, 8);
    std::cout << "counter.x after call to setX friend function: ";
    counter.print();

    return 0;
}
