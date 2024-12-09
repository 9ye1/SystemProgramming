#ifndef _POLYA_

#define _POLYA_

typedef struct poly {
    double coef;
    int exp;
} poly;

poly* makePolyArray(double input[], int size);
void printPolyArray(poly* pa);

#endif