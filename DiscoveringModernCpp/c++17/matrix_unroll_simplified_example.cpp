// Example program for Discovering Modern C++
//
// File: matrix_unroll_example.cpp
// Date: 2020-03-09

#include <iostream>
#include <chrono>
#include <cassert>

using namespace std;
using namespace std::chrono;
using TP= time_point<steady_clock>;


namespace dmc {

template <typename Value>
class matrix 
{
  public:
    using value_type= Value;

    matrix() : nrows(0), ncols(0), data(0) {}

    matrix(int nrows, int ncols) 
      : nrows(nrows), ncols(ncols), data( new value_type[nrows * ncols] ) {}

    matrix(const matrix& that) 
      : nrows(that.nrows), ncols(that.ncols), data(new value_type[nrows * ncols])
    {
	for (int i= 0, size= nrows*ncols; i < size; ++i)
	    data[i]= that.data[i];
    }

    ~matrix() { if(data) delete [] data; }

    void operator=(const matrix& that) 
    {
	assert(nrows == that.nrows && ncols == that.ncols);
	for (int i= 0, size= nrows*ncols; i < size; ++i)
	    data[i]= that.data[i]; 
    }

    int num_rows() const { return nrows; }
    int num_cols() const { return ncols; }

  private:
    void check(int r, int c) const { assert(0 <= r && r < nrows && 0 <= c && c <= ncols); }
  public:
    value_type& operator()(int r, int c) 
    { 
	check(r, c); 
	return data[r*ncols + c]; 
    }
    const value_type& operator()(int r, int c) const 
    { 
	check(r, c); 
	return data[r*ncols + c]; 
    }
  private:
    int     nrows, ncols;
    value_type* data;
};

template <typename Value>
std::ostream& operator<<(std::ostream& os, const matrix<Value>& A)
{
    for (int r= 0; r < A.num_rows(); r++) {
	os << '[';
	for (int i= 0; i < A.num_cols(); ++i) 
	    os << A(r, i) << (i+1 < A.num_cols() ? "  " : "");
	os << "]\n";
    }
    return os;
}


template <unsigned BSize, typename Value>
struct multi_tmp
{
    static const unsigned bs= BSize;
    using sub_type= multi_tmp<BSize-1, Value>;

    multi_tmp(const Value& v) : value(v), sub(v) {}
    Value     value;
    sub_type  sub;
};

template <typename Value>
struct multi_tmp<0, Value>
{
    multi_tmp(const Value& v) {}
};


template <typename Matrix>
inline void mult(const Matrix& A, const Matrix& B, Matrix& C)
{
    assert(A.num_cols() == B.num_rows()); // ...

    using value_type= typename Matrix::value_type;
    unsigned s= A.num_rows();
    
    for (unsigned i= 0; i < s; i++)
	for (unsigned k= 0; k < s; k++) {
	    value_type tmp(0);
	    for (unsigned j= 0; j < s; j++)
		tmp+= A(i, j) * B(j, k);
	    C(i, k)= tmp;
	}
}



template <typename Matrix>
inline void mult4(const Matrix& A, const Matrix& B, Matrix& C)
{
    assert(A.num_cols() == B.num_rows()); // ...
    assert(A.num_rows() % 4 == 0);       // we omit cleanup here 
    assert(A.num_cols() % 4 == 0);       // we omit cleanup here 

    using value_type= typename Matrix::value_type;
    unsigned s= A.num_rows();
    
    for (unsigned i= 0; i < s; i+= 4)
	for (unsigned k= 0; k < s; k+= 4) {
            value_type array[4][4]= {};
	    for (unsigned j= 0; j < s; j++) {
                array[0][0]+= A(i+0, j) * B(j, k+0);
                array[0][1]+= A(i+0, j) * B(j, k+1);
                array[0][2]+= A(i+0, j) * B(j, k+2);
                array[0][3]+= A(i+0, j) * B(j, k+3);
                array[1][0]+= A(i+1, j) * B(j, k+0);
                array[1][1]+= A(i+1, j) * B(j, k+1);
                array[1][2]+= A(i+1, j) * B(j, k+2);
                array[1][3]+= A(i+1, j) * B(j, k+3);
                array[2][0]+= A(i+2, j) * B(j, k+0);
                array[2][1]+= A(i+2, j) * B(j, k+1);
                array[2][2]+= A(i+2, j) * B(j, k+2);
                array[2][3]+= A(i+2, j) * B(j, k+3);
                array[3][0]+= A(i+3, j) * B(j, k+0);
                array[3][1]+= A(i+3, j) * B(j, k+1);
                array[3][2]+= A(i+3, j) * B(j, k+2);
                array[3][3]+= A(i+3, j) * B(j, k+3);
            } 
            C(0, 0)= array[0][0];
            C(0, 1)= array[0][1];
            C(0, 2)= array[0][2];
            C(0, 3)= array[0][3];
            C(1, 0)= array[1][0];
            C(1, 1)= array[1][1];
            C(1, 2)= array[1][2];
            C(1, 3)= array[1][3];
            C(2, 0)= array[2][0];
            C(2, 1)= array[2][1];
            C(2, 2)= array[2][2];
            C(2, 3)= array[2][3];
            C(3, 0)= array[3][0];
            C(3, 1)= array[3][1];
            C(3, 2)= array[3][2];
            C(3, 3)= array[3][3];
        }
}




template <unsigned Index0, unsigned Index1, unsigned Max>
struct mult_block
{
    using next= mult_block<Index0, Index1+1, Max>;
    using next_row= mult_block<Index0+1, 0, Max>;

    template <typename Tmp, typename Matrix>
    void operator()(Tmp& tmp, const Matrix& A, const Matrix& B, unsigned i, unsigned j, unsigned k)
    {
	// std::cout << "tmp." << tmp.bs << "+= A[" << i + Index0 << "][" << j << "] * B[" << j << "][" << k + Index1 << "]\n";
	tmp[Index0][Index1]+= A(i + Index0, j) * B(j, k + Index1);
        if constexpr(Index1 < Max) {
            next{}(tmp, A, B, i, j, k);
        } else {
            if constexpr(Index0 < Max) 
                next_row{}(tmp, A, B, i, j, k);
        }            
    }

    template <typename Tmp, typename Matrix>
    void update(const Tmp& tmp, Matrix& C, unsigned i, unsigned k)
    {
	// std::cout << "C[" << i + Index0 << "][" << k + Index1 << "]= tmp." << tmp.bs << "\n";
	C(i + Index0, k + Index1)= tmp[Index0][Index1];
        if constexpr(Index1 < Max) {
            next{}.update(tmp, C, i, k);
        } else {
            if constexpr(Index0 < Max) 
                next_row{}.update(tmp, C, i, k);
        }
    }
};


template <unsigned Size, typename Matrix>
inline void mult(const Matrix& A, const Matrix& B, Matrix& C)
{
    assert(A.num_cols() == B.num_rows()); // ...
    assert(A.num_rows() % Size == 0);       // we omit cleanup here 
    assert(A.num_cols() % Size == 0);       // we omit cleanup here 

    using value_type= typename Matrix::value_type;
    unsigned s= A.num_rows();
    mult_block<0, 0, Size-1> block;
    
    for (unsigned i= 0; i < s; i+= Size)
	for (unsigned k= 0; k < s; k+= Size) {
            value_type array[Size][Size]= {};
	    for (unsigned j= 0; j < s; j++)
		block(array, A, B, i, j, k);
	    block.update(array, C, i, k);
	}
}

#if 0
template <typename Matrix>
inline void mult(const Matrix& A, const Matrix& B, Matrix& C, constexpr unsigned Size= 4)
{
    using value_type= typename Matrix::value_type;
    unsigned s= A.num_rows();
    
    for (unsigned i= 0; i < s; i+= Size)
	for (unsigned k= 0; k < s; k+= Size) {
            value_type array[Size][Size]= {};
	    for (unsigned j= 0; j < s; j++) { 
                for constexpr (unsigned Index0= 0; Index0 < Size; ++Index0)
                    for constexpr (unsigned Index1= 0; Index1 < Size; ++Index1)
                        tmp[Index0][Index1]+= A(i + Index0, j) * B(j, k + Index1);
                }
            for constexpr (unsigned Index0= 0; Index0 < Size; ++Index0)
                for constexpr (unsigned Index1= 0; Index1 < Size; ++Index1)
                    C(i + Index0, k + Index1)= tmp[Index0][Index1];
    }    
}
#endif


inline double duration_s(const TP& from, const TP& to, unsigned rep)
{
    return duration_cast<nanoseconds>((to - from) / rep).count() / 1e9;
}


template <typename Matrix>
void bench(const Matrix& A, const Matrix& B, Matrix& C, const unsigned rep)
{
    TP t1= steady_clock::now();      
    for (unsigned j= 0; j < rep; j++)
	mult(A, B, C);
    TP t2= steady_clock::now(); 
    double t= duration_s(t1, t2, rep);
    unsigned s= A.num_rows();

    std::cout << "Time mult is " 
	      << 1000000.0 * t << " mmicros. This are "
	      << s * s * (2*s - 1) / t / 1000000.0 << " MFlops.\n";
    if (s < 10)
	std::cout << "C is " << C << '\n';
}

template <unsigned Size, typename Matrix>
void bench_unroll(const Matrix& A, const Matrix& B, Matrix& C, const unsigned rep)
{
    TP t1= steady_clock::now();      
    for (unsigned j= 0; j < rep; j++)
	mult<Size>(A, B, C);
    TP t2= steady_clock::now(); 
    double t= duration_s(t1, t2, rep);
    unsigned s= A.num_rows();

    std::cout << "Time mult<" << Size << "> is " 
	      << 1000000.0 * t << " mmicros. This are "
	      << s * s * (2*s - 1) / t / 1000000.0 << " MFlops.\n";
    if (s < 10)
	std::cout << "C is\n" << C << '\n';
}


} // namespace dmc

int main()
{
    using namespace dmc;

    const unsigned s= 4;  // s= 4 for testing and 128 for timing
    matrix<float> A(s, s), B(s, s), C(s, s);
    // matrix<double> A(s, s), B(s, s), C(s, s);

    for (unsigned i= 0; i < s; i++) 
	for (unsigned j= 0; j < s; j++) {
	    A(i, j)= 100.0 * i + j;
	    B(i, j)= 200.0 * i + j;
	}

    mult(A, B, C);
    if (s < 10)
	std::cout << "C is " << C << '\n';

    mult<4>(A, B, C);
    if (s < 10)
	std::cout << "C is " << C << '\n';

    const unsigned rep= 100;
    bench(A, B, C, rep);
    
    bench_unroll<1>(A, B, C, rep);
    bench_unroll<2>(A, B, C, rep);
    bench_unroll<4>(A, B, C, rep);
    if (s > 4) {
        bench_unroll<8>(A, B, C, rep);
    }
    
    return 0;
}
