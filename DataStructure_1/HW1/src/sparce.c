/*
32210086 강인창
Assignment 1

Added transpose and randArray function to common.c from gobhagi.
*/

#include <stdio.h>
#include <stdlib.h>
#include "sparce.h"

void randSparce(MATRIX* a, int m, int n, int range) {
    int val;
    int count = m*n / 10;  //10%
    a[0].row = m;
    a[0].col = n;
    a[0].value = count;

    int* loc = malloc(sizeof(int)*count);

    // generate random r,c(sorted)
    int num, current = 0;
    while(current < count) {
        num = rand() % (n*m);
        int flag = 0;
        for (int i = 0; i < current; i++) {
            if (loc[i] == num) {
                flag = 1;
                break;
            }
        }
        if(!flag) {
            loc[current] = num;
            current++;
        }
    }
    bubble(loc, count);

    for(int i = 1; i<=count; i++) {
        val = (rand() % (range-1)) + 1; //val > 0

        a[i].row = loc[i-1] / m;
        a[i].col = loc[i-1] % m;
        a[i].value = val;
    }
}


void toSparce(int **a, int m, int n, MATRIX *b) {
    int count = 1;
    b[0].row = m;
    b[0].col = n;

    for(int i=0; i<m;i++) {
        for(int j=0; j<n; j++) {
            if(a[i][j]) {
                b[count].row = i;
                b[count].col = j;
                b[count].value = a[i][j];
                count++;
            }
        }
    }
    b[0].value = count;
    if ((count+1)*3 > m*n) {
        printf("Sparce matrix is not efficient for this matrix\n");
    }
}

//sort the sparce so that row then col is sorted in ascending order
void sortSparce(MATRIX *a) {
    for(int i = 0; i < a[0].value; i++) {
        for(int j = 1; j < a[0].value+1-i; j++) {
            if (a[j].row < a[j+1].row) {
                continue;
            }
            if (a[j].row == a[j+1].row && a[j].col < a[j+1].col) {
                continue;
            }
            MATRIX temp = {a[j].row, a[j].col, a[j].value};
            a[j] = a[j+1];
            a[j+1] = temp;
        }
    }
}

void transposeSparce (MATRIX *a, MATRIX *b) {
    int n, i, j, currentb;

    n = a[0].value; b[0].row = a[0].col; //2
    b[0].col = a[0].row; b[0].value = n; //2
    if(n > 0) { //1
        currentb = 1; //1
        for(i = 0; i < a[0].col; i++) //b[0].row /m
            for(j = 1; j <= n; j++) //check every element / mv
                if(a[j].col == i) { //5mv
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].value = a[j].value;
                    currentb++;
                }
    }
}

void transposeSparceNoSort(MATRIX *a, MATRIX *b) {
    int n;
    n = a[0].value; 
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = n;

    int currentb = 1;
    for(int i=1; i <= n; i++) {
        b[currentb].row = a[i].col;
        b[currentb].col = a[i].row;
        b[currentb].value = a[i].value;
        currentb++;
    }
}


void printSparce(MATRIX* a) {
    printf("[");
    for(int i = 1; i <= a[0].value; i++) {
        if (i != a[0].value) {
            printf("[%d, %d, %d],\n", a[i].row, a[i].col, a[i].value);
        }
        else {
            printf("[%d, %d, %d]", a[i].row, a[i].col, a[i].value);
        }
        
    }
    printf("]\n");
}

//prints as normal array
void printSparceArray(MATRIX* a) {
    int m, n;
    m = a[0].row;
    n = a[0].col;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("\t %d", getValue(i, j, a));
        }
        printf("\n");
    }
}

int getValue(int r, int c, MATRIX* s) {
    int k; 
    
    if( r < 0 || r >= s[0].row || c < 0 || c >= s[0].col ){ 
        printf("r or c index is out of range\n"); 
        return -999; 
    } 
    
    for(k=1; k<=s[0].value; k++){ 
        if( s[k].row==r && s[k].col==c) 
            return s[k].value; 
    } 
    return 0;
}


void multiplyTwoSparses( int **res, MATRIX *a, MATRIX *b ){
    int r, c, k;
    float csum;
    for(r = 0; r < a[0].row; r++){
        for( c = 0; c < b[0].col; c++){
            csum = 0;
            for( k = 0; k < a[0].col; k++)
                csum += getValue( r, k, a) * getValue( k, c, b);
            res[r][c] = csum;
        }
    }
}
