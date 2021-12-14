#include <iostream>
#include <string>
#include <map>

#include <utility>

using namespace std;


template<typename x, typename y>
class MapDemonstration 
{
    typedef typename map<x, y>::iterator mapItr;
public:
    // insert values to a map0
    //
    void push(x town, y country)
    {
        towns.insert(pair<x,y>(town, country));
    }

    // print the map structure
    //
    void print()
    {
        //typename map<x,y>::iterator start = mp.begin();
        mapItr Itr = towns.begin();
        mapItr End = towns.end();
        while(Itr != End)
        {
            cout << "Town: " << Itr->first << "\t\t\tCountry: " << Itr->second << endl;
            Itr++;
        }
        // same as :: 
        // for(const auto &[town, country] : towns)
        //      cout << "Town: " << town << "\t\t\tCountry: " << country << endl;
    }

    // find the origin countyry of a town from a map struct
    //
    string find_country(const string &town)
    {
        // Search for the town named 'town'
        // and return its country
        // typename map<x,y>::iterator origin_country_itr = towns.find(town);
        mapItr origin_country_itr = towns.find(town);
        if(origin_country_itr != towns.end())
            return origin_country_itr->second;
        return "[ NOT found ]";
    }
private:
    // create an empty map
    map<x, y> towns;
};




int main()
{
    MapDemonstration<string, string> TestObj;

    TestObj.push("Alexandria", "Egypt");
    TestObj.push("Utrecht", "The Netherlands");
    TestObj.push("Boston", "The US");
    TestObj.push("Athens", "Greece");

    TestObj.print();

    string origin_country = TestObj.find_country("Athens");
    cout << "\nAthens is located in : " << origin_country << endl;

    string not_found = TestObj.find_country("Patras");
    cout << "\nPatras is located in : " << not_found << " <-- this should be empty!\n";

    return 0;
}

/* OUTPUT ::

Town: Alexandria			Country: Egypt
Town: Athens			Country: Greece
Town: Boston			Country: The US
Town: Utrecht			Country: The Netherlands

Athens is located in : Greece

Patras is located in : [ NOT found ] <-- this should be empty!

*/
