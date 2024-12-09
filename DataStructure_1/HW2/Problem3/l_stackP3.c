/*
32210086 강인창
HW2 Problem 3

Stack implementation using lists and will use list functions.
Stack element is an int.

No need to check for full as list is dynamic.
Check for empty Stack is same as empty list(no overloading in c).

**note**
This stack passes in pointer of the list pointer(stack) to modify the values unlike list.
*/

#include <stdio.h>
#include <stdlib.h>
#include "l_stackP3.h"

void push(Stack *s, Element e) {
    if (s == NULL) {
        printf("&s is NULL. Exiting program.\n");
        exit(1);
    }
    *s = addItem(*s, e);
}

//pops stack and returns popped value
//returns -999 if empty stack
Element pop(Stack *s) {
    if (s == NULL) {
        printf("&s is NULL. Exiting program.\n");
        exit(1);
    }

    int n = -999; //Element is int
    if (isEmpty(*s)) {
        printf("Stack is empty\n");
    }
    else {
        n = top(*s);
        *s = deleteFirstItem(*s);
    }
    return n;
}

//returns top value
Element top(Stack s) {
    return s->value;
}

void freeStack(Stack *s) {
    if (s == NULL) {
        printf("&s is NULL. Exiting program.\n");
        exit(1);
    }
    *s = makeListEmpty(*s);
}