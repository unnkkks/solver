#include "stack.h"
#include "Stack_dtor.cpp"
#include "Stack_ctor.cpp"
#include "Stack_push.cpp"
#include "Stack_pop.cpp"
#include <stdio.h>

int main()
{
    struct Stack stk = {0};
    Stack_ctor(&stk, stack_start_capacity);
    int n;
    printf("Enter the quantity of numbers you want to push\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        elem_t input;
        scanf("%zd", &input);
        Stack_push(&stk, input);
    }
    printf("Your stack:");
}
