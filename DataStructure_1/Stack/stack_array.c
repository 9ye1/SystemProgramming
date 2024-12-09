// stack 구현 - 배열 사용
// 2022.10.10


#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

int stack[SIZE];
int top = 0;


bool isFull(){
    if(top==100) return true;
    else return false;
}

void push(int value){
    stack[top] = value;
    top++;
}

bool isEmpty(){
    if(top==0) return true;
    else return false;
}

void pop(){
    top--;
}

void display(){
    for(int i =0; i<top; i++){
        printf("%d ",stack[i]);
    }
    
}


int main(){
    int n, value;

    while(true){
        printf(" \n 1:push \n 2:pop \n 3:isFull \n 4:isEmpty \n 5:Display \n 6:Exit\n");
        scanf("%d",&n);
        printf("\n");
        if(n==1){
            printf("push : ");
            scanf("%d", &value);
            push(value);
            printf("push ok");
        }else if(n==2){
            if(top==0) printf("stack is empty");
            else{
                pop();
                printf("pop ok :: value = %d",stack[top]);
            }
        }else if(n==3){
            if(isFull()==true) printf("yes");
            else printf("no");
        }else if(n==4){
            if(isEmpty()==true) printf("yes");
            else printf("no");
        }else if(n==5){
            display();
        }else if(n==6){
            break;
        }
    }

}
