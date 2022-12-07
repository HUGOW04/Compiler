#include <stdlib.h>

#include "../include/stack.h"

struct Stack *head = NULL;

void push(int val)
{
    struct Stack* item = malloc(sizeof(struct Stack));
    item->val = val;
    item->next = head;
    head = item;
}

int pop()
{
    int val = head->val;

    struct Stack *tmp = head;
    head = head->next;
    free(tmp);

    return val;
}

bool empty()
{
    return NULL == head;
}