#include <iostream>
#include <vector>

#include <algorithm> // trasnform function

using namespace std;

template<class T>
T SQRT(T num) {
    return (num<=0) ? 0 : num*num;
}

template<class T>
T CUBE(T num) {
    return (num<=0) ? 0 : num*num*num; 
}

template<class T>
void PRINT(const vector<T> &vec) {
    for(const auto & v : vec)
        cout << v << " ";
    cout << endl;
}

template<class type>
void Transform(vector<type> &vec, size_t operation = 0) {
    switch(operation)
    {
        case 0:
            transform(vec.begin(), vec.end(), vec.begin(), SQRT<type>);
            PRINT<type>(vec);
            break;
        case 1:
            transform(vec.begin(), vec.end(), vec.begin(), CUBE<type>);
            PRINT<type>(vec);
            break;
        default:
            cout << "Choose square root OR cube operations only...\n";
            break;
    }
}

int main()
{
    vector<int> nums{1,2,3,4,5,6,7,8,9,10};
    cout << "Nums vector:\n";
    PRINT<int>(nums);
    cout << "Nums vector squared:\n";
    Transform<int>(nums);
    cout << "Nums vector squared-squared:\n";
    Transform<int>(nums, 1);


    return 0;
}