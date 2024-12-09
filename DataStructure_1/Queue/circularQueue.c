#include<stdio.h>

#define QSIZE 5
#define T 1
#define F 0

struct queue {
 int item[QSIZE];
 int front,rear;
 int lastOp;
};

int isEmpty(struct queue *pq) {
   if (pq->rear == pq->front && pq->lastOp) {
      return 1;
   }
   else return 0;
}

int isFull(struct queue *pq) {
   if (pq->rear == pq->front && !pq->lastOp) {
      return 1;
   }
   else return 0;
}

void enqueue(struct queue *pq,int n) {
 if(isFull(pq)) {
    printf("\nqueue is full\n");
 } else {
      pq->rear = (pq->rear+1) % QSIZE;
      pq->item[pq->rear]=n;
      pq->lastOp = F;
 }
}

void dequeue(struct queue *pq) {
 int i=pq->front;
   if(isEmpty(pq))
   {
      printf("\nqueue is empty\n");
   }
   else                                 /*same as priority queue*/
   {
      pq->front = (pq->front+1) % QSIZE;
      pq->lastOp = T;
   }
}

void display(struct queue *pq) {
   int i = (pq->front+1) % QSIZE;
   if(isEmpty(pq)) {
      printf("\nqueue is empty\n");
   }
   else {
      while(T) {
         printf("\n%d",pq->item[i]);
         if(i == pq->rear) {
            break;
         }
         i = (i+1)%QSIZE;
      }
   }
}

int main(void) {
   struct queue q;
   int ch,n;
   q.front=0;
   q.rear=0;
   q.lastOp=T;

   do {
   printf("\nenter choice:\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
   scanf(" %d",&ch);
   switch(ch)
      {
         case 1: printf("\nenter integar to enqueue:");
               scanf("%d",&n);
               enqueue(&q,n);
               break;

         case 2: dequeue(&q);
               break;

         case 3: display(&q);
               break;
      }
   } while(ch!=4);

   return 0;
}