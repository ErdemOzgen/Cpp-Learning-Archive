// vector_module.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

import vector;

int main()
{
    vector v(4);
    v[0] = v[1] = 1.0; v[2] = 2.0; v[3] = -3.0;
    std::cout << v << std::endl;

    vector w(v.size());
    w = v;

    const vector z(w);
    std::cout << "z[3] is " << z[3] << '\n';

    std::cout << "w is " << w << '\n';
    v[1] = 9.;
    std::cout << "w is " << w << '\n';

    std::cout << "Hello World!\n";
}

