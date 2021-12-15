// Example program for Discovering Modern C++
//
// File: vector_formatted_output.cpp
// Date: 2020-02-13

#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include <iterator>

#ifdef DMC2_WITH_FMT

#include <fmt/format.h>

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

template <typename Value>
struct fmt::formatter<dmc::vector<Value>>
{
    constexpr auto parse(fmt::format_parse_context& ctx) 
    {
        value_format= "{:";        
        for (auto it= begin(ctx), ite= end(ctx); it != ite; ++it) {
            char c= *it;
            if (c == 'c')
                curly= true;
            else
                value_format+= c;
            if (c == '}') 
                return it;
        }
        return end(ctx);
    }
    
    template <typename FormatContext>
    auto format(const dmc::vector<Value>& v, FormatContext& ctx) 
    {
        // std::cout << "value_format = " << value_format << endl;
        auto&& out= ctx.out();
        format_to(out, curly ? "{{" : "[");
        if (v.size() > 0)
            format_to(out, value_format, v[0]);
        for (int i= 1; i < v.size(); ++i) 
            format_to(out, ", " + value_format, v[i]);
        return format_to(out, curly ? "}}" : "]");
    }
    bool        curly{false};
    std::string value_format;
};





#endif // DMC2_WITH_FMT

int main()
{
#ifdef DMC2_WITH_FMT
    using namespace dmc;
    using namespace fmt;
    
    dmc::vector<double> v{1.394, 1e9, 1.0/3.0, 1e-20};
    cout << "v = " << v << ".\n";
    
    print("u = {}, v = {}, w = {}.\n", 2, v, 4);
    
    print("v with empty format string = {}.\n", v);
//     print("v curly with empty format string = {:c}.\n", v);
    print("v with f = {:f}.\n", v);
    print("v curly with f = {:fc}.\n", v);
//     print("v with g (as without formatting) = {:g}.\n", v);
//     print("v curly with g (as without formatting) = {:gc}.\n", v);
//     print("v with 6 fractional digits = {:.6f}.\n", v);
    print("v curly with 6 fractional digits = {:.6fc}.\n", v);
    print("v with 9 symbols and 4 digits = {:9.4f}.\n", v);
    print("v in scientific style = {:ec}.\n", v);
    print("v hex = {:a}.\n", v);
    
    
#else    
    std::cout << "vector_formatted_output: fmt library not enabled. :-(\n";
#endif
    return 0;
}
