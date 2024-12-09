#include <stdio.h>
#include "sparce.h"

int main(void) {
    MATRIX a[101];
    MATRIX b[101];
    MATRIX c[101];
    randSparce(a, 10, 20, 10);
    printSparce(a);
    printf("\n-------------------------\n");

    transposeSparce(a, b);
    printSparce(b);
    printf("\n-------------------------\n");
    transposeSparceNoSort(a, c);
    printSparce(c);

    return 0;
}