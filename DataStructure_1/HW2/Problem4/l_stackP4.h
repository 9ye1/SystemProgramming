#ifndef _L_STACK_

#define _L_STACK_

#include "listP4.h"

typedef List Stack;

void push(Stack *s, char c);
char pop(Stack *s);
char top(Stack s);
void freeStack(Stack *s);

#endif