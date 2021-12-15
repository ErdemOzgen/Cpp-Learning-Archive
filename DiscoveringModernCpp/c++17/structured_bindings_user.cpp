#include <iostream>
#include <map>
#include <utility>
#include <typeinfo>

using namespace std;

namespace dmc {

     // dummies
     class matrix {};
     class vector {};

     struct lu_result
     {
	 matrix LU;
	 vector p;
     };
    
     auto lu(const matrix& A)
     {
	 matrix LU(A);
	 vector p;

	 // ... some computations
	 return lu_result{LU, p};
     }
    
     template <typename T>
     struct sloppy_complex
     {
	 T r, i;
     };

     // template <typename T>
     // class complex : public std::pair<T, T>
     // {
     //     using base= std::pair<T, T>;
     //   public:
     //     explicit complex(T rn = 0.0, T in = 0.0) : base(rn, in) {}
	
     //     T const& real() const { return base::first; } 
     //     T const& imag() const { return base::second; } 
     // };

     template <typename T, typename U= T>
     class complex
     {
       public:
	 explicit complex(T rn = 0.0, U in = 0.0) : r(rn), i(in) {}
	
	 T const& real() const { return r; } 
	 T& real() { return r; }     

	 U const& imag() const { return i; } 
	 U& imag() { return i; }     

	 template <std::size_t N>
	 decltype(auto) get() const
	 {
	     if constexpr (N == 0)
			      return r;
	     else
		 return i;
	 }
       private:
	 T r;
	 U i;
     };

     // template <std::size_t N, typename T>
     // decltype(auto) get(const complex<T>& z)
     // {
     //     if constexpr (N == 0)
     // 	return z.real();
     //     else
     // 	return z.imag();
     // }

     // template <std::size_t N, typename T> decltype(auto) get(const complex<T>& z);

     // // Partial Specialization forbidden for functions (remember?)
     // template <typename T> decltype(auto) get<0, T>(const complex<T>& z) { return z.real(); }
     // template <typename T> decltype(auto) get<1, T>(const complex<T>& z) { return z.imag(); }   

     // template <> decltype(auto) get<0, int>(const complex<int>& z) { return z.real(); }
     // template <> decltype(auto) get<1, int>(const complex<int>& z) { return z.imag(); }
}

namespace std {
    
    template<typename T, typename U>
    struct tuple_size<dmc::complex<T, U> >
      : public std::integral_constant<std::size_t, 2> {};

    template<std::size_t N, typename T, typename U>
    struct tuple_element<N, dmc::complex<T, U> >
    {
        using type = decltype(std::declval<dmc::complex<T, U>>().template get<N>());
        // using type = decltype(get<N>(std::declval<dmc::complex<T, U>>()));
    };
}

int main () 
{
    using namespace dmc;

    matrix A;
    auto [LU, p]= lu(A);
    
    sloppy_complex<short> c{4, 9};
    auto [cr, ci]= c;
    
    complex<int, short> z{3, 7};
    auto [re, im]= z;

    cout << "The real part is " << re << " and the imaginary " << im << ".\n";
    
    return 0;
}
 
