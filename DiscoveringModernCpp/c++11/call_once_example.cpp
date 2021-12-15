#include <iostream>
#include <mutex>


namespace carit {

    struct lookup_table
    {
	lookup_table(int para1, int para2)
	{
	    std::call_once(initialized, setup, para1, para2);
	}

	static void setup(int para1, int para2) {     }

	int lookup(int i) { return table[i]; }
      private:
	static int table[256]; 
	static std::once_flag initialized;
    };

    std::once_flag lookup_table::initialized;    
}


int main (int argc, char* argv[]) 
{
    using namespace std;
    using namespace carit;

    lookup_table table(3, 6); // per thread

    return 0;
}

