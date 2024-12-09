#include <stdio.h>

long memo[10000];

long fib(int n){

    if(memo[n]!=0) return memo[n];

    if(n==0 || n==1) return n;

    memo[n] = fib(n-1)+fib(n-2);
    return memo[n];
    
};

int main(){
    for(int i =0; i<10000; i++){
        memo[i]=0;
    }
    printf(("%ld"), fib(44));
};