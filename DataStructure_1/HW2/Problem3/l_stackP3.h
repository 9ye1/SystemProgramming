#ifndef _L_STACK_

#define _L_STACK_

#include "listP3.h"

typedef List Stack;

void push(Stack *s, Element e);
Element pop(Stack *s);
Element top(Stack s);
void freeStack(Stack *s);

#endif