#include <cmath>
#include <cassert>
#include <iostream>
#include <chrono>

using namespace std::chrono;



template <typename T>
class vector 
{
    void check_size(int that_size) const { assert(my_size == that_size); }
    void check_index(int i) const { assert(i >= 0 && i < my_size); }
  public:
    typedef T   value_type;

    explicit vector(int size)
      : my_size(size), data( new T[my_size] )
    {}

    vector()
      : my_size{0}, data{nullptr}
    {}

    vector( const vector& that )
      : my_size(that.my_size), data( new T[my_size] )
    {
	for (int i= 0; i < my_size; ++i)
	    data[i]= that.data[i];
    }

    ~vector() { if (data) delete [] data ; }

    vector& operator=( const vector& that ) 
    {
	check_size(that.my_size);
	for (int i= 0; i < my_size; ++i)
	    data[i]= that.data[i];
    }

    template <typename Src>
    vector& operator=(const Src& that) 
    {
	check_size(size(that));
	for (unsigned i= 0; i < my_size; i++) 
	    data[i]= that[i];
	return *this;
    }

    friend int size(const vector& x) { return x.my_size; }

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
    int   my_size ;
    T*    data ;
};


template <typename Value>
std::ostream& operator<<(std::ostream& os, const vector<Value>& v)
{
  os << '[';
  if (v.size() > 0)
      os << v[0];
  for (int i= 1; i < v.size(); ++i) 
      os << ", " << v[i];
  return os << ']';
}
 
template <unsigned Offset, unsigned Max>
struct one_norm_ftor
{
    template <typename S, typename V>
    static void eval(S& s0, S& s1, S& s2, S& s3, S& s4, S& s5, S& s6, S& s7, const V& v, unsigned i)
    {
	using std::abs;
        if constexpr (Offset < Max) {       
            s0+= abs(v[i+Offset]);
            // std::cout << "s0+= abs(v[" << i << "+" << Offset << "])\n";
            one_norm_ftor<Offset+1, Max>::eval(s1, s2, s3, s4, s5, s6, s7, s0, v, i);
        }
    }
};

// template <unsigned Max>
// struct one_norm_ftor<Max, Max> 
// {
//     template <typename S, typename V>
//     void operator()(S&, S&, S&, S&, S&, S&, S&, S&, const V&, unsigned) {}
// };

template <unsigned BSize, typename Vector>
typename Vector::value_type
inline one_norm(const Vector& v)
{
    using std::abs;
    typename Vector::value_type s0{0}, s1{0}, s2{0}, s3{0}, s4{0}, s5{0}, s6{0}, s7{0};
    unsigned s= size(v), sb= s / BSize * BSize;
   
    for (unsigned i= 0; i < sb; i+= BSize)
	one_norm_ftor<0, BSize>::eval(s0, s1, s2, s3, s4, s5, s6, s7, v, i);
    s0+= s1 + s2 + s3 + s4 + s5 + s6 + s7;

    for (unsigned i= sb; i < s; i++) 
	s0+= abs(v[i]);

    return s0;
}


template <typename TP>
double duration_ms(const TP& from, const TP& to, unsigned rep)
{
    return duration_cast<nanoseconds>((to - from) / rep).count() / 1000.;
}

template <unsigned BSize, typename Vector>
void inline bench_unroll(const Vector& v, const unsigned rep)
{
    typename Vector::value_type norm;
    auto t1 = steady_clock::now();
    for (unsigned j = 0; j < rep; j++)
        norm = one_norm<BSize>(v);
    auto t2 = steady_clock::now();
    std::cout << "Compute time one_norm<" << BSize << ">(v) is "
        << duration_ms(t1, t2, rep) << " mmicros.\n";
    std::cout << "one_norm<" << BSize << ">(v) is " << norm << '\n';
}

int main(int argc, char** argv)  
{
    const unsigned s= 1000;
    // if (argc > 1) s= atoi(argv[1]);
    vector<float> u(s), v(s), w(s);

    // auto norm = one_norm<4>(v); return 0; // for debugging

    for (unsigned i= 0; i < s; i++) { 
	v[i]= float(i);
	w[i]= float(2*i + 15);
    }
    const unsigned rep= 1000000; 

    bench_unroll<1>(v, rep);
    bench_unroll<2>(v, rep);
    bench_unroll<4>(v, rep);
    bench_unroll<6>(v, rep);
    bench_unroll<8>(v, rep);

    return 0 ;
}

 
