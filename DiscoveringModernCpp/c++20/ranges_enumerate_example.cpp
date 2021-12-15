// Example program for Discovering Modern C++
//
// File: range_enumerate_example.cpp
// Date: 2020-02-12

#include <iostream>
#include <vector>
#include <utility>
#include <iterator>

using namespace std;

namespace dmc {

    using namespace ::ranges;
    
    template <typename Range>
    class enumerate_iterator
    {
        using riter= decltype(std::begin(std::declval<Range>()));
        using self= enumerate_iterator<Range>;
    public:
        explicit enumerate_iterator(int index, riter it) : index{index}, it{it} {}
        
        auto operator*() const noexcept { return make_pair(index, *it); }
        bool operator!=(self other) const noexcept { return it != other.it; }
        self& operator++() noexcept { ++index; ++it; return *this; }        
    private:
        int   index;
        riter it;
    };


    template <typename Range>
    class enumerate_view
    {
        using iter= enumerate_iterator<Range>;
    public:
        enumerate_view(Range& r) : r{r} {}
        
        iter begin() const noexcept { return iter{0, std::begin(r)}; }
        iter end() const noexcept { return iter{-1, std::end(r)}; }
        
    private:
        Range& r; // requires lvalue!!!
    };

    namespace view {

        struct enumerate_t 
        {
            template <typename Range>
            enumerate_view<Range> operator()(Range&& r) const noexcept
            {
                return enumerate_view<Range>{std::forward<Range>(r)};
            }
        };
        static constexpr enumerate_t enumerate;
        
        template <typename Range>
        enumerate_view<Range> operator|(Range&& r, enumerate_t) noexcept
        {
            return enumerate_view<Range>{std::forward<Range>(r)};
        }

    }
} // namespace dmc


int main()
{
    using namespace dmc;

    vector<int> seq= {3, 4, 7, 9, 2, 5, 7, 8, 3, 4, 3, 9};    

    for (size_t i= 0; i < std::size(seq); ++i)
        cout << "The " << i << "th value is " << seq[i] << endl;

    for (auto [i, value] : dmc::enumerate_view{seq})
        cout << "The " << i << "th value is " << value << endl;

    for (auto [i, value] : dmc::view::enumerate(seq))
        cout << "The " << i << "th value is " << value << endl;

    for (auto [i, value] : seq | dmc::view::enumerate) {
        value*= i;
        cout << "The " << i << "th value is " << value << endl;
    }

    return 0;
}
