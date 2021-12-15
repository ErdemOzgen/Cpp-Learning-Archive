// Example program for Discovering Modern C++
//
// File: vector_refactored.cpp
// Date: 2020-02-03

#include <iostream>
#include <memory>
#include <algorithm>


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

    dmc::vector<double> v{3, 2, 1}, w{2, 3, 4}, u{4, 3, 2};
    std::cout << "u is " << u << std::endl;
    v= {7, 8, 9};
    std::cout << "v is " << v << std::endl;
    // v= set();

    dmc::vector<double> x{std::move(w)}, y{x};
    std::cout << "x is " << x << std::endl;
    std::cout << "w is " << w << std::endl;

    v= std::move(u);
    std::cout << "v is " << v << std::endl;
    std::cout << "u is " << u << std::endl;

    std::cout << "x + y is " << x + y << std::endl;
    
    return 0;
}
