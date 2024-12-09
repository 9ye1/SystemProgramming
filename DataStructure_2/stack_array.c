#include <stdio.h>

int stack[100];
int top =-1;

void push(int d){
    stack[++top]=d;
}
void pop(){
    int d = stack[top];
    top--;
    return d;
}
int main(){
    push(2);
    push(6);
    push(3);
    pop();
}