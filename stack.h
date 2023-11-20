#ifndef STACK
#define STACK

typedef int elem_t; //when we want to change int to float/double/char and so on

const int stack_multiplier = 2; //y = x instead of stairs
const int stack_start_capacity = 2;

struct Stack{
    elem_t stack_size;
    elem_t capacity;
    elem_t* data;
};


enum ERRORS{
    OK              = 0 << 0, // << pushes number to particular quantity of bytes
    NO_MEMORY       = 1 << 1,
    EMPTY_STACK     = 1 << 2,
    STACK_NULL      = 1 << 3,
    STACK_DATA_NULL = 1 << 4,

};

elem_t Stack_ctor(struct Stack* stk, elem_t stack_start_capacity);
elem_t Stack_dtor(struct Stack* stk);
elem_t Stack_pop (struct Stack* stk);
elem_t Stack_push(struct Stack* stk, elem_t inserted_value);

#endif
