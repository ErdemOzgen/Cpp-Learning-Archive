#include <iostream>
#include <string>
#include <map>

using namespace std;

void show(const char* msg, map<string, int> mp)
{
    map<string, int>::iterator itr;

    cout << msg << "\n";
    for(itr=mp.begin();itr!=mp.end();++itr) {
        cout << "KEY: " << itr->first << "\t->\tVALUE: " << itr->second << "\n";
    }
    cout << endl;
}

int main()
{
    map<string, int> m;
    m.insert(pair<string, int>("Alpha", 100));
    m.insert(pair<string, int>("Gamma", 300));
    m.insert(pair<string, int>("Delta", 400));
    m.insert(pair<string, int>("Beta", 200));

    //
    map<string, int> m2(m);

    map<string, int>::iterator itr;

    itr = m.begin();
    cout << "FIrst key/value pair in m is: " << itr->first << ", " << itr->second << endl;

    itr = m.end();
    --itr;
    cout << "\nThe last key/value pair in m is: " << itr->first << ", " << itr->second << "\n\n";

    show("Contents of m are: ", m);
    m.clear();
    show("M is now empty: ", m);

    m2.erase("Delta");
    m2.erase("Alpha");
    show("M2 after erasing two key/values is: ", m2);

    m.swap(m2);
    show("\nM2 after swap is: ", m2);
    show("\nM after swap is: ", m);

    return 0;
}
