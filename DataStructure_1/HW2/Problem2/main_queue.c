/*
32210086 강인창
Assignment 2 Circular queue

Implemented using Double linked lists. Main func code from queue.c provided from lecture.
*/

#include <stdio.h>
#include <stdlib.h>
#include "l_cQueue.h"

int main(void)
{
    Queue q = NULL;
    int ch;
    char c;

    do
    {
        printf("\nenter choice:\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        scanf(" %d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nenter char to enqueue:");
            scanf(" %c", &c);
            enqueue(&q, c);
            break;

        case 2:
            dequeue(&q);
            break;

        case 3:
            display(&q);
            break;
        }
    } while (ch != 4);
    if (!isEmpty(q))
    {
        freeQueue(&q);
    }

    return 0;
}