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
#include "Time.hpp"

int main(int argc, const char *argv[]) {
    Time wakeUp(6, 45, 0);      // non-constant object
    const Time noon(12, 0, 0);  // constant object

    // OBJECT       // MEMBER FUNCTION
    wakeUp.setHour(18);  // non-const    non-const

    noon.setHour(12);  // const        non-const

    wakeUp.getHour();  // non-const    const

    noon.getMinute();       // const        const
    noon.printUniversal();  // const        const

    noon.printStandard();  // const        non-const
    return 0;
}
