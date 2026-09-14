#include "parenthesis_balance.h"
bool is_balanced(char *string)
{
    int i = 0;
    int balance = 0;
    while (string[i] != '\0')
    {
        if (string[i] == '(')
        {
            balance += 1;
        }
        else if (string[i] == ')')
        {
            if (balance == 0)
            {
                return false;
            }
            balance -= 1;
        }

        i++;
    }
    if (balance < 0)
    {
        return false;
    }
    return true;
}

