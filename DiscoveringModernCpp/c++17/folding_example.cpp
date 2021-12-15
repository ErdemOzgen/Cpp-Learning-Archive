#include <iostream>
#include <string>

using namespace std;

namespace dmc {

    
    template <typename ...P>
    auto sum(const P& ...p)
    {
        return (0 + ... + p);
        // return ((0 + p1) + p2) + ...);

        // return (... + p);
        // return ((p1 + p2) + p3) + ...);
        
        // return (p + ...);
        // return (p1 + (p2 + ...     (p_{n-1} + pn)));

        // return (p + ... + 0);
        // return (p1 + (p2 + ...     (p_{n} + 0)));
    }

    template <typename ...Strings>
    auto concat_left(const Strings& ...strings)
    {
        return (""s + ... + strings);
    }

    template <typename ...Strings>
    auto concat_right(const Strings& ...strings)
    {
        return (strings + ... + ""s);
    }

    struct pstring
    {
        pstring(const string& s) : s(s) {}

        friend pstring operator+(const pstring& p1, const pstring& p2)
	{
            return pstring("(" + p1.s + p2.s + ")");
        }

        friend std::ostream& operator<<(std::ostream& os, const pstring& p)
        {
           return os << p.s;
        }
    
        operator std::string() const { return s; }
    
     private:
        string s;
   };

   pstring operator"" _ps(const char* s, size_t)
   {
       return pstring(s);
   }


}


int main (int argc, char* argv[]) 
{
    using namespace dmc;

    cout << "sum(-7, 3.7f, 9u, -42.6) = " << sum(-7, 3.7f, 9u, -42.6) << endl;
    cout << "sum() = " << sum() << endl;

    cout << "concat_left -> " << concat_left("we"s, "concat"s, "some"s, "strings"s) << endl;
    cout << "concat_right -> " << concat_right("we"s, "concat"s, "some"s, "strings"s) << endl;

    cout << "concat_left -> " << concat_left("we"_ps, "concat"_ps, "some"_ps, "strings"_ps) << endl;
    cout << "concat_right -> " << concat_right("we"_ps, "concat"_ps, "some"_ps, "strings"_ps) << endl;

    cout << "concat_left() -> " << concat_left() << endl;
    cout << "concat_right() -> " << concat_right() << endl;

    return 0;
}
 
