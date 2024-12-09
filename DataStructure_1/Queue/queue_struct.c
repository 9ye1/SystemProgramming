//Queue 구현 - struct 사용
//2020.10.11

#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

typedef struct {
    int stack[SIZE];
    int front, rear;
} Stack;



bool isFull(Stack* st){
    if(st->rear==SIZE) return true;
    else return false;
}

bool isEmpty(Stack* st){
    if(st->front==-1) return true;
    else return false;
}

void enQueue(Stack* st, int value){
    if(isFull(st)) printf("Queue is Full");
    else{
        if(isEmpty(st)) st->front++;
        st->stack[st->rear] = value;
        st->rear++;
        printf("enQueue ok");
    }

}

void deQueue(Stack* st){
    if(isEmpty(st)) printf("Queue is Empty");
    else {
        printf("enQueue ok, value : %d",st->stack[st->front]);
        st->front++;
        if(st->front==st->rear) st->front=-1; 
    }
}

void display(Stack* st){
    for(int i = st->front; i<st->rear; i++){
        printf("%d ",st->stack[i]);
    }
    
}


int main(){
    int n, value;
    Stack st;
    st.front=-1;
    st.rear=0;

    while(true){
        printf(" \n 1:enQueue \n 2:deQueue \n 3:Display \n 4:Exit\n");
        scanf("%d",&n);
        printf("\n");
        if(n==1){
            printf("enQueue : ");
            scanf("%d", &value);
            enQueue(&st,value);
        }else if(n==2){
            deQueue(&st);
        }else if(n==3){
            display(&st);
        }else if(n==4){
            break;
        }
    }

}
