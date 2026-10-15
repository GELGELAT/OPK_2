#include "asserts_scripts.h"
#include "stack.h"
#include "create_arrays.h"
#include "assert.h"
void stack_asserts(void)
{
    stack_assert_create_destroy();
    stack_assert_size_push();
}

void stack_assert_create_destroy()
{
    Stack* test = stack_create();
    stack_destroy(test);
    stack_destroy(NULL);

}

void stack_assert_size_push()
{
    Stack* test = stack_create();
    int** str = malloc(sizeof(int*)*5);
    for(int i=0;i<5;i++)
    {
        str[i]= malloc(sizeof(int)*5);
        *str[i] = i;
    }
    for(int i=0;i<5;i++)
    {
        stack_push(test,str[i]);
    }
    stack_push(test,NULL);
    assert(stack_size(test)==5);
    stack_destroy(test);

}
void stack_assert_pop()
{
    Stack* test = stack_create();
    char** str = malloc(sizeof(char*)*5);
    for(int i=0;i<5;i++)
    {
        str[i]= malloc(sizeof(char));
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
}