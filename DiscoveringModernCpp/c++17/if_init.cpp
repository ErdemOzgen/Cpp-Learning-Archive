#include <iostream>
#include <map>
#include <string>

using namespace std;

int main (int argc, char* argv[]) 
{
    map<string, double> constants= {{"e", 2.7}, {"pi", 3.14}};
    if (auto res= constants.insert({"h", 6.6e-34}); res.second)
	cout << "inserted " << res.first->first << " mapping to "
	     << res.first->second << endl;
    else
	cout << "entry for " << res.first->first << " already exists.\n";

    return 0;
}

