#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int data;
    struct _node* next;
}Node;

typedef struct _queue
{
    Node* front;
    Node* rear;
}Queue;

Queue* createQueue(){
    Queue* q= malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(int data, Queue* q){
    
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL; 
    if(q->front==NULL){
        q->front=newNode;
    }else{
        q->rear->next = newNode;
    }
    q->rear = newNode;

}

int deQueue(Queue* q){

    int data = q->front->data;

    if(q->front==q->rear){ //큐에 노드가 한 개 남으면
        q->rear=NULL;
    }
    q->front = q->front->next;
    

    return data;
}

int main(){

    Queue * queue = createQueue();
    
    enQueue(1,queue);
    enQueue(3,queue);
    enQueue(5,queue);

    printf("%d\n", deQueue(queue));
    printf("%d\n", deQueue(queue));
    printf("%d\n", deQueue(queue));
    return 0;
}

//isQueueEmty()
//SizeOfQueue()
//QueueCount()