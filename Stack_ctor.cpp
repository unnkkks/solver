#include "stack.h"
#include <stdlib.h>
elem_t Stack_ctor(struct Stack* stk, elem_t stack_start_capacity)
{
    stk->data = (elem_t*) calloc(stack_start_capacity, sizeof(elem_t));
    stk->stack_size = 0;
    stk->capacity = stack_start_capacity;
    return OK;
}
