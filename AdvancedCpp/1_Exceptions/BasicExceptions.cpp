#include <iostream>
#include <string>

using namespace std;

void mightThrow()
{

    bool errorCondition = false;
    bool errorCondition2 = false;
    bool errorCondition3 = true;

    if (errorCondition)
    {
        throw string("Error condition 1");
    }
    if (errorCondition2)
    {
        throw string("Error condition 2");
    }

    if (errorCondition3)
    {
        throw 8;
    }

    throw "This is a const char *e exception Unknown Condition";
}

void throwExceptionFunction()
{
    try
    {
        mightThrow();
    }
    catch (string &e)
    {
        cout << "Caught exception STRINGS: " << e << endl;
    }
    catch (const char *e)
    {
        cout << "Caught exception CONST CHAR *e: " << e << endl;
    }
    catch (int e)
    {
        cout << "Caught exception INT: " << e << endl;
    }
    catch (...)
    {
        cout << "Caught unknown exception" << endl;
    }
}

int main(int argc, char *argv[])
{
    throwExceptionFunction();
    return 0;
}
