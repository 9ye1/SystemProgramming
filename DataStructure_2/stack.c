#include <stdio.h>


typedef struct _node{
    int data;
    struct _node* next;

}Node;

typedef struct _stack{

    int count;
    Node* top;
}Stack;

Stack* createStack(){
    Stack* stack = malloc(sizeof(Stack));
    stack->count = 0; 
    stack->top = NULL;
    return stack;
}

void push(int d, Stack* s){
    Node* newNode  = malloc(sizeof(Node));
    newNode->data=d;
    newNode->next=s->top;
}

int pop(Stack* s){

    if(s->count<=0) return -1;
    int d = s->top->data;
    Node* p = s->top;
    
    s->top = s->top->next;
    s->count--;

    free(p);
    return d;
}

int main(){
    Stack* stack = createStack();

    push(2, stack);
    push(6, stack);
    push(3, stack);

    printf(pop(stack));
    printf(pop(stack));
    printf(pop(stack));

    return 0;
}