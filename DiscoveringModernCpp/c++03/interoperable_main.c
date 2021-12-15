#include <stdio.h>
#include "interoperable.h"


int main(int argc, char** argv) 
{
    printf("ctimes(3, 4.2f) = %f.\n", ctimes(3, 4.2f));

    printf("iadder(3, 4) = %i.\n", iadder(3, 4));
    printf("fadder(3, 4.2f) = %f.\n", fadder(3, 4.2f));

    return 0;
}
 
