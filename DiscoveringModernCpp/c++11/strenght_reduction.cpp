#include <iostream>
#include <cstdlib>
#include "print_compiler.hpp"

using namespace std;

int main (int argc, char* argv[]) 
{
    print_compiler();
    int i= 3;
    if (argc > 1) 
	i= atoi(argv[1]);

// Assembler code not in Visual Studio
#ifndef _MSC_VER
    asm ( "# start here" );
    int j= i / 64;
    asm ( "# end here" );
    cout << "j = " << j << endl;
#endif

    return 0;
}

