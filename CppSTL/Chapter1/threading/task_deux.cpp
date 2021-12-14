#include <iostream>
#include <future>   // pair of a promise and a future
#include <vector>

using namespace std;

template<typename T>
T cube(T num) {
    return num*num*num;
}


int main()
{
    cout << "Threading using tasks ... \n\n";
    // vector of 21 tasks
    vector<future<int>> tasks(21);
    // Sum of cubes
    int sumOfCubes = 0;
    cout << "sum(";
    for(int i=0; i<21; i++)
    {
        tasks[i] = async(&cube<int>, i);
        sumOfCubes += tasks[i].get();
        if(i<20)    cout << sumOfCubes;
        cout << (i<19 ? " + " : "");
    }
    cout << ") = " << sumOfCubes << endl;

    return 0;
}
// Compilation :: g++ task_deux.cpp -lpthread -std=c++11 -o task_deux 