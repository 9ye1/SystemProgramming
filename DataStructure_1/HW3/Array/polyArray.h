#ifndef _POLYA_

#define _POLYA_

typedef struct poly {
    double coef;
    int exp;
} poly;

poly* makePolyArray(double input[], int size);
void printPolyArray(poly* pa);
int compPolyExp(poly poly1, poly poly2);
poly addTwoPoly(poly poly1, poly poly2);
poly* addPolyArray(poly* pa1, poly* pa2);
poly* subPolyArray(poly* pa1, poly* pa2);

#endif