#include "parenthesis_balance.h"

int main(void)
{
    char *test_strs[8] = {"", "((()))()(())", "", "()", "dasda()", "()((()))", "()()(()))", "(sad)gaf(dsad)(())"};
    int test_value[8] = {1,1,1,1,1,1,0,1};
    for (int i = 0; i < 8; i++)
    {
        bool balanced = is_balanced(test_strs[i]);
        printf("test %d) current value -> %d|should be ->%d \n", i,balanced,test_value[i]);
    }
}