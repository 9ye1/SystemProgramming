/*
32210086 강인창
Assignment 1

Code for testing problem 3 transpose functions and sparce matrix
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_common.h"
#include "sparce.h"

#define RANGE 10

int main(void) {
    MATRIX *a, *b;
    int **a2, **b2;
    int m1 = 10;
    int n1 = 20;
    int m2 = 5;
    int n2 = 7;
    printf("---------Sparce---------\n");
    a = randSparce(m1, n1, RANGE, 10); //10%
    printSparce(a);
    printf("----Transposed Sparce----\n");
    b = malloc(sizeof(MATRIX) * (a[0].value+1));
    transposeSparce(a, b);
    printSparce(b);

    printf("\n-----Normal Matrix-----\n");
    a2 = array(m2, n2);
    b2 = array(n2, m2);
    randArray(a2, m2, n2, RANGE);
    printArray(a2, m2, n2, "A");
    printf("----Transposed Sparce----\n");
    transpose(a2, b2, m2, n2);
    printArray(b2, n2, m2, "A transposed");


    free(a);
    free(b);
    freeArray(a2, m2);
    freeArray(b2, n2);
    return 0;
}