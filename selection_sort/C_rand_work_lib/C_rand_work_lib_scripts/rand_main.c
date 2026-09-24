#include "rand_main.h"
#include <stdlib.h>
float rand_with_in_f(float min, float max)
{
    double coefficient = (double)rand() / (RAND_MAX);
    return (min + (coefficient*(max-min)));
}
double rand_with_in_d(double min, double max)
{
    double coefficient = (double)rand() / (RAND_MAX);
    return (min + (coefficient*(max-min)));
}
int rand_with_in_int(int min, int max)
{
    double coefficient = (double)rand() / (RAND_MAX);
    return (min + (coefficient*(max-min)));
}
char rand_with_in_char(char min, char max)
{
    double coefficient = (double)rand() / (RAND_MAX);
    return (min + (coefficient*(max-min)));
}
