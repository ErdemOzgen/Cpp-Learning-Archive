#include <cassert>
#include <iostream>
#include <cmath>

#if 0
template <typename Target, typename Source, int N>
struct fsize_assign
{
    static void eval(Target& tar, const Source& src)
    {
        if constexpr (N > 0)
            fsize_assign<Target, Source, N-1>::eval(tar, src);
	std::cout << "assign entry " << N << "\n";
	tar[N]= src[N];
    }
};
#endif

template <int N>
struct fsize_assign
{
    template <typename Target, typename Source>
    static void eval(Target& tar, const Source& src)
    {
        if constexpr (N > 0)
            fsize_assign<N-1>::eval(tar, src);
	std::cout << "assign entry " << N << "\n";
	tar[N]= src[N];
    }
};

template <typename Matrix, typename Vector>
struct mat_vec_et
{
    const static int my_rows= Matrix::my_rows, my_cols= Matrix::my_cols;

    mat_vec_et(const Matrix& A, const Vector& v) : A(A), v(v) {}

    const Matrix& A;
    const Vector& v;
};

template <int Row, int Col>
struct fsize_mat_vec_mult
{
    template <int R, int C> using mvm= fsize_mat_vec_mult<R, C>;
    
    template <typename Matrix, typename VecIn, typename VecOut>
    static void eval(const Matrix& A, const VecIn& v_in, VecOut& v_out)
    {
        if constexpr (Col == 0) {
            if constexpr (Row > 0)
                mvm<Row-1, Matrix::my_cols-1>::eval(A, v_in, v_out);        
            v_out[Row]= A[Row][Col] * v_in[Col];
            // std::cout << "v_out[" << Row << "]= A[" << Row << "][" << Col << "] * v_in[" << Col << "]\n";
        } else {
            mvm<Row, Col-1>::eval(A, v_in, v_out);
            v_out[Row]+= A[Row][Col] * v_in[Col];
            // std::cout << "v_out[" << Row << "]+= A[" << Row << "][" << Col << "] * v_in[" << Col << "]\n";
        }
    }
};

template <int Row, int Col>
struct fsize_mat_vec_mult_cm
{
    template <int R, int C> using mvm= fsize_mat_vec_mult_cm<R, C>;
    
    template <typename Matrix, typename VecIn, typename VecOut>
    static void eval(const Matrix& A, const VecIn& v, VecOut& w)
    {
        if constexpr (Col == 0) {
            if constexpr (Row > 0)
                mvm<Row-1, 0>::eval(A, v, w);
            w[Row]= A[Row][0] * v[0];
            // std::cout << "w[" << Row << "]= A[" << Row << "][" << Col << "] * v[" << Col << "]\n";
        } else { 
            if constexpr (Row > 0)
                mvm<Row-1, Col>::eval(A, v, w);
            else 
                mvm<Matrix::my_rows-1, Col-1>::eval(A, v, w);
            w[Row]+= A[Row][Col] * v[Col];
            // std::cout << "w[" << Row << "]+= A[" << Row << "][" << Col << "] * v[" << Col << "]\n";
        }
    }
};


template <int Row, int Col>
struct fsize_mat_vec_mult_aux
{
    template <typename Matrix, typename VecIn, typename Tmp>
    static void eval(const Matrix& A, const VecIn& v, Tmp& w)
    {
        if constexpr (Col == 0) {
            w= A[Row][0] * v[0];
            // std::cout << "w[" << Row << "]= A[" << Row << "][" << Col << "] * v[" << Col << "]\n";
        } else {
            fsize_mat_vec_mult_aux<Row, Col-1>::eval(A, v, w);
            w+= A[Row][Col] * v[Col];
            // std::cout << "w[" << Row << "]+= A[" << Row << "][" << Col << "] * v[" << Col << "]\n";
        }
    }
};

template <int Row, int Col>
struct fsize_mat_vec_mult_reg
{
    template <typename Matrix, typename VecIn, typename VecOut>
    static void eval(const Matrix& A, const VecIn& v, VecOut& w)
    {
        if constexpr (Row > 0)
            fsize_mat_vec_mult_reg<Row-1, Col>::eval(A, v, w);

	typename VecOut::value_type tmp;
	fsize_mat_vec_mult_aux<Row, Col>::eval(A, v, tmp);
	w[Row]= tmp;
    }
};



template <typename T, int Size>
class fsize_vector 
{
    using self= fsize_vector;
    void check_index(int i) const { assert(i >= 0 && i < my_size); }

  public:  
    using value_type= T           ;
    const static int     my_size= Size;

    fsize_vector() {}

    fsize_vector( const self& that )
    {
	for (int i= 0; i < my_size; ++i)
	    data[i]= that.data[i];
    }

    self& operator=( const self& that ) 
    {
	fsize_assign<my_size-1>::eval(*this, that);
	return *this;
    }

    template <typename Vector>
    self& operator=( const Vector& that ) 
    {
	fsize_assign<my_size-1>::eval(*this, that);
	return *this;
    }


    template <typename Matrix, typename Vector>
    self& operator=(const mat_vec_et<Matrix, Vector>& that)
    {
	using et= mat_vec_et<Matrix, Vector>;
	// fsize_mat_vec_mult<et::my_rows-1, et::my_cols-1>::eval(that.A, that.v, *this);
	// fsize_mat_vec_mult_cm<et::my_rows-1, et::my_cols-1>::eval(that.A, that.v, *this);
	fsize_mat_vec_mult_reg<et::my_rows-1, et::my_cols-1>::eval(that.A, that.v, *this);
	return *this;
    }

    int size() const { return my_size ; }

    const T& operator[]( int i ) const 
    {
	check_index(i);
	return data[i];
    }
		     
    T& operator[]( int i ) 
    {
	check_index(i);
	return data[i] ;
    }

  private:
    T     data[Size] ;
};


template <typename T, int Size>
std::ostream& operator<<(std::ostream& os, const fsize_vector<T, Size>& v)
{
    os << '[';
    if (v.size() > 0)
        os << v[0];
    for (int i= 1; i < v.size(); ++i) 
        os << ", " << v[i];
    return os << ']';
}

template <typename T, int Rows, int Cols>
class fsize_matrix 
{
    static_assert(Rows > 0, "Row must be larger than 0."); 
    static_assert(Cols > 0, "Col must be larger than 0.");

    using self= fsize_matrix;
  public:  
    using value_type= T;
    const static int     my_rows= Rows, my_cols= Cols;

    fsize_matrix() 
    {
	for (int i= 0; i < my_rows; ++i)
	    for (int j= 0; j < my_cols; ++j)
		data[i][j]= T(0);
    }

    fsize_matrix( const self& that )
    {
	for (int i= 0; i < my_rows; ++i)
	    for (int j= 0; j < my_cols; ++j)
		data[i][j]= that.data[i][j];
    }

    // cannot check column index
    const T* operator[](int r) const { return data[r]; }
    T* operator[](int r) { return data[r]; }

    mat_vec_et<self, fsize_vector<T, Cols> > 
    operator*(const fsize_vector<T, Cols>& v) const 
    { 
	return {*this, v}; 
    }

  private:
    T     data[Rows][Cols];
};


int main() 
{
    fsize_vector<float, 4> v, w ;
    v[0] = v[1] = 1.0 ; v[2] = 2.0 ; v[3] = -3.0 ;
    w= v;

    fsize_matrix<float, 4, 4> A;
    A[0][1]= 2.3; A[1][2]= 3.4; A[2][3]= 4.1; A[3][0]= 5.; 

    w= A * v;
    std::cout << "A * v = " << w << '\n';

    return 0 ;
}
