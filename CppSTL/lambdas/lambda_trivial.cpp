#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

/* a lambda function that returns the sum of a vector */
auto sum = [](const auto& vec) -> auto {
    auto s = 0.0;
    for( auto& elem: vec) { 
        s += elem;
    }
    return s;
};

template<class T>
class Matrix {
public:
    Matrix(vector<T>& vect) { setvec(vect); } 
    ~Matrix() { vec.clear(); }

    void setvec(vector<T>& source_vector) {
        typename vector<T>::iterator start = source_vector.begin();
        while(start != source_vector.end()) {
            vec.push_back(*start);
            start++;
        }
    }
    /* vector<T> */ auto Getvec() const { 
        return vec;
    }
private:
    vector<T> vec; 
};



int main()
{
    vector<int> vec{1,2,3,4,5};
    Matrix<int> m(vec);

    cout << "The sum of vec elements is : " << sum(m.Getvec()) << endl;

    return 0;
}
