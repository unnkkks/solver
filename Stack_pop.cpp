#include "stack.h"
#include <stdlib.h>
elem_t Stack_pop(struct Stack* stk)
{
    if (stk->stack_size == 0)
    {
        return EMPTY_STACK;
    }
    elem_t deleted_value = *(stk->data + stk->stack_size-1);
    stk->stack_size--;
    *(stk->data + stk->stack_size) = 0;
    return deleted_value;

}
