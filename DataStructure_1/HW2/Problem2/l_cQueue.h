#ifndef _L_CQUEUE_

#define _L_CQUEUE_

#include "dlist.h"

typedef List Queue;

int isFull(Queue q);
void enqueue(Queue *q, Element e);
void dequeue(Queue *q);
void display(Queue *q);
void freeQueue(Queue *q);

#endif