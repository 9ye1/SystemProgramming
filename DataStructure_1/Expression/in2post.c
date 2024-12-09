#include <stdio.h>
#include <string.h>
#include "stack.h"

#define MAX 80

int prioity(char op1, char op2);

int main(int argc, char const *argv[])
{
    char infix[MAX];
    struct stack s;
    s.top=-1;

    if (argc == 1) {
        printf("Input infix string: ");
        scanf(" %s", infix);
    }
    else if (argc == 2) {
        strcpy(infix, argv[1]);
    }
    else {
        return 1;
    }
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        //S1
        if (c == '(') {
            push(&s, c);
            continue;
        }

        //S2
        else if (c == ')') {
            while(!isempty(&s)) {
                pop(&s);
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
            if(isempty(&s) || prioity(s.item[s.top], c) == 1) {
                push(&s, c);
            }
            else {
                pop(&s);
                push(&s, c);
            }
        }
    }

    while(!isempty(&s)) {
        pop(&s);
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

