#include<stdio.h>
#include<stdlib.h>
#include "common.h"

void multiplyTwoArrays( int **res, int **a, int **b, int m, int n, int q){
   int r, c, k;
   int sum;

    //matrix : a[m][n], b[n][q]
   for(r=0; r<m; r++)
      for(c=0; c<q; c++){
            sum = 0;
	    for(k=0; k<n; k++)
	        sum += a[r][k] + b[k][c];
	        res[r][c] = sum;
      }

    
}


int main(){
    int m = 10, n=5, q = 6;
    int r, c;
    int **a, **b, **res;

    a = array( m, n);
    b = array( n, q);
    res = array( m, q);

    /* assign some values to the arrays */
    for(r=0; r<m; r++)
        for(c=0; c<n; c++)
           a[r][c] = mrand( 10 );//난수 생성

    for(r=0; r<n; r++)
        for(c=0; c<q; c++)
           b[r][c] = mrand( 5 );

    /* multiply a[][] and b[][] */
    multiplyTwoArrays( res, a, b, m, n, q);
    printArray( a, m, n, "A");
    printArray( b, n, q, "B");
    printArray( res, m, q, "C");

    freeArray(a, m);
    freeArray(b, n);
    freeArray(res, m);

    return 0;
}
