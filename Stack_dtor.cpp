#include "stack.h"
#include <stdlib.h>
elem_t Stack_dtor(struct Stack* stk)
{
    free(stk->data);
    stk->data = NULL;
    stk->stack_size = 0;
    stk->capacity = 0;
    return OK;
}
