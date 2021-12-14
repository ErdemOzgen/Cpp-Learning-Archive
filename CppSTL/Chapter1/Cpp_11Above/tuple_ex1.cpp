#include <iostream>
#include <tuple>

using namespace std;

tuple<int, int, int> myTuple(int num)
{
    int square = num*num;
    int cube = square*num;
    int quad = cube*num;
    return make_tuple(square, cube, quad);
}


int main()
{
    for(int i=1; i<11; i++)
    {
        cout << i << "^2 = " << get<0>(myTuple(i)) << "\t\t"
             << i << "^3 = " << get<1>(myTuple(i)) << "\t\t"
             << i << "^4 = " << get<2>(myTuple(i)) << "\n";
    }

    return 0;
}
/* OUTPUT

1^2 = 1		1^3 = 1		1^4 = 1
2^2 = 4		2^3 = 8		2^4 = 16
3^2 = 9		3^3 = 27		3^4 = 81
4^2 = 16		4^3 = 64		4^4 = 256
5^2 = 25		5^3 = 125		5^4 = 625
6^2 = 36		6^3 = 216		6^4 = 1296
7^2 = 49		7^3 = 343		7^4 = 2401
8^2 = 64		8^3 = 512		8^4 = 4096
9^2 = 81		9^3 = 729		9^4 = 6561
10^2 = 100		10^3 = 1000		10^4 = 10000

*/