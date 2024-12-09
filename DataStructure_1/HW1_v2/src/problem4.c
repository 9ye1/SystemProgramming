/*
32210086 강인창
Assignment 1 - problem 4

Code for batch testing transpose funtion times.

Input: m1 n1 m2 n2....
Output: m n (sparce time) (array time)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "my_common.h"
#include "sparce.h"

#define RANGE 10

int main(void) {
    clock_t start, stop;
    double d1, d2;
    char data[100];
    char *token;
    MATRIX *a1, *b1;
    int **a2, **b2;
    int m, n;

    printf("Data: ");
    fgets(data, 100, stdin);
    token = strtok(data, " ");

    while( token != NULL ) {
        m = atoi(token);  
        token = strtok(NULL, " ");
        if (token == NULL) {
            printf("Data is not correct\n");
            break;
        }

        n = atoi(token);
        token = strtok(NULL, " ");

        //initialize matrixes
        a1 = randSparce(m, n, RANGE, 0.01); //0.01%
        b1 = malloc(sizeof(MATRIX) * (a1[0].value+1));
        a2 = array(m, n);
        b2 = array(n, m);
        randArray(a2, m, n, RANGE);

        //sparce time
        start = clock();
        transposeSparce(a1, b1);
        stop = clock();
        d1 = (double)(stop - start) / CLOCKS_PER_SEC;

        //sparce time
        start = clock();
        transpose(a2, b2, m, n);
        stop = clock();
        d2 = (double)(stop - start) / CLOCKS_PER_SEC;

        printf("%d %d %f %f\n", m, n, d1, d2);
    }
    return 0;
}