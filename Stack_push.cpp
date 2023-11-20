#include "stack.h"
#include <stdlib.h>
elem_t Stack_push(struct Stack* stk, elem_t inserted_value)
{
    if (stk->stack_size == stk->capacity)
    {
        realloc(stk->data, stk->capacity*stack_multiplier*sizeof(elem_t));
        stk->capacity *= stack_multiplier;
    }
    *(stk->data + stk->stack_size) = inserted_value;
    stk->stack_size++;
    return OK;
}
