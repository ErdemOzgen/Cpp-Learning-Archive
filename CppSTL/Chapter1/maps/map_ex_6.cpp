#include <iostream>
#include <string>
#include <map>
#include <utility>

using namespace std;

class MapActions {
public:
    // a few definitions, in order not to write every time the same types
    typedef map<string, int> myMap;
    typedef myMap::iterator myMapItr;
    MapActions() {};
    MapActions(const myMap &fromMap) {
        // copy fromMap map to mp map ::
        mp.insert(fromMap.begin(), fromMap.end());
    }
    ~MapActions() {};

    void push(string key, int val) {
        // Insert key: value pair in mp map ::
        mp.insert( make_pair(key, val) );
    }
    void echoMap() {
        // print map ::
        myMapItr itr = mp.begin();
        while( itr != mp.end() ) {
            cout << "(" << itr->first << ", " << itr->second << ")\n";
            itr++;
        }
    }
    // Search for a value inside mp map ::
    void find_key(const string &key) {
        myMapItr kItr = mp.find(key);
        cout << endl << "Searching for key ... " << key << " ... \n";
        if(kItr == mp.end()) {
            cout << "Key: " << key << " NOT found inside map! Try again with another key..\n";
        } else {
            cout << "Key: " << key << " found with value : " << kItr->second << endl;
        }
    }
private:
    myMap mp;
}; 


int main() 
{
   /*
   MapActions Test;
   Test.push("Giovanni", 10);
   Test.push("Rivaldo", 10);

   Test.echoMap();
   */

   // Create a map from and copy this to MapActions class mp map, and then print the map
   // copy constructor
   MapActions::myMap from{ {"Giovanni", 10}, {"Rivaldo", 10}, {"Mellberg", 5} };
   MapActions Test(from);
   Test.echoMap();

   Test.find_key("Rivaldo");
   Test.find_key("Mirrallas");

   return 0;
}