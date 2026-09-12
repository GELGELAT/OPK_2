#include "rand_main.h"
#include <stdlib.h>
float rand_with_in_f(float min, float max)
{
    float coefficient = (float)rand() / (RAND_MAX);
    return (min + (coefficient*(max-min)));
}