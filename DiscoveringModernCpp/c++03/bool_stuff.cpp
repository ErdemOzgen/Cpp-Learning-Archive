#include <iostream>
#include <typeinfo>

using namespace std;

int main (int argc, char* argv[]) 
{
    // Examples of (probably) unexpected behavior. Better not running it.
    cout << boolalpha << "! 2>3 = " << (! 2>3) 
	 << "\n!(2 > 3) = " << !(2 > 3) << "\n"
	 << "!2 + 3 = " << !2 + 3 << "\n"
	 << typeid(!2 > 3).name() << "\n";

    return 0;
}
