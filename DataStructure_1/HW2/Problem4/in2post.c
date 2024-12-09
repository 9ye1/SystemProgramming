/*
32210086 강인창
HW2 Problem 4

Infix to postfix program.
As of current, does not support unary operators.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "l_stackP4.h"

#define MAX 80

int prioity(char op1, char op2);

int main(int argc, char const *argv[])
{
    char infix[MAX];
    char c, popc;
    Stack s = NULL;

    if (argc == 1) { //Program menu
        printf("Input infix string: ");
        scanf(" %s", infix);
    }
    else if (argc == 2) { //argument passing
        //strcpy_s(infix, argv[1]);
    }
    else {
        printf("Usage: 1. %s \t2. %s infix_expression\n", argv[0], argv[0]);
        exit(1);
    }

    //need to add check for unary operators  A*(B+C)*D/-F*G
    for (int i = 0; infix[i] != '\0'; i++) {
        c = infix[i];
        //S1
        if (c == '(') {
            push(&s, c);
            continue;
        }

        //S2
        else if (c == ')') {
            while(!isEmpty(s)) {
                popc = pop(&s);
                if (popc == '(') {
                    break;
                }
                else {
                    printf("%c", popc);
                }
            }
            continue;
        }

        //S3
        else if (47 < c) { // 47 == '/'
            printf("%c", c);
            continue;
        }

        //S4
        else {
            if (!(c == '+'||c == '-'||c == '/'||c == '*')) { //skips non identified ops
                continue;
            } 

            while(1) {
                if(!isEmpty(s) && prioity(top(s), c) < 1) {
                    popc = pop(&s);
                    printf("%c", popc);
                    continue;
                }
                push(&s, c);
                break;
            }
        }
    }

    while(!isEmpty(s)) {
        popc = pop(&s);
        printf("%c", popc);
    }

    return 0;
}

//1 if op2 has prioity, 0 if same, -1 if less
int prioity(char op1, char op2) {
    if (op1 == '(') {
        return 1;
    }

    int p1, p2;
    if (op1 == '*' || op1 == '/') {
        p1 = 1;
    }
    else {
        p1 = 0;
    }

    if (op2 == '*' || op2 == '/') {
        p2 = 1;
    }
    else {
        p2 = 0;
    }

    return(p2 - p1);
}