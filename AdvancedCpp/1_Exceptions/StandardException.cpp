#include <iostream>
using namespace std;

class CanGoWrong
{
public:
    CanGoWrong()
    {
        cout << "CanGoWrong()" << endl;
        while (true)
        {
            new int[100000000ul];
        }
    }
};

int main(int argc, char *argv[])
{
    try
    {
        CanGoWrong cgw;
    }
    catch (const std::bad_alloc& e) {
        cout << "Allocation failed: " << e.what() << '\n';
    }
    catch (exception &e)
    {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}