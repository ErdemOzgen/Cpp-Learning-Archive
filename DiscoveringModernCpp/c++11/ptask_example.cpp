#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <string>

namespace carit {

    bool is_prime(long i)
    {
	if (i == 1)
	    return false;
	if (i % 2 == 0)
	    return i == 2;
	// sqrt(i) would be enough to check
	for (long j= 3; j < i; j+= 2)
	    if (i % j == 0)
		return false;
	return true;
    }
}

// Similar to std::packaged_task
template <typename Ret, typename ...Args>
class ptask
{
    using fun= std::function<Ret(Args...)>;
  public:

    explicit ptask(fun fn) : f(fn) {}

    void operator()(Args&& ...args) const
    {
	try {
	    p.set_value_at_thread_exit(f(std::forward<Args>(args)...));
	} catch(...) {
	    p.set_exception_at_thread_exit( std::current_exception() );
	}
    }

    std::future<Ret> get_future() const { return p.get_future(); }

  private:
    std::function<Ret(Args...)> f;
    mutable std::promise<Ret>   p;
};



int main (int argc, char* argv[]) 
{
    using namespace std;
    using namespace carit;

    int num_threads= 2;
    if (argc > 1)
	num_threads= stoi(argv[1]);

    vector<long> vi;
    long first_prime= 982451653;
    for (long v= first_prime, i= 0; i < num_threads; ++i, v+= 2)
	vi.emplace_back(v);

    vector<future<bool>> futures;
    for (long i= 0; i < num_threads; ++i) {
	ptask<bool, long> pt(is_prime);
	futures.push_back(pt.get_future());
	thread t(move(pt), vi[i]);
	t.detach();
    }

    for (long i= 0; i < num_threads; ++i) 
	cout << vi[i] << (futures[i].get() ? " is " : " is not ") 
	     << "a prime number.\n";

    return 0;
}

