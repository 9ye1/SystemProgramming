/*
32210086 강인창
Assignment 1

Added transpose and randArray function to common.c from gobhagi.
*/
#ifndef _COMMON_

#define _COMMON_

int **array( int, int );
int *vector( int );

void freeArray( int **, int );
void freeVector( int * );

void printArray( int **, int, int, char*);
void printVector( int *, int, char*);

int mrand(int range);

void transpose(int **a, int** b, int m, int n);
void randArray(int **a, int m, int n, int range);

#endif
