#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

typedef struct stack {
    listnode *top;
    int size;
} stack;

stack *stack_create();
int stack_push(stack *s, int val, char *data);
void stack_print(stack *s);
listnode *stack_pop(stack *s);
int stack_size(stack *s);
void stack_free(stack *s);

#endif
