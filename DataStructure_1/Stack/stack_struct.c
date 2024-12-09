//Stack 구현 - struct 사용
//2020.10.10

#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

typedef struct {
    int stack[SIZE];
    int top;
} Stack;


void isFull(Stack* st){
    if(st->top==100) printf("yes");
    else printf("no");
}

void push(Stack* st, int value){
    st->stack[st->top] = value;
    st->top++;
    printf("push ok");
}

void isEmpty(Stack* st){
    if(st->top==0) printf("yes");
    else printf("no");
}

void pop(Stack* st){
    if(st->top == 0) printf("Stack is Empty");
    else {
        st->top--;
        printf("pop ok, value : %d",st->stack[st->top]);
    }
}

void display(Stack* st){
    for(int i =0; i<st->top; i++){
        printf("%d ",st->stack[i]);
    }
    
}


int main(){
    int n, value;
    Stack st;
    st.top=0;

    while(true){
        printf(" \n 1:push \n 2:pop \n 3:isFull \n 4:isEmpty \n 5:Display \n 6:Exit\n");
        scanf("%d",&n);
        printf("\n");
        if(n==1){
            printf("push : ");
            scanf("%d", &value);
            push(&st,value);
        }else if(n==2){
            pop(&st);
        }else if(n==3){
            isFull(&st);
        }else if(n==4){
            isEmpty(&st);
        }else if(n==5){
            display(&st);
        }else if(n==6){
            break;
        }
    }

}
