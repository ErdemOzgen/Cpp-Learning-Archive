// Example program for Discovering Modern C++
//
// File: vector_constraint_initialization.cpp
// Date: 2020-02-13

#include <iostream>
#include <memory>
#include <algorithm>
#include <list>
#include <iterator>

#if __has_include(<ranges>)
# include <ranges>
# define WITH_RANGES
#endif

using namespace std;

namespace dmc {

struct range_error {};
struct incompatible {};
    
template <typename Value>
class vector 
{
    void check_index(int i) const { if (i < 0 || i >= my_size) throw range_error{}; }
    void copy(const vector& that) { std::copy(&that.data[0], &that.data[that.my_size], &data[0]); }
  public:
    vector() : my_size{0}, data{} {}

    explicit vector(int size) : my_size{size}, data{ new Value[my_size] } {}

    vector(std::initializer_list<Value> values) : vector(values.size())
    {
        *this= values;
        std::cout << "initializer_list constructor called.\n";
    }

    vector(const vector& that) : vector(that.size())
    {
        copy(that);
    }

    vector(vector&& that) : my_size{that.my_size}, data{std::move(that.data)}
    {
        that.my_size= 0;
    }
    
    template <std::forward_iterator Iter> // needed to reuse iter in distance and copy 
    vector(Iter first, Iter last) : vector(distance(first, last))
    {
        using std::copy;
        copy(first, last, &data[0]);
    }
    
    // template <std::is_range Range>
    template <std::ranges::forward_range Range>
    vector(Range&& r) : vector(begin(forward<Range>(r)), end(forward<Range>(r))) {}

    vector& operator=(const vector& that) &
    {
        check_size(that.my_size);
        copy(that);
        return *this;
    }
    
    vector& operator=(vector&& that) &
    {
        check_size(that.size());
        data= std::move(that.data);
        that.my_size= 0;
        return *this;
    }
    
    vector& operator=(std::initializer_list<Value> values) &
    {
        check_size(values.size());
        std::copy(begin(values), end(values), &data[0]);
        return *this;
    }

    void check_size(int that_size) const { if (my_size != that_size) throw incompatible{}; }    
    int size() const { return my_size; }

    const Value& operator[](int i) const& { check_index(i); return data[i]; }     
          Value& operator[](int i) &      { check_index(i); return data[i]; }
          Value  operator[](int i) &&     { check_index(i); return data[i]; }

  private:
    int                       my_size;
    std::unique_ptr<Value[]>  data;
};

template <std::forward_iterator Iter> // without deduction guide we'd get vectors of iterators
vector(Iter first, Iter last) -> vector<std::iter_value_t<Iter>>;

template <std::ranges::forward_range Range>
vector(Range&& r) -> vector<std::iter_value_t<decltype(begin(r))>>;
// vector(Iter first, Iter last) -> vector<std::range_value_t<Iter>>;

template <typename Value>
std::ostream& operator<<(std::ostream& os, const vector<Value>& v)
{
    os << '[';
    if (v.size() > 0)
        os << v[0];
    for (int i= 1; i < v.size(); ++i) 
        os << ", " << v[i];
    return os << ']';
}

template <typename Value>
vector<Value> operator+(const vector<Value>& v, const vector<Value>& w)  
{
    int s= v.size();
    w.check_size(s);
    vector<Value> sum(s);
    for (int i= 0; i < s; ++i) 
        sum[i] = v[i] + w[i];
    return sum;
}

} // namespace dmc

int main()
{
    using namespace dmc;
    
    list l= {17, 4, 3, 9, 2};
    dmc::vector<int> v{begin(l), end(l)};
    cout << "vector initialized with iterators: " << v << ".\n";
    
#ifdef WITH_RANGES
    dmc::vector w= ranges::iota_view{1, 101}; 
    cout << "vector initialized with range (iota_view): " << w << ".\n";
#else
    std::cout << "Skip iota_view example due to still missing ranges :-(\n";
#endif

    // a list is also a range
    dmc::vector x= l;
    cout << "vector initialized with range (list): " << x << ".\n";
    
    
    return 0;
}
