#include <iostream>
#include <typeinfo>
#include <string>
#include <chrono>
#include <complex>

int main (int argc, char* argv[]) 
{
    using namespace std;
    
    auto herbert= "Herbert"s;
    cout << "Type of herbert is " << typeid(herbert).name() << "\n";

    auto secd= 7.3s;
    cout << "Type of secd is " << typeid(secd).name() << "\n";
    
    auto seci= 7s;
    cout << "Type of seci is " << typeid(seci).name() << "\n";
    
    auto mind= 7.3min;
    cout << "Type of mind is " << typeid(mind).name() << "\n";
    
    auto mini= 7min;
    cout << "Type of mini is " << typeid(mini).name() << "\n";
    
    auto usd= 7.3us;
    cout << "Type of usd is " << typeid(usd).name() << "\n";
    
    auto usi= 7us;
    cout << "Type of usi is " << typeid(usi).name() << "\n";

    auto dur1= 3h;      // 3 hours
    auto dur2= 5.5min;  // 5.5 minutes
    auto dur3= 9s;      // 9 seconds
    auto dur4= 12.3ms;  // 12.3 milliseconds
    auto dur5= 4us;     // 4 microseconds
    auto dur6= 2.3ns;   // 2.3 nanoseconds

    auto dur7= 2h + 12min;
    cout << "Type of dur7 is " << typeid(dur7).name() << "\n";
    
    auto ii= 1i;
    cout << "Type of ii is " << typeid(ii).name() << "\n";

    auto id= 1.0i;
    cout << "Type of id is " << typeid(id).name() << "\n";

    auto zd= 3.2 + 4.3i;
    cout << "Type of zd is " << typeid(zd).name() << "\n";

    auto zf= 3.2f + 4.3if;
    cout << "Type of zf is " << typeid(zf).name() << "\n";
    
    auto zl= 3.2l + 4.3il;
    cout << "Type of zl is " << typeid(zl).name() << "\n";
    
    
    return 0;
} 

