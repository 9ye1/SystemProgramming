/*
32210086 강인창

Array(선형 리스트) to save a polynomial f(x).
Simple implementation of polynomial.
*/

#include <stdio.h>
#include <stdlib.h>
#include "polyArray.h"

int main(void) {
    double input[] = {6.7, 4, 3.2, 3, -1, 2, 1, 1, -2, 0};
    int size = sizeof(input)/sizeof(double);
    
    poly* polyArr = makePolyArray(input, size);
    printPolyArray(polyArr, size/2);

    return 0;
}