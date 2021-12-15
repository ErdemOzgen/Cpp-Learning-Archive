#include <string>
#include <algorithm>

std::string between_str(const std::string& input, char starts, char ends) {
    std::string::const_iterator pos_beg 
        = std::find(input.begin(), input.end(), starts);
    if (pos_beg == input.end()) {
        return std::string();
    }
    ++ pos_beg;

    std::string::const_iterator pos_end 
        = std::find(pos_beg, input.end(), ends);

    return std::string(pos_beg, pos_end);
}

#include <boost/utility/string_view.hpp>
boost::string_view between(
    boost::string_view input,
    char starts,
    char ends)
{
    boost::string_view::const_iterator pos_beg 
        = std::find(input.cbegin(), input.cend(), starts);
    if (pos_beg == input.cend()) {
        return boost::string_view();
    }
    ++ pos_beg;

    boost::string_view::const_iterator pos_end 
        = std::find(pos_beg, input.cend(), ends);
    // ...
    if (pos_end == input.cend()) {
        return boost::string_view(pos_beg, input.end() - pos_beg);
    }

    return boost::string_view(pos_beg, pos_end - pos_beg);
}

#include <vector>
void string_view_init_examples() {
    boost::string_view r0("^_^");

    std::string O_O("O__O");
    boost::string_view r1 = O_O;

    std::vector<char> chars_vec(10, '#');
    boost::string_view r2(&chars_vec.front(), chars_vec.size());

    (void)r0;
    (void)r1;
    (void)r2;
}

#include <boost/algorithm/string/case_conv.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/lexical_cast.hpp>
#include <iterator>
#include <iostream>

void string_view_algorithms_examples() {
    boost::string_view r("O_O");
    // Finding single symbol.
    std::find(r.cbegin(), r.cend(), '_');

    // Will print 'o_o'.
    boost::to_lower_copy(std::ostream_iterator<char>(std::cout), r);
    std::cout << '\n';

    // Will print 'O_O'.
    std::cout << r << '\n';

    // Will print '^_^'.
    boost::replace_all_copy(
        std::ostream_iterator<char>(std::cout), r, "O", "^"
    );
    std::cout << '\n';

    r = "100";
    assert(boost::lexical_cast<int>(r) == 100);
}

int main() {
    std::cout << between("Getting expression (between brackets)", '(', ')') << '\n';

    std::string s("(expression)");
    std::cout << between(s, '(', ')') << '\n';

    string_view_init_examples();
    string_view_algorithms_examples();

    assert(between_str(s, '(', ')') == between(s, '(', ')'));
    assert(between_str("(expr", '(', ')') == between("(expr", '(', ')'));
    assert(between_str("expr)", '(', ')') == between("expr)", '(', ')'));
}
