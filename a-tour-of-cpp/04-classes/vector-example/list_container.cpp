//
// Created by Samuel Martins on 2019-04-22.
//

#include "list_container.h"

#include <stdexcept>      // std::out_of_range


// we cannot put override in the implementation, only in the definition
double& ListContainer::operator[](int i) {
    for (auto& x : ld) {
        if (i == 0)
            return x;
    --i;
    }
    throw std::out_of_range{"List Container"};
}
