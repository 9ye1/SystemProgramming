/*
32210086 강인창
HW2 Problem 4

Stack implementation using lists and will use list functions.
Stack element is char type.

No need to check for full as list is dynamic.
Check for empty Stack is same as empty list(no overloading in c).

**note**
This stack passes in pointer of the list pointer(stack) to modify the values unlike list.
This is done because in2post was made before changing to lists thus making changes minimal.
*/

#include <stdio.h>
#include <stdlib.h>
#include "l_stackP4.h"

void push(Stack *s, char c) {
    if (s == NULL) {
        printf("&s is NULL. Exiting program.\n");
        exit(1);
    }
    *s = addItem(*s, c);
}

//pops stack and returns popped value
char pop(Stack *s) {
    if (s == NULL) {
        printf("&s is NULL. Exiting program.\n");
        exit(1);
    }

    char c = '\0';
    if (isEmpty(*s)) {
        printf("Stack is empty\n");
    }
    else {
        c = (*s)->value;
        *s = deleteFirstItem(*s);
    }
    return c;
}

//returns top value
char top(Stack s) {
    return s->value;
}

void freeStack(Stack *s) {
    if (s == NULL) {
        printf("&s is NULL. Exiting program.\n");
        exit(1);
    }
    *s = makeListEmpty(*s);
}