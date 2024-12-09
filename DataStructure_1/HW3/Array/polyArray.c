/*
32210086 강인창

Polynomial array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polyArray.h"

poly* makePolyArray(double input[], int size) {
    int i, j;
    
    poly *polyArray = (poly*) malloc(sizeof(poly)*(size/2 + 1));
    poly x;

    polyArray[0].coef = size/2; //array size
    polyArray[0].exp = 0; //unused

    for(i = 0, j = 1; i<size; i+=2, j++) {
        x.coef = input[i];
        x.exp = input[i+1];
        polyArray[j] = x;
    }

    return polyArray;
}

void printPolyArray(poly* pa) {
    for(int i = 1; i <= pa[0].coef; i++) {
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

int compPolyExp(poly t1, poly t2) {
    return t1.exp - t2.exp;
}

//adds two terms together
poly addTwoPoly(poly t1, poly t2) {
    poly res = {0, 0};
    if (t1.exp != t2.exp) {
        printf("exp must be same\n");
    }
    else {
        res.coef = t1.coef + t2.coef;
        res.exp = t1.exp;
    }
    return res;
}

poly* addPolyArray(poly* pa1, poly* pa2) {
    int l1 = pa1[0].coef;
    int l2 = pa2[0].coef;

    poly* result = malloc(sizeof(poly)*(l1+l2+1)); //max term count

    int i, j, k;
    i = j = k = 1; //0 index is length
    while((i <= l1) && (j <= l2)) { //includes l1, l2
        if (compPolyExp(pa1[i], pa2[j]) == 0) {
            result[k++] = addTwoPoly(pa1[i], pa2[j]);
            i++;
            j++;
        } 
        else if (compPolyExp(pa1[i], pa2[j]) > 0) {
            result[k++] = pa1[i];
            i++;
        }
        else {
            result[k++] = pa2[j];
            j++;
        }
    }

    for(; i<=l1; i++) {
        result[k++] = pa1[i];
    }
    for(; j<=l2; j++) {
        result[k++] = pa2[j];
    }

    result[0].coef = k-1;
    result[0].exp = 0;

    return result;
}

poly* subPolyArray(poly* pa1, poly* pa2) {
    //copy pa2
    int length = pa2[0].coef;
    poly *temp = malloc(sizeof(poly)*(length + 1));

    temp[0] = pa2[0];
    for(int i = 1; i <= length; i++) {
        temp[i] = pa2[i];
        temp[i].coef *= -1;
    }

    return addPolyArray(pa1, temp);

}