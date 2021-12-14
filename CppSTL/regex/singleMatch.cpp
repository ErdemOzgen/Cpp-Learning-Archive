#include <iostream>
#include <regex>

#include <regex>

using namespace std;


string singleOccurence(string &str, string r)
{
    string subject( str );
    string result;
    try {
        regex re( r );
        smatch match;
        if (regex_search(subject, match, re) && match.size() > 1) {
            result = match.str(1);
        } else {
            result = std::string("");
        }
    } catch (regex_error& e) {
        // error in regex

    }
    return result;
}


int main() 
{
    string str("Hello my name is Dimos and my favorite team is Olympiakos ... \n");
    cout << singleOccurence(str, "name (.*)") << endl;
    cout << singleOccurence(str, "team is (.*)") << endl;

    return 0;
}

/* COnsole Output ::

is Dimos and my favorite team is Olympiakos ... 
Olympiakos ... 

*/