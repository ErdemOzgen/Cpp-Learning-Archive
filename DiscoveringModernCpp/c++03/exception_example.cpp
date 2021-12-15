#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <exception>

using namespace std;

namespace dmc {

    struct io_error
      : std::runtime_error
    {
	io_error(const string& message= "I/O error") : std::runtime_error(message) {}
    };

    struct cannot_open_file
      : io_error
    {
	cannot_open_file(const string& fname) : io_error("File '" + fname + "' not found") {}
    };

    struct matrix {}; // dummy

    matrix read_matrix_file(const string& fname)
    {
	fstream f(fname.c_str());
	if (!f.is_open())
	    // return 1;
	    throw cannot_open_file(fname);
	matrix A;
	// populate A with data (possibly throw exception)
	return A;
    }

}

int main (int argc, char* argv[]) 
{
    using namespace dmc;

    matrix A;
    
    // read_matrix_file("does_not_exist.dat");

#if 0
    try {
	A= read_matrix_file("does_not_exist.dat");
    } catch (cannot_open_file& e) {
	cerr << "O my gosh, the file is not there! Please help me.\n";
	throw;
    }
#endif
    
    // try {
    // 	A= read_matrix_file("does_not_exist.dat");
    // } catch (float& i) {
    // 	cerr << "Catch 1\n";
    // } catch (int& i) {
    // 	cerr << "Catch 2\n";
    // } catch (cannot_open_file& e) {
    // 	cerr << "Hey guys, your file does not exist! I'm out.\n";
    // 	exit(EXIT_FAILURE);
    // } catch (...) {}

    
    bool keep_trying= true;
    do {
	string fname;
	cout << "Please enter file name: ";
	cin >> fname;
	try {
	    A= read_matrix_file(fname);
	    keep_trying= false;
	} catch (cannot_open_file& e) {
	    cout << "Could not open the file. Try another one!\n";
	} catch (io_error& e) {
	    cerr << "Unexpected I/O error. Fix it!\n"; throw;
	} catch (std::runtime_error& e) {
	    cerr << "Unknown run-time error: " << e.what() << "\n"; throw;
	} catch (std::exception& e) {
	    cerr << "Unknown standard exception:" << e.what() << "\n"; throw;
	} catch (...) {
	    cerr << "Unknown exception caught. I call it a day.\n"; throw;
	}
    } while (keep_trying);
    
    (void) A; // nonsense to avoid of A not being used

    return 0;
}

