/*
32210086 강인창

Polynomial array using structures.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polyArray.h"

poly* makePolyArray(double input[], int size) {
    int i, j;
    
    poly *polyArray = (poly*) malloc(sizeof(poly)*size/2);
    poly x;

    polyArray[0].coef = 0; //unused data
    polyArray[0].exp = size/2; //array size

    for(i = 0, j = 1; i<size; i+=2, j++) {
        x.coef = input[i];
        x.exp = input[i+1];
        polyArray[j] = x;
    }

    return polyArray;
}

void printPolyArray(poly* pa) {
    for(int i = 1; i <= pa[0].exp; i++) {
        if (pa[i].coef == 0) {
            continue;
        }
        if (i == 1) {
            printf("%.1fx^%d ", pa[i].coef, pa[i].exp);
        }
        else {
            if(pa[i].coef < 0) {
                printf("- ");
            }
            else {
                printf("+ ");
            }
            printf("%.1fx^%d ", fabs(pa[i].coef), pa[i].exp);
        }
    }
    printf("\n");
}