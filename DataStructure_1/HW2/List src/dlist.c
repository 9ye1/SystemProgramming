/*
32210086 강인창

Double Linked list.
*/

#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"


//change if element type changes
int compElement(Element e1, Element e2) {
    if (e1 == e2) {
        return T;
    }
    else return F;
}

void printElement(Element e) {
    printf("%c ", e);
}

int isEmpty(List L) {
    if (L == NULL) {
        return T;
    } else return F;
}


//change if element type changes
void writeListItem(List L) {
    if (isEmpty(L)) {
        printf("List is empty\n");
        return;
    }
    Node rnode = L;
    do {
        printElement(rnode->value);
        rnode = rnode->rlink;
    } while (rnode != L);
    printf("\n");
}

//add to rnode of L
List addItem(List L, Element e) {
    Node node, rnode;
    node = (Node) malloc(sizeof(list_node));
    if (node == NULL) {
        printf("Failed to allocate memory.");
        exit(1);
    }
    node->value = e;

    if (isEmpty(L)) {
        node->llink = node;
        node->rlink = node;
        L = node;
    } 
    else {
        rnode = L->rlink; //save original rnode
        L->rlink = node; //change L rlink to new node
        rnode->llink = node; //rnodes llink is new node

        //connect node to L and rnode
        node->rlink = rnode;
        node->llink = L;
    }
    return L;
}

Node findItem(List L, Element e) {
    Node node = L;
    do {
        if (compElement(node->value, e)) {
            return(node);
        }
        node = node->rlink;
    } while (node != L);

    printf("Element is not in List\n");
    return NULL;
}

//new L is L->rlink
//same as deleting any node
List deleteFirstItem(List L) {
    if (isEmpty(L)) {
        printf("List is empty\n");
        return L; //NULL
    }

    Node node = L; //to delete
    Node lnode = L->llink;
    L = L->rlink; //L is rlink

    if (node == L) { //if L is one element
        free(node);
        return NULL;
    }

    lnode->rlink = L;
    L->llink = lnode;

    free(node);
    return L;
}

List deleteItem(List L, Element e) {
    if (isEmpty(L)) {
        printf("List is empty\n");
        return L;
    }

    if(compElement(L->value, e)) {
        return deleteFirstItem;
    }

    Node node = L->rlink;
    while(node != L) {
        if (compElement(node->value, e)) {
            deleteFirstItem(node); //any node is "first" in DLL
        }
        node = node->rlink;
    }
    return L;
}

List makeListEmpty(List L) {
    if (isEmpty(L)) {
        printf("List is empty\n");
        return L;
    }
    Node end_node = L->llink;
    end_node->rlink = NULL; //termination point

    Node node = L;
    while(L != NULL) {
        L = node->rlink;
        free(node);
        node = L;
    }
    return L;
}