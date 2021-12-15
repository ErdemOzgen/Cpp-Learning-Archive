#include <iostream>
#include "solver.hpp"
#include "mesher.hpp"

int main()
{
    dmc::mesh my_mesh;
    mesh_it(my_mesh);

    dmc::system my_system= discretize(my_mesh);
    solve(my_system);

    return 0;
}
