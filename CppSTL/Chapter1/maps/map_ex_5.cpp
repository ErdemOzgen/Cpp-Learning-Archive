#include <map>  // map
#include <utility>  // pair
#include <iostream>
#include <string>

using namespace std;


typedef map<string, pair<string, int>> StringMapPair;
typedef StringMapPair::iterator StringMapPairItr;

// map of < team_name, < country_name, position > >
StringMapPair teams;

// insert some values
void init() {
    teams.insert( pair<string, pair<string, int>>( "OSFP", make_pair("Greece", 1) ) );                // 1
    teams.insert( pair<string, pair<string, int>>( "Ajax", make_pair("Netherlands", 2) ) );                 // 2
    teams.insert( pair<string, pair<string, int>>( "PAO Athen", make_pair("Greece", 10) ) );            // 3
    teams.insert( pair<string, pair<string, int>>( "Eindhoven", make_pair("Netherlands", 1) ) );            // 4
    teams.insert( pair<string, pair<string, int>>( "Paris SG", make_pair("France", 1) ) );                       // 5
    teams.insert( pair<string, pair<string, int>>( "Lyonnais", make_pair("France", 2) ) );                  // 6
    teams.insert( pair<string, pair<string, int>>( "Marseille", make_pair("France", 3) ) );                 // 7
    teams.insert( pair<string, pair<string, int>>( "Skoda", make_pair("Greece", 3) ) );              // 8
    teams.insert( pair<string, pair<string, int>>( "Rennes", make_pair("France", 4) ) );                    // 9
    teams.insert( pair<string, pair<string, int>>( "Bordeaux", make_pair("France", 5) ) );                  // 10
}

// print teams map
void print() {
    StringMapPairItr itr = teams.begin();
    while( itr != teams.end() ) {
        cout << "Team: " << itr->first << "\t\t Country: " << itr->second.first << "\t\t Position: " << itr->second.second << endl;
        itr++;
    }
}

int main()
{
    init();
    print();

    // I want to find teams that are in the first position, i.e. second element of the pair <string, int> == 1
    //
    cout << "\nSearching for teams in 1st position: \n\n";
    StringMapPairItr itr = teams.begin();
    while( itr != teams.end() ) {
        if(itr->second.second == 1)
            cout << "Team " << ": " << itr->first << "\t\tCountry: " << itr->second.first << "\t\tPosition: " << itr->second.second << endl;

        itr++;
    }

    // I want to find teams from France olny
    //
    size_t count=1;
    string searched_country("France");
    cout << "\nSearching for teams from " << searched_country << ": \n\n";
    itr = teams.begin();
    while(itr!= teams.end())
    {
        if(itr->second.first == searched_country)
            cout << "Team #" << count++ << ": " << itr->first << endl;
        itr++;
    }
    
    return 0;
}