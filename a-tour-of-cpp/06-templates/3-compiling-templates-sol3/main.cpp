#include <iostream>
#include <list>

#include "vector.h"
#include "vector.cpp" // added here as part of the solution


int main() {
    // Usually, we split declarations and definitions in header (.h) and source file (.cpp) separately.
    // Then we compile the source file to generate an object file (.o)
    // When compiling a new source file that uses the other one, we just use its object file (.o) and its header file (.h).
    // Thus, the compiler does not know details about implementations during this compilation.

    // However, this does not work for Template classes/functions.
    
    // To correctly compile/link a source file (like the current one) that uses/includes a header file with
    // template functions, the compiler needs to know the both declarations and definitions during this compilation.
    // We have some solutions for that.
    
    // ### Solution 3 ###
    // We put the definitions in a separated source file (.cpp) and then we include it into all files that use its functions.
    // For the current source file, we have a #include "vector.cpp"
    // Thus, all content of vector.cpp is included here!
    // cons:
    // We will not always have access to the source files with the definitions/implementations.
    // Moreover, we could have the same problems of Solution #1
    
    // See a more complete explanation on:
    // https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
    // https://www.codeproject.com/Articles/48575/How-to-define-a-template-class-in-a-h-file-and-imp
    
    Vector<int> v(100);
    v[0] = 10;
    std::cout << "v[0] = " << v[0] << std::endl;
    
    Vector<char> vc(200);
    vc[0] = 'A';
    std::cout << "vc[0] = " << vc[0] << std::endl;
    
    Vector<double> vd(200);
    vd[0] = 2.5;
    std::cout << "vd[0] = " << vd[0] << std::endl;
    
    Vector<std::string> vs(17);
    vs[0] = "A Tour of C++";
    std::cout << "vs[0] = " << vs[0] << std::endl;
    
    Vector<std::list<int>> vli(45);
    
    
    return 0;
}