#include <string>
#include <iostream>

#if __has_include(<filesystem>)
    #define FSVERSION 2
    #include <filesystem>
    namespace fs = std::filesystem;
#elif __has_include(<experimental/filesystem>)
    #define FSVERSION 1
    #include <experimental/filesystem> 
    namespace fs = std::experimental::filesystem::v1;
#endif

using namespace std;

int main (int argc, char* argv[]) 
{
#ifdef FSVERSION
    cout << (FSVERSION == 2 ? "mature" : "experimental") << " filesystem support.\n";
    
    std::string path = ".";
    if (argc > 1)
	path = argv[1];
    for (auto & p : fs::directory_iterator(path))
	if (is_regular_file(p))
	    cout << p << " is a regular file.\n";
	else if(is_directory(p))
	    cout << p << " is a directory.\n";
	else
	    cout << p << " is neither regular file nor directory.\n";
#else
    std::cerr << "File system not supported yet by this compiler.\n";
#endif
    
    return 0;
}

#if 0
.\\cpp17_vector_any.exe is a regular file
.\\sub is a directory
#endif

