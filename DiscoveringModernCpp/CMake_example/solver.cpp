#include <iostream>

#include "solver.hpp"

namespace dmc {

system discretize(const mesh& m)
{
    std::cout << "Now I'm discretizing.\n";
    system s;
    return s;
}

void solve(system& s)
{
    std::cout << "Now I'm solving.\n";
}

} // namespace dmc
