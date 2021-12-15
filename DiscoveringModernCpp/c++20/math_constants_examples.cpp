#include <iostream>
#include <iomanip>

#if __has_include(<numbers>)
# include <numbers>
# define WITH_MATH_CONSTANTS
#endif

#ifdef WITH_MATH_CONSTANTS
template <typename T>
T circular_area(T r) 
{
    return std::numbers::pi_v<T> * r * r;
}
#endif




int main()
{
    using namespace std;
    
#ifdef WITH_MATH_CONSTANTS

    cout << "The Euler constant is " << setprecision(15) << numbers::e << ".\n";
    cout << "The dual logarithm of the Euler constant is " << setprecision(15) << numbers::log2e << ".\n";
    cout << "The decimal logarithm of the Euler constant is " << setprecision(15) << numbers::log10e << ".\n\n";
    
    cout << "pi is " << setprecision(15) << numbers::pi << ".\n";
    cout << "The inverse of pi is " << setprecision(15) << numbers::inv_pi << ".\n";
    cout << "The inverse of pi's square root is " << setprecision(15) << numbers::inv_sqrtpi << ".\n\n";
    
    cout << "The natural logarithm of 2 is " << setprecision(15) << numbers::ln2 << ".\n";
    cout << "The natural logarithm of 10 is " << setprecision(15) << numbers::ln10 << ".\n\n";
    
    cout << "The square root of 2 is " << setprecision(15) << numbers::sqrt2 << ".\n";
    cout << "The square root of 3 is " << setprecision(15) << numbers::sqrt3 << ".\n\n";
    
    cout << "The Euler-Mascheroni constant is " << setprecision(15) << numbers::egamma << ".\n\n";

    cout << "The golden ratio is " << setprecision(15) << numbers::phi << ".\n\n";
    
    cout << "A circle of radius 3.892 has an area of " << circular_area(3.892) << endl;
#else
    std::cout << "no mathematical constants yet :-(\n";
#endif
}
