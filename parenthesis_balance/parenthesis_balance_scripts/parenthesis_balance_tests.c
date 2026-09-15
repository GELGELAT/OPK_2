#include "parenthesis_balance.h"

int main(void)
{
    assert(is_balanced("") == true);
    assert(is_balanced("()") == true);
    assert(is_balanced("((()))()(())") == true);
    assert(is_balanced("(()())") == true);
    assert(is_balanced("(45(ragfe()(435sag)435)435345(sag))(s)fasf(asf(fas)jhgj)") == true);


    assert(is_balanced(")(") == false);
    assert(is_balanced("((())))") == false);
    assert(is_balanced("(()") == false);
        assert(is_balanced("(45(ragfe()(435sag)435)435345sag))(s)fasf(asf(fas)jhgj)") == false);

}