#include <assert.h>
#include "test_bm.h"
#include <stdio.h>
#include "boyer_moore.h"

void bm_tests()
{
    
    /*
    Проверить реализацию тестами
    Обеспечить корректную работу со следующими случаями:

    пустая подстрока (needle == "") — вернуть -1;
    подстрока длиннее строки (len(needle) > len(haystack)) — вернуть -1;
    отсутствие подстроки в строке — вернуть -1.

    char arr[]="saisisi";
    char need[]="si";
    printf("%d\n",boyer_moore(arr,need));
    */
    char test_empty[]="";
    char need1[]="si";
    assert(boyer_moore(test_empty,need1)==-1);
    
    char test_long_string[]="f";
    char need2[]="sfsfsai";
    assert(boyer_moore(test_long_string,need2)==-1);

    char test_substring_not_found[]="fgagjytjytrfdfdsfaej";
    char need3[]="sfsfsai";
    assert(boyer_moore(test_substring_not_found,need3)==-1);

    assert(boyer_moore(NULL,NULL)==-1);

    char test_1[]="His next class is art. He draws on paper with crayons and pencils and sometimes uses a ruler. Lucas likes art. It is his favorite class.";
    char need[]="sometimes";
    assert(boyer_moore(test_1,need)==70);
}