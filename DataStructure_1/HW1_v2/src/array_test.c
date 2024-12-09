/*
32210086 강인창
Assignment 1 - test for problem 1

main for testing array multiplication and element-wise arithmetic
*/
#include<stdio.h>
#include<stdlib.h>
#include "my_common.h"
#include "array_arith.h"

#define RANGE 10

int main(void){
    int m, n, q;
    int **a, **b, **res;
    int input;

    while(1) {
        printf("\n\nMatrix Calculator Menu\n");
        printf("---------------------------------\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Division(element-wise)\n");
        printf("4. Multiplication\n");
        printf("5. Exit\n");

        printf("Menu select: ");
        scanf(" %d", &input);

        if (1<= input && input <= 3) {
            printf("Array size(m n): ");
            scanf(" %d %d", &m, &n);

            a = array( m, n);
            b = array( m, n);
            res = array( m, n);
            randArray(a, m, n, RANGE);
            randArray(b, m, n, RANGE);

            if(input == 1) {
                addTwoArrays(res, a, b, m, n);
            }
            else if (input == 2) {
                subtractTwoArrays(res, a, b, m, n);
            }
            else {
                divideTwoArrays(res, a, b, m, n);
            }

            printArray( a, m, n, "A");
            printArray( b, m, n, "B");
            printArray( res, m, n, "C");

            freeArray(a, m);
            freeArray(b, m);
            freeArray(res, m);
        }
        else if ( input == 4) {
            printf("m by n times n by q array.\nEx) For [4x5] * [5x3], input: 4 5 3\n");
            printf("Array size(m n q): ");
            scanf(" %d %d %d", &m, &n, &q);

            a = array( m, n);
            b = array( n, q);
            res = array( m, q);

            randArray(a, m, n, RANGE);
            randArray(b, n, q, RANGE);

            multiplyTwoArrays(res, a, b, m, n, q);

            printArray( a, m, n, "A");
            printArray( b, n, q, "B");
            printArray( res, m, q, "C");

            freeArray(a, m);
            freeArray(b, n);
            freeArray(res, m);
        }
        else {
            break;
        }
    }
    return 0;
}
