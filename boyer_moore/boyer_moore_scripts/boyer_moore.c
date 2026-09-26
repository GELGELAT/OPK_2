#include <stddef.h>
#include "boyer_moore.h"
#include <stdlib.h>
#include <limits.h>
size_t boyer_moore(char* haystack, char* needle)
{
    size_t len_hs=0, len_n=0;
    size_t hs_i,n_i;
    while (haystack[hs_i]!='/0')
    {
        len_hs++;
        hs_i++;
    }
    while (needle[n_i]!='/0')
    {
        len_n++;
        n_i++;
    }
}

int* build_bad_char_table(char* needle,size_t len_n)
{
    int* bad_char_table = malloc(CHAR_MAX*sizeof(int));
    for (int i=0;i<CHAR_MAX;i++)
    {
        bad_char_table[i]=len_n;
    }

    for(int i=0;i<len_n;i++)
    {
        
    }
}