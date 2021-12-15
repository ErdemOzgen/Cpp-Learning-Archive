#ifndef GREATEST_BESTEST_SOLVER_INCLUDE
#define GREATEST_BESTEST_SOLVER_INCLUDE

#include "mesher.hpp"

namespace dmc {
    
struct system {};

system discretize(const mesh& m);

void solve(system& s);

} // namespace dmc

#endif // GREATEST_BESTEST_SOLVER_INCLUDE
