//
// Created by Samuel Martins on 2019-04-22.
//

#ifndef VECTOR_EXAMPLE_LISTCONTAINER_H
#define VECTOR_EXAMPLE_LISTCONTAINER_H

#include <iostream>
#include <initializer_list>
#include <list>

#include "container.h"


class ListContainer : public Container {
private:
    std::list<double> ld; // (standard-library) list of doubles (§11.3)
    
public:
    ListContainer() { } // empty List
    
    ListContainer(std::initializer_list<double> il) : ld{il} { }
    
    ~ListContainer() {
        std::cout << "calling ListContainer destructor\n";
    }
    
    
    double& operator[](int i) override;
    
    int size() const override {
        return ld.size();
    }
};


#endif //VECTOR_EXAMPLE_LISTCONTAINER_H
