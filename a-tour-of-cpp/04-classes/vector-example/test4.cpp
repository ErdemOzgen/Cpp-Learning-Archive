#include <iostream>

#include "vector_container.h"
#include "list_container.h"


void use(Container& c) {
    std::cout << "using\n";
    for (long i = 0; i < c.size(); i++)
        std::cout << "[" << i << "] = " << c[i] << std::endl;
    
    c.xpto(); // it always calls the 'xpto' of Container because it is not virtual.
    std::cout << "\n";
}


void useVectorContainer() {
    std::cout << "useVectorContainer\n";
    
    VectorContainer vc(5);
    for (long i = 0; i < vc.size(); i++)
        vc[i] = i;
    
    use(vc);
    vc.xpto(); // it calls the 'xpto' of Vector
}


void useListContainer() {
    std::cout << "useListContainer\n";
    
    ListContainer lc = {0, 1, 2, 3, 4};
    use(lc);
}


int main() {
    useVectorContainer();
    std::cout << "\n";
    useListContainer();
    
    return 0;
}
