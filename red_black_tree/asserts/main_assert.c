#include "asserts_script.h"
#include <stdio.h>
#include <time.h>
int main(void)
{
    srand(time(NULL));
    compil_asserts();

    printf("accept\n");
}