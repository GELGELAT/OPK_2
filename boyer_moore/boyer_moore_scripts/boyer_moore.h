#pragma once
#include <stddef.h>
int boyer_moore(char *haystack, char *needle);
int *build_bad_char_table(char *needle, int len_n);
int *build_good_suffix_table(char *needle, int len_n);
