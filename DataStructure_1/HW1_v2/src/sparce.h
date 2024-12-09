#ifndef _SPARCE_

#define _SPARCE_

typedef struct MATRIX{
int row;
int col;
int value;
} MATRIX;

void bubble(int *a, int n);
MATRIX* randSparce(int m, int n, int range, double percent);
void toSparce(int **a, int m, int n, MATRIX *b);
void transposeSparce (MATRIX *a, MATRIX* b);
void transposeSparceNoSort(MATRIX *a, MATRIX *b);
void printSparce(MATRIX* a);
void printSparceArray(MATRIX* a);

int getValue(int r, int c, MATRIX* s);
void multiplyTwoSparses(int **res, MATRIX *A, MATRIX *B);

#endif