#include "stack.h"

stack *stack_create()
{
    stack *s;

    s = (stack *) malloc(sizeof(*s));

    if (s != NULL) {
        s->size = 0;
        s->top = NULL;
    }

    return s;
}

void stack_free(stack *s)
{
    while (s->size > 0) {
        listnode *node = stack_pop(s);
        free(node->key);
        free(node);
    }
    free(s);
}

int stack_size(stack *s)
{
    return s->size;
}

int stack_push(stack *s, int val, char *data)
{
    s->top = listnode_addfront(s->top, val, data);

    if (s->top == NULL) {
        cout << "stack: Stack overflow\n";
        return -1;
    }

    s->size++;
    return 0;
}

listnode *stack_pop(stack *s)
{
    listnode *next;
    listnode *data;

    if (s->top == NULL) {
        cout << "stack: Stack undeflow\n";
        return NULL;
    }

    next = s->top->next;
    data = s->top;
    free(s->top->key);
    free(s->top);
    s->top = next;
    s->size--;
    return data;
}

void stack_print(stack *s)
{
    listnode_print(s->top);
}
