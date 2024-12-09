#include <stdio.h>

char que[100];
int front; 
int rear;

int main(){
    front = rear = -1;
    enq('a'); ena('b'); enq('c');
    printf("%c\n", deq());
    printf("%c\n", deq());
    printf("%c\n", deq());
}

void enq(char c){
    if(front == -1) front++;
    que[++rear] = c;
}

char deq(){
    char c = que[front];
    front++;
    if(front>rear) front=rear=-1;
    return c;
}