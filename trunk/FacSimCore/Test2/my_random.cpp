//my_random.cpp

#include <iostream>

#include "my_random.h"

double random(double from,double to)
{
    long max=RAND_MAX;
    long k=rand();
    double rs = ((k*99.99 )/max)/99.99;
    
    return from + rs*(to-from);
}

