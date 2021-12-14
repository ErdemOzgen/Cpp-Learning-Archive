#include <iostream>
#include <regex>

#include <regex>
#include <map>

using namespace std;

map<int, string> multOccurences(string &strToSearch, string & regex_pattern)
{
    // Initialize a map of strings, ints that will contain all occurences 
    // of pattern and its location index too in strToSearch string using cpp regex
    map<int, string> allOccurences;

    try 
    {
        regex re(regex_pattern);
        sregex_iterator start(strToSearch.begin(), strToSearch.end(), re);
        sregex_iterator end;

        int i = 0;
        while( start != end ) {
            smatch match = *start;
            // cout << match.str() << "\n\n";
            // cout << " .. found at position: " << match.position(i) << endl;
            allOccurences.insert(make_pair<int, string>(match.position(i), match.str()));
            // i++;

            start++;
        }

    } catch (std::regex_error& e) {
        // error in regex 
        cout << "\n\t\t\tregex Error ... \n\n";
    }

    return allOccurences;
}


int main()
{
    string str("Hello my name is Dimos ... Oops my name is Dimosthenis ... Wrong my name is dimkatsi ...\n");
    string pat("name");

    map<int, string> v = multOccurences(str, pat); 
    map<int, string>::iterator itr = v.begin();

    while(itr != v.end())
    {
        cout << "Item: " << itr->second << " found at position: " << itr->first << endl;
        itr++;
    }
    

    return 0;
}

/*  Console Output ::

Item: name found at position: 9
Item: name found at position: 35
Item: name found at position: 68

*/