#include <cassert>
#include <iostream>
#include <chrono>

using namespace std::chrono;


template <unsigned Offset, unsigned Max>
struct assign
{
    template <typename U, typename V>
    static void eval(U& u, const V& v, unsigned i)
    {
        if constexpr (Offset < Max) {       
            u[i+Offset]= v[i+Offset];
            assign<Offset+1, Max>::eval(u, v, i);
        }
    }
};


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
      : my_size(0), data(0)
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
	unsigned s= my_size, sb= s / 4 * 4;

	for (unsigned i= 0; i < sb; i+= 4)
	    assign<0, 4>::eval(*this, that, i);

	for (unsigned i= sb; i < s; i++) 
	    data[i]= that[i];

	return *this;
    }

    template <unsigned BSize, typename Src>
    vector& operator=(const Src& that) 
    {
	check_size(size(that));
	unsigned s= my_size, sb= s / BSize * BSize;

	for (unsigned i= 0; i < sb; i+= BSize)
	    assign<0, BSize>::eval(*this, that, i);

	for (unsigned i= sb; i < s; i++) 
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

template <typename V1, typename V2>
class vector_sum
{
    typedef vector_sum   self;
    void check_index(int i) const { assert(i >= 0 && i < size(v1)); }
  public:
    typedef typename V1::value_type value_type;

    vector_sum(const V1& v1, const V2& v2) : v1(v1), v2(v2) 
    { 
	assert(size(v1) == size(v2));
    }

    friend int size(const self& x) { return size(x.v1); }

    value_type operator[](int i) const { check_index(i); return v1[i] + v2[i]; }

  private:
    const V1& v1;
    const V2& v2;
};

template <typename V1, typename V2>
vector_sum<V1, V2> inline operator+(const V1& x, const V2& y) 
{
    return vector_sum<V1, V2>(x, y);
}

template <unsigned BSize, typename V>
class unroll_vector
{
  public:
    unroll_vector(V& ref) : ref(ref) {}

    template <typename Src>
    V& operator=(const Src& that) 
    {
	assert(size(ref) == size(that));
	unsigned s= size(ref), sb= s / BSize * BSize;

	for (unsigned i= 0; i < sb; i+= BSize)
	    assign<0, BSize>::eval(ref, that, i);

	for (unsigned i= sb; i < s; i++) 
	    ref[i]= that[i];
	return ref;
    }
  private:
    V&    ref;
};

template <unsigned BSize, typename Vector>
auto unroll(Vector& v)
{
    return unroll_vector<BSize, Vector>(v);
}

template <typename TP>
double duration_ms(const TP& from, const TP& to, unsigned rep)
{
    return duration_cast<nanoseconds>((to - from) / rep).count() / 1000.;
}

template <unsigned BSize, typename Vector>
void bench_unroll(Vector& u, const Vector& v, const Vector& w, const unsigned rep)
{
    auto t1= steady_clock::now();
    for (unsigned j= 0; j < rep; j++)
	unroll<BSize>(u)= v + v + w;
    auto t2= steady_clock::now();
    std::cout << "Compute time unroll<" << BSize << ">(u)= v + v + w is " 
	      << duration_ms(t1, t2, rep) << " mmicros.\n";
    std::cout << "u[0] is " << u[0] << '\n';
}

int main(int argc, char** argv)  
{
    const unsigned s= 1000; 
    // if (argc > 1) s= atoi(argv[1]);
    vector<float> u(s), v(s), w(s);

    for (unsigned i= 0; i < s; i++) { 
	v[i]= float(i);  
	w[i]= float(2*i + 15);
    }
    const unsigned rep= 1000000; 

#if 1    
    auto t1= steady_clock::now();
    for (unsigned j= 0; j < rep; j++)
	u= v + v + w;
    auto t2= steady_clock::now();
    std::cout << "Compute time is " << duration_ms(t1, t2, rep) << " mmicros.\n";
    std::cout << "u[0] is " << u[0] << '\n';

    u.operator=<4>(v + v + w);
#endif 

#if 1    
    bench_unroll<1>(u, v, w, rep);
    bench_unroll<2>(u, v, w, rep);
    bench_unroll<4>(u, v, w, rep);
    bench_unroll<6>(u, v, w, rep);
    bench_unroll<8>(u, v, w, rep);
#endif 

    return 0 ;
}

 
