//Stack 구현 - 메모리 동적 할당
//2020.10.10

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int top=0;

void isFull(int size){
    if(top==size) printf("yes");
    else printf("no");
}

void push(int* st, int value){
    st[top] = value;
    top++;
    printf("push ok");    
}

void isEmpty(int* st){
    if(top==0) printf("yes");
    else printf("no");
}

void pop(int* st){
    if(top == 0) printf("Stack is Empty");
    else {
        top--;
        printf("pop ok, value : %d",st[top]);
    }
}

void display(int* st){
    for(int i=0; i<top; i++){
        printf("%d ",st[i]);
    }
    
}


int main(){
    int n,size, value;
    
    printf("Making Stack with dynamic memory. SIZE :");
    scanf("%d",&size);
    int *stack = (int*)malloc(sizeof(int) * size);

    while(true){
        printf(" \n 1:push \n 2:pop \n 3:isFull \n 4:isEmpty \n 5:Display \n 6:Exit\n");
        scanf("%d",&n);
        printf("\n");
        if(n==1){
            if(top>=size) printf("Stack is Full");
            else{
                printf("push : ");
                scanf("%d", &value);
                push(stack,value);
            }
            
        }else if(n==2){
            pop(stack);
        }else if(n==3){
            isFull(size);
        }else if(n==4){
            isEmpty(stack);
        }else if(n==5){
            display(stack);
        }else if(n==6){
            break;
        }
    }

    free(stack);
}
