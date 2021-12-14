#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
class Vector {
  template<class U>
    friend istream& operator>>( istream&, Vector<U>&);

  template<class U>
    friend ostream& operator<<( ostream&, Vector<U>&);
private:
    T size;
    vector<T> vect;
public:
  template<class U>
    Vector(U Size) : size(Size) {
        for( size_t i=0; i<size; i++)
            vect.push_back(0);
    }
    ~Vector() {
        cout << "\nPoping back elements ...\n";
        typename std::vector<T>::iterator itr=vect.begin();
        while( !vect.empty() ) {
            vect.pop_back();
            cout << "Poping back element #" << *itr << "\n";
            itr++;
        }
        //this->print();
      }
  template<class U>
    void print() {
        typename std::vector<U>::iterator itr = vect.begin();
        size_t i=0;
        while( itr != vect.end() ) {
            cout << "Vec[" << i++ << "] = " <<  *itr << " ";
            itr++;
        }
        cout << endl;
    }
};

template<class U>
istream& operator>>( istream& is, Vector<U>& vect ) {
    cout << "Enter vector length: ";
    is   >> vect.size;
    U val;
    for( size_t i=0; i<vect.size; i++) {
        cout << "Enter element #" << i+1 << " : ";
        is >> val;
        vect.vect[i] = val;
    }
    return is;
}

template<class U>
ostream& operator<<( ostream& os, Vector<U>& vect ) {

    for( size_t i=0 ; i<vect.vect.size() ; i++ )
        os << "Vect[" << i << "] = " << vect.vect[i] << "\n";
    return os;
}


main()
{
    const int N = 5;

    Vector<int> vec(N);

    cin >> vec;
    cout << vec;
}
