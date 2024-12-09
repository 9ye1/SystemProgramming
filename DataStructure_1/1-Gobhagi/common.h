#ifndef _COMMON_

#define _COMMON_

int **array( int, int );
int *vector( int );

void freeArray( int **, int );
void freeVector( int * );

void printArray( int **, int, int, char*);
void printVector( int *, int, char*);

int mrand(int range);

#endif
