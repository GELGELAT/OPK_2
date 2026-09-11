#include "parenthesis_balance.h"

int main(void)
{
    char *test_strs[8] = {"", "((()))()(())", "", "()", "dasda()", "()((()))", "()()(()))", "(sad)gaf(dsad)(())"};
    for (int i = 0; i < 8; i++)
    {
        bool balanced = is_balanced(test_strs[i]);
        printf("%d", balanced);
    }
}