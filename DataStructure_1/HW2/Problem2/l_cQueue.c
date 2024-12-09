/*
32210086 강인창
HW2 Problem 2

Circular queue implementation using double linked lists and will use list functions.
Element is char.

Uses call by reference.
*/

#include <stdio.h>
#include <stdlib.h>
#include "l_cQueue.h"

#define MAX 20

//change MAX to -1 for infinite queue
int isFull(Queue q) {
    if (MAX == -1 || isEmpty(q)) { //no need to check empty unless MAX==1
        return F;
    }

    //count nodes
    int count = 1; //include start
    Node node = q->rlink;
    while (node != q) {
        count++;
        node = node->rlink;
    }

    if (count == MAX) {
        return T;
    }
    else {
        return F;
    }
}

void enqueue(Queue *q, Element e) {
    if (isFull(*q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(*q)) {
        *q = addItem(*q, e);
        return;
    }

    addItem((*q)->llink, e); //add to rear, *q is same
}

void dequeue(Queue *q) {
    if (isEmpty(*q)) {
        printf("Queue is empty\n");
    }
    else {
        *q = deleteFirstItem(*q);
    }
}

void display(Queue *q) {
    Node node = *q;
    if (isEmpty(*q)) {
        printf("Queue is empty\n");
        return;
    }
    do {
        printElement(node->value);
        node = node->rlink;
    } while (node != *q);
}

void freeQueue(Queue *q) {
    *q = makeListEmpty(*q);
}