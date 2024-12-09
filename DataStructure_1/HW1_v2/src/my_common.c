/*
32210086 강인창
Assignment 1

Added transpose and randArray function to common.c from gobhagi.
*/

#include<stdlib.h>
#include<stdio.h>
#include"my_common.h"

// create a 2-dimensional array with size rows x cols
int **array( int rows, int cols){
	int **arr;
	int i;

	arr = (int **) malloc( sizeof( int *) * rows );
	for( i=0; i<rows; i++)
	   arr[i] = (int *) malloc( sizeof( int ) * cols );

	return arr;
}

// create a 1-dimensional array with size rows
int *vector( int rows){
	int *vec;

	vec = (int *) malloc( sizeof( int ) * rows );

	return vec;
}

// deallocate a 2-dimensional array with size rows x cols
void freeArray( int **arr, int rows ){
	int r, c;
	for( r=0; r<rows; r++)
	    freeVector( arr[r] );

	free(arr);
}

// deallocate a 1-dimensional array 
void freeVector( int *vec ){
    free( vec );
}

// output the contents of a 2-dimensional array with a message msg
void printArray( int **arr, int rows, int cols, char *msg){
	int r, c;

	printf("%s\n", msg );
	for(r=0; r<rows; r++){
		for(c=0; c<cols; c++)
		   printf("\t %d", arr[r][c]);
		printf("\n");
	}
}

// output the contents of a 2-dimensional array with a message msg
void printVector( int *arr, int rows, char *msg){
	int r;

	printf("%s\n", msg );
	for(r=0; r<rows; r++){
	   printf("\t %d", arr[r]);
	}
	printf("\n");
}

// return an integer random number between 0 and range-1
int mrand(int range){
    return rand() % range;
}

//transposes matrix a into b
//a: m by n
//b: n by m
void transpose(int **a, int **b, int m, int n) {
    for(int r = 0; r < m; r++){
        for(int c = 0; c < n; c++) {
            b[c][r] = a[r][c];
        }
    }
}

//Fills matrix a with random values in given range.
//a: m by n
void randArray(int **a, int m, int n, int range) {
	for(int r=0; r<m; r++)
        for(int c=0; c<n; c++)
           a[r][c] = mrand( range );
}