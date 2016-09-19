#include <stdio.h>
#include "LongFrac.h"

int main()
{
    printf("calc pi\n");
    
    LongFrac a1, a2;
    
    a1 = atan_inverse(5);
    a1 *= 4;
    
    a2 = atan_inverse(239);
    
    a1 -= a2;
    
    a1 *= 4;
    
    a1.print();
    
    return 0;
}

