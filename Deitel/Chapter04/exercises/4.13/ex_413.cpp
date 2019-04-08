/*
 * =====================================================================================
 *
 *       Filename:  
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thanks to github you know it
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author: Mahmut Erdem ÖZGEN   m.erdemozgen@gmail.com
 *   
 *
 * =====================================================================================
 */
#include "GasMileage.hpp"

static const int QUIT = -1;

int main(int argc, const char *argv[]) {
    GasMileage gm;

    while (gm.getMilesDriven() != QUIT) {
        gm.run();
    }

    return 0;
}
