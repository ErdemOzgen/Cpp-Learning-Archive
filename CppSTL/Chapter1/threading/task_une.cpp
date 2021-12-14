#include <iostream>
#include <future>   // pair of a promise and a future

using namespace std;

template<typename T>
T cube(T num) {
    return num*num*num;
}


int main()
{
    cout << "Threading using tasks ... \n\n";
    for(int i=1; i<11; i++)
    {
        auto task1 = async(&cube<int>, i);
        int numCubed = task1.get();
        cout << i << "^3 = " << numCubed << endl;
    }

    return 0;
}
// Compilation :: g++ task_une.cpp -lpthread -std=c++11 -o task_une 