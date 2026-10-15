#include "double_ended_queue.h"
#include <stdio.h>
int main(void)
{
    Deque* d = deque_create();
    int t=10;
    vptr tp = &t;
    deque_push_back(d,tp);
    printf("%d\n",*(int*)deque_peek_back(d));
}