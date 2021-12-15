#include <iostream>

using namespace std;

namespace tst {

    /// Length in meter
    class length
    {
      public:
	explicit length(double l) : l(l) {}

	friend std::ostream& operator<<(std::ostream& os, const length& len)
	{
	    if (len.l >= 1000.0)
		return os << len.l / 1000.0 << "km";
	    else if (len.l >= 1.0)
		return os << len.l << "m";
	    else
		return os << len.l * 1000.0 << "mm";
	}

	friend length operator+(const length& len1, const length& len2)
	{
	    return length(len1.l + len2.l);
	}
    
	friend length operator-(const length& len1, const length& len2)
	{
	    return length(len1.l - len2.l);
	}
    
	friend length operator*(double factor, const length& len2)
	{
	    return length(factor * len2.l);
	}
    
      private:
	double l;
    };


    length operator"" _m(long double l)
    {
	return length(l);
    }

    length operator"" _km(long double l)
    {
	return length(1000.0 * l);
    }

    length operator"" _cm(long double l)
    {
	return length(1e-2 * l);
    }

    length operator"" _mm(long double l)
    {
	return length(1e-3 * l);
    }

    length operator"" _miles(long double l)
    {
	return length(1609.344 * l);
    }

    length operator"" _nm(long double l)
    {
	return length(1852 * l);
    }

    void print_length(length len)
    {
	cout << "length is " << len << endl;
    }

}

int main(int argc, char** argv) 
{
    using namespace tst;
    // using tst::operator"" _nm;
    
    length len1{13.5};
    length len2{14.2_km};
    length len3= 14.2_km;
    
    cout << "len1 = " << len1 << endl;
    cout << "len2 = " << len2 << endl;
    cout << "len3 = " << len3 << endl;

    print_length(len1);
    print_length(14.2_m);
    print_length(14.2_km);
    print_length(14.2_mm);
    print_length(0.0142_m);

    auto l1= 13.5_m,
         l2= 14.2_km,
 	 l3= 3 * l2,
         l4= 7.2_nm;

    cout << "l1 = " << l1 << endl;
    cout << "l2 = " << l2 << endl;
    cout << "l3 = " << l3 << endl;
    cout << "l4 = " << l4 << endl;
    

    cout << "2km + 30m = " << 2._km + 30.0_m << endl;
    cout << "2.5miles + 3.2nm = " << 2.5_miles + 3.2_nm << endl;

    return 0;
}
