#include <iostream>
#include <vector>
#include <thread>

#if __has_include(<syncstream>)
# include <syncstream>
# define WITH_SYNCSTREAM
#endif

void bla(int id)
{
#ifdef WITH_SYNCSTREAM
    
    std::osyncstream sync_out(std::cout)
    for (int i= 0; i < 300; ++i)
        sync_out << "On thread " << id << ": printing message " << i << std::endl;
    
#else
    for (int i= 0; i < 300; ++i)
        std::cout << "On thread " << id << ": printing message " << i << std::endl;
#endif
}



int main()
{
    using namespace std;
    
    vector<thread> threads;
    for (int i= 0; i < 30; ++i)
        threads.emplace_back(bla, i);
    
    for (thread& t : threads)
        t.join();
    
#ifndef WITH_SYNCSTREAM
    std::cout << "no syncstream :-(\n";
#endif
}
