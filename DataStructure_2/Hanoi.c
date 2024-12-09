#include <stdio.h>



void hanoi(int n, char s, char d, char a){
    if(n==0) return;
    hanoi(n-1,s,a,d);
    printf("move disk from %c to %c/n", s, d);
    hanoi(n-1,a,d,s);


}

void main(){
    hanoi(5,'s','a','d');
    return 0;
}