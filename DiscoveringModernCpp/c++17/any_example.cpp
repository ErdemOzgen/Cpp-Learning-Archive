#include <iostream>
#include <string>
#include <vector>
#include <any>
#include <typeinfo>

using namespace std;

auto find_ints(const vector<any>& v)
{
    vector<int> vi;
    for (const any& a : v)
	if (a.type() == typeid(int))
	    vi.push_back( any_cast<int>(a) );
    return vi;
}


int main(int argc, char** argv) 
{
    any a;
    a= 3;
    a= 4.2;
    cout << "a is " << any_cast<int>(a) << ".\n";
    
    vector<any> v= {33, 2.3, "Huhu"s, "Dings"s, 11111, 3809, "Soso"s};
    v.push_back(42.0);
    
    auto vi= find_ints(v);
    cout << "Our ints are: ";
    for (int i : vi)
	cout << i << ", ";

    return 0;
}
