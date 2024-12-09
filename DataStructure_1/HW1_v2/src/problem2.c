/*
32210086 강인창
Assignment 1 - code for batch testing problem 2

Input: (menu) m1 n1 m2 n2....
(for multiplication: 4 m1 n1 q1 m2 n2 q2...)

Output: (menu) m n (m*n) time
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "my_common.h"
#include "array_arith.h"

#define RANGE 10

int main(void) {
    clock_t start, stop;
    double duration;
    int input;
    char data[100];
    char *token;
    int **a, **b, **res;
    int m, n, q;

    printf("\n\nMatrix Calculator Test Menu\n");
    printf("---------------------------------\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Division(element-wise)\n");
    printf("4. Multiplication\n");

    printf("Menu and data: ");
    fgets(data, 100, stdin);
    token = strtok(data, " ");
    input = atoi(token);

    token = strtok(NULL, " ");
    while( token != NULL ) {
        if (input != 4) {
            m = atoi(token);  
            token = strtok(NULL, " ");
            if (token == NULL) {
                printf("Data is not correct\n");
                break;
            }

            n = atoi(token);
            token = strtok(NULL, " ");

            a = array( m, n);
            b = array( m, n);
            res = array( m, n);
            randArray(a, m, n, RANGE);
            randArray(b, m, n, RANGE);

            //calculation
            start = clock();
            if(input == 1) {
                addTwoArrays(res, a, b, m, n);
            }
            else if (input == 2) {
                subtractTwoArrays(res, a, b, m, n);
            }
            else {
                divideTwoArrays(res, a, b, m, n);
            }
            stop = clock();
            duration = (double)(stop - start) / CLOCKS_PER_SEC ;

            freeArray(a, m);
            freeArray(b, m);
            freeArray(res, m);

            printf("%d %d %d %d %f\n", input, m, n, m*n, duration); 
        }
        else {
            m = atoi(token);  
            token = strtok(NULL, " ");

            if (token == NULL) {
                printf("Data is not correct\n");
                break;
            }
            n = atoi(token);
            token = strtok(NULL, " ");  

            if (token == NULL) {
                printf("Data is not correct\n");
                break;
            }  
            q = atoi(token);
            token = strtok(NULL, " "); 


            a = array( m, n);
            b = array( n, q);
            res = array( m, q);

            randArray(a, m, n, RANGE);
            randArray(b, n, q, RANGE);

            //calculation
            start = clock();
            multiplyTwoArrays(res, a, b, m, n, q);
            stop = clock();
            duration = (double)(stop - start) / CLOCKS_PER_SEC ;

            freeArray(a, m);
            freeArray(b, n);
            freeArray(res, m);

            printf("%d %d %d %d %d %f\n", input, m, n, q, m*n*q, duration);
        }
   }
   return 0;
}