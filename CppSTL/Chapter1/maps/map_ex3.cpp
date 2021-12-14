#include <iostream>
#include <string>
#include <map>

#include <utility>

using namespace std;

// create an empty map
map<string, string> towns;

// insert values to a map0
//
template<class x, class y>
void push(x town, y country)
{
    towns.insert(pair<x,y>(town, country));
}

// print the map structure
//
template<class x, class y>
void print(map<x, y> &mp)
{
    typename map<x,y>::iterator start = mp.begin();
    while(start != mp.end())
    {
        cout << "Town: " << start->first << "\t\t\tCountry: " << start->second << endl;
        start++;
    }
    // same as :: 
    // for(const auto &[town, country] : mp)
    //      cout << "Town: " << town << "\t\t\tCountry: " << country << endl;
}

// find the origin countyry of a town from a map struct
//
template<class x, class y>
string find_country(map<x,y> &mp, const string &town)
{
    // Search for the town named 'town'
    // and return its country
    typename map<x,y>::iterator origin_country_itr = mp.find(town);
    if(origin_country_itr != mp.end())
        return origin_country_itr->second;
    return "[ NOT found ]";
}


int main()
{
    push<string, string>("Alexandria", "Egypt");
    push<string, string>("Utrecht", "The Netherlands");
    push<string, string>("Boston", "The US");
    push<string, string>("Athens", "Greece");

    print<string, string>(towns);


    string origin_country = find_country<string, string>(towns, "Athens");
    cout << "\nAthens is located in : " << origin_country << endl;

    string not_found = find_country<string, string>(towns, "Patras");
    cout << "\nPatras is located in : " << not_found << " <-- this should be empty!\n";

    return 0;
}

/* OUTPUT ::

Town: Alexandria			Country: Egypt
Town: Athens			Country: Greece
Town: Boston			Country: The US
Town: Utrecht			Country: The Netherlands

Athens is located in : Greece

Patras is located in : [] <-- this should be empty!

*/
