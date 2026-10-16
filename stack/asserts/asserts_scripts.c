#include "asserts_scripts.h"
#include "stack.h"
#include "assert.h"
#include "stdlib.h"

void stack_asserts(void)
{
    stack_assert_create_destroy();
    stack_assert_size_push();
    stack_assert_pop();
}

void stack_assert_create_destroy()
{
    Stack* test = malloc(sizeof(Stack));
    stack_create(test);
    stack_destroy(test);
    stack_destroy(NULL);

}

void stack_assert_size_push()
{
    Stack* test = malloc(sizeof(Stack));
    stack_create(test);
    int** str = malloc(sizeof(int*)*5);
    if(!str)return;
    for(int i=0;i<5;i++)
    {
        str[i]= malloc(sizeof(int));
        if(!str[i])return;
        *str[i] = i;
    }
    for(int i=0;i<5;i++)
    {
        stack_push(test,str[i]);
    }
    stack_push(test,NULL);
    assert(stack_size(test)==5);
    stack_destroy(test);
    for(int i=0;i<5;i++)
    {
        free(str[i]);
    }
    free(str);
}
void stack_assert_pop()
{
    Stack* test = malloc(sizeof(Stack));
    stack_create(test);
    char** str = malloc(sizeof(char*)*5);
    if(!str)return;
    for(int i=0;i<5;i++)
    {
        str[i]= malloc(sizeof(char));
        if(!str[i])return;
        *str[i] = '1'+i;
    }
    for(int i=0;i<5;i++)
    {
        stack_push(test,str[i]);
    }
    
    assert(*(char*)stack_pop(test)=='5');
    assert(stack_size(test)==4);
    assert(*(char*)stack_peek(test)=='4');
    assert(stack_size(test)==4);
    stack_destroy(test);
    assert(*str[4]=='5');
    for(int i=0;i<5;i++)
    {
        free(str[i]);
    }
    free(str);
}