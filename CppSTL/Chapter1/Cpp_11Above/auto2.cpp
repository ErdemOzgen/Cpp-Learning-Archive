#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

class UsedByAuto {
    string name;
public:
    UsedByAuto(string newName) : name(newName) {}
    string get() const {
        return name;
    }
};

template<class T>
class Auto {
    T anything;
public:
    Auto(T anthg) : anything(anthg) {}
    auto echo() -> decltype(auto) {
        for(auto element: anything) {
            cout << element << " ";
        }
        cout << endl;
    }
};


int main()
{
    /* Example I: Using a vector of integer numbers */
    vector<int> numbers = {1,2,3,4,5};
    Auto< vector<int> > v(numbers);
    v.echo();

    /* Example II: Using a string */
    string myString("Dimos");
    Auto< string > String(myString);
    String.echo();

    /* Example III: Using another Class ! */
    vector<string> names = {"Fortounis", "Avraam", "Camara"};
    for(auto name: names) {
        UsedByAuto toBeUsed(name);
        Auto< string > last(toBeUsed.get());
        last.echo();
    }

    return 0;
}