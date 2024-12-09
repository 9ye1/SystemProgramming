/*
32210086 강인창

parenthesis matching code using stack
*/

#include <stdio.h>
#include <stdlib.h>
#include "l_stackP3.h"

#define MAX 80

int main(int argc, char const *argv[]) {
    char input[MAX];
    char c;
    Stack s = NULL;

    if (argc == 1) { //Program menu
        printf("Input expression: ");
        scanf(" %s", input);
    }
    else if (argc == 2) { //argument passing
        strcpy_s(input, MAX, argv[1]);
    }
    else {
        printf("Usage: 1. %s \t2. %s expression\n", argv[0], argv[0]);
        exit(1);
    }

    for(int i=0; input[i]; i++) {
        c = input[i];
        if (c == '(') {
            push(&s, i);
        }
        else if (c == ')') {
            if(isEmpty(s)) {
                printf("\nError: Parenthesis does not match(missing start parse)\n");
                exit(1);
            }
            printf("(%d, %d) ", pop(&s), i);
        }
    }
    if(!isEmpty(s)) {
        printf("\nError: Parenthesis does not match(missing end parse)\n");
        exit(1);
    }
    printf("\n");
    return 0;
}