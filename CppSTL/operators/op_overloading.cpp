#include <iostream>
#include <vector>

using namespace std;


class Matrix {
public:
    static Matrix newMatrix(int *arr, int sz) {
        return {arr, sz};
    }
    // Overload - operator for Objects of type class --> Matrix
    //
    Matrix operator-(Matrix &rhs) {
        int counter{0};
        // Create a temp Matrix Object and store the current object's values
        Matrix tmp = *this;
        while(counter != vec.size()) {
            tmp.vec.at(counter) = this->vec.at(counter) - rhs.vec.at(counter);
            counter++;
        }
        return tmp;
    }
    // Overload + operator for Objects of type class --> Matrix
    //
    Matrix operator+(Matrix &rhs) {
        int counter{0};
        // Create a temp Matrix Object and store the current object's values
        Matrix tmp = *this;
        while(counter != vec.size()) {
            tmp.vec.at(counter) = this->vec.at(counter) + rhs.vec.at(counter);
            counter++;
        }
        return tmp;
    }
    // Overload * Operator for Objects of type class --> Matrix
    //
    Matrix operator*(int multiplier) {
        int counter{0};
        Matrix tmp(*this);
        while(counter != vec.size()) {
            tmp.vec.at(counter) *= multiplier;
            counter++;
        }
        return tmp;
    }
    void print() {
        for(int i=0; i<vec.size(); i++) {
            cout << vec.at(i) << " ";
        }
        cout << endl;
    }
private:
    vector<int> vec{};
    Matrix(int *mat, int size)
    {
        int i{0};
        while(i != size) {
            vec.push_back(mat[i]);
            i++;
        }
    }
};


int main() 
{
    const int N = 5;
    int A[N] = {1,2,3,4,5};
    int B[N] = {11,22,33,44,55};

    Matrix m1 = Matrix::newMatrix(A, N);
    Matrix m2 = Matrix::newMatrix(B, N);
    cout << "m1 matrix : ";
    m1.print();
    cout << "m2 matrix : ";
    m2.print();

    cout << "m3 = m2 - m1 = ";
    Matrix m3 = m2 - m1;
    m3.print();

    cout << "m4 = m3 + m3 = ";
    Matrix m4 = m3 + m3;
    m4.print();

    cout << "m5 = m4*2 = ";
    Matrix m5 = m4*2;
    m5.print();

    return 0;
}
