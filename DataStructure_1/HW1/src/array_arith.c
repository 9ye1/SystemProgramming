/*
32210086 강인창
Assignment 1

Basic arithmetic functions for a normal 2d matrix.
*/

#include <stdio.h>
#include "array_arith.h"

//m by n matrix addition
void addTwoArrays(int **res, int **a, int **b, int m, int n) {
    for(int i = 0; i < m;i++){ //m
        for(int j = 0; j < n; j++) { //mn
            res[i][j] = a[i][j] + b[i][j]; //mn
        }
    }
}

//m by n matrix subtraction
void subtractTwoArrays(int **res, int **a, int **b, int m, int n) {
    for(int i = 0; i < m;i++){ //m
        for(int j = 0; j < n; j++) { //mn
            res[i][j] = a[i][j] - b[i][j]; //mn
        }
    }
}

//m by n matrix division(int division)
void divideTwoArrays(int **res, int **a, int **b, int m, int n) {
    for(int i = 0; i < m;i++){ //m
        for(int j = 0; j < n; j++) { //mn
            if (b[i][j] == 0) { //if -> mn, res -> mn
                res[i][j] = 999;
                continue;
            }
            res[i][j] = (int)a[i][j] / b[i][j];
        }
    }
}

//code from gobhagi
//a: m by n
//b: n by q
void multiplyTwoArrays( int **res, int **a, int **b, int m, int n, int q){
   int i, j, k;
   int sum;

   for(i=0; i<m; i++) //m
      for(j=0; j<q; j++){ //mq
        sum = 0; //mq
        for(k=0; k<n; k++) //mnq
            sum += a[i][k] * b[k][j]; //mnq
        res[i][j] = sum; //mq
      }
}

