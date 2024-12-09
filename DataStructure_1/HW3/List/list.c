/*
32210086 강인창

Linked list.

Element is defined in list.h and may be changed to any type(including struct).
Any functions related to reading the element needs to be written case by case.(tradeoff)
Related code is commented.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"


//change if element type changes
int compElement(Element e1, Element e2) {
    if (e1.coef == e2.coef && e1.exp == e2.exp) {
        return T;
    }
    else return F;
}


int isEmpty(List L) {
    if (L == NULL) {
        return T;
    } else return F;
}

//Writes polynomial list
//Does not write anything when all 0
void writeListItem(List L) {
    Node node = L;
    while(node != NULL) {
        if (node->value.coef == 0) {
            node = node->link;
            continue;
        }

        if (node == L) {
            printf("%.1fx^%d ", node->value.coef, node->value.exp);
            
        }
        else {
            if (node->value.coef < 0) {
                printf("- ");
            }
            else {
                printf("+ ");
            }
            printf("%.1fx^%d ", fabs(node->value.coef), node->value.exp);
        }
    
        node = node->link;
    }
    printf("\n");
}


List addItem(List L, Element e) {
    Node node = (Node) malloc(sizeof(list_node));
    if (node == NULL) {
        printf("Failed to allocate memory.");
        exit(1);
    }

    node->value = e;
    node->link = L;
    L = node;
    return L;
}


Node findItem(List L, Element e) {
    Node node = L;
    while(node != NULL) {
        if (compElement(node->value, e)) {
            return node;
        }
        node = node->link;
    }
    printf("Element not found\n");
    return NULL;
}


List deleteFirstItem(List L) {
    Node node = L;
    if (node == NULL) {
        printf("List is empty\n");
    }
    else {
        L = node->link;
        free(node);    
    }
    return L;
}


List deleteItem(List L, Element e) {
    //check List and first item first
    if (L == NULL) {
        printf("List is empty\n");
        return L;
    }
    if (compElement(L->value, e)) {
        L = deleteFirstItem(L);
        return L;
    }

    Node node = L;
    Node dnode = node->link;

    while(dnode != NULL) {
        if (compElement(dnode->value, e)) {
            node->link = dnode->link;
            free(dnode);
            break;
        }
        node = dnode;
        dnode = node->link;
    }
    return L;
}



List makeListEmpty(List L) {
    Node node = L;
    while (L != NULL) {
        L = node->link; //careful what pointer it should be
        free(node);
        node = L;
    }
    return L;
}

void addToNode(Node node, Element e) {
    if (node == NULL) {
        printf("Use addItem() instead"); //void return
        return;
    }

    Node nextNode = node->link;
    Node newNode = (Node) malloc(sizeof(list_node));
    newNode->value = e;

    node->link = newNode;
    newNode->link = nextNode;
}