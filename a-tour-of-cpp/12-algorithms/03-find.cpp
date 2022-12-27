#include <iostream>

using std::cout;
using std::string;



// does s contain the character c?
// PS: it could be other kind of types here
bool has_c(const string& s, char c) {
    // find = returns an iterator to the first element in the range [first, last) that compares equal to val.
    // If no such element is found, the function returns last (end()) to indicate “not found.”
    auto p = find(s.begin(), s.end(), c);
    
    if (p != s.end())
        return true;
    else
        return false;
}


// short version
bool has_c_short(const string& s, char c) {
    return find(s.begin(), s.end(), c) != s.end();
}


string bool_to_string(bool b) {
    return (b) ? "true" : "false";
}


int main() {
    string str = "A nice sentence here!";
    
    cout << "str has 's'? " << bool_to_string(has_c(str, 's')) << "\n";
    cout << "str has 's'? " << bool_to_string(has_c_short(str, 'x')) << "\n";
    
    return 0;
}

