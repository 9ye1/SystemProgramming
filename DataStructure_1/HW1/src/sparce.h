#ifndef _SPARCE_

#define _SPARCE_

typedef struct MATRIX{
int row;
int col;
int value;
} MATRIX;

void bubble(int *a, int n);
void randSparce(MATRIX* a, int m, int n, int range);
void toSparce(int **a, int m, int n, MATRIX *b);
void sortSparce(MATRIX *a);
void transposeSparce (MATRIX *a, MATRIX *b);
void transposeSparceNoSort(MATRIX *a, MATRIX *b);
void printSparce(MATRIX* a);
void printSparceArray(MATRIX* a);

int getValue(int r, int c, MATRIX* s);
void multiplyTwoSparses(int **res, MATRIX *A, MATRIX *B);

#endif