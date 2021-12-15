#include <iostream>
#include <mutex>
#include <thread>
#include <future>
#include <array>
#include <chrono>

namespace dmc {

    template <std::size_t N>
    class array_lock_guard
    {
	// index_sequence<0, 1, 2, ..., N-1>
	template <std::size_t ...I>
	void lock_all(std::index_sequence<I...>)
	{
	    std::lock(mutexes[I]...);
	}

      public:
	array_lock_guard(std::array<std::mutex, N>& mutexes) 
	  : mutexes(mutexes) 
	{
	    lock_all(std::make_index_sequence<N>{});
	}

	~array_lock_guard()
	{
	    for (auto& m : mutexes)
		m.unlock();
	}

      private:
	std::array<std::mutex, N>& mutexes;
    };

    std::array<std::mutex, 8> mutexes;

    void my_task(int i, int ms)
    {
	array_lock_guard<8> alg(mutexes);
	std::cout << "Start my_task " << i << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
	std::cout << "Finish my_task " << i << std::endl;
    }

}


int main (int argc, char* argv[]) 
{
    using namespace std;
    using namespace dmc;

    auto f1= std::async(&my_task, 1, 1000);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Launch my_task 2" << std::endl;
    auto f2= std::async(&my_task, 2, 200);
    
    f1.wait(); f2.wait();

    return 0;
}

