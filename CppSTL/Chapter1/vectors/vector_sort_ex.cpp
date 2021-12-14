#include <cstdlib>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

void show(const char* msg, vector<int> vect) {
    cout << msg;
    for(unsigned i=0; i<vect.size(); i++) {
        cout << vect[i] << " " ;
    }
    cout << endl;
}

int main()
{
    vector<int> v(10);

    for(unsigned i=0;i<v.size();++i)
        v[i] = rand() % 100;

    show("Original order: \n", v);
    cout << endl;

    sort(v.begin(), v.end());
    show("Order after sorting int onatural order:\n", v);
    cout << endl;

    sort(v.begin(), v.end(), greater<int>());

    show("Order after sorting into descending order:\n", v);
    cout << endl;

    return 0;
}
