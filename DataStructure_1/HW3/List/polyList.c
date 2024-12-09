/*
32210086 강인창

Polynomial list. Used linked list but code may be better if double linked list
was used to add to rear instead. (Change of whole current code is needed in this case)
*/

#include <stdio.h>
#include <stdlib.h>
#include "polyList.h"

//{coef exp ...}
List makePolyList(double input[], int size) {
    List fx = NULL;
    Element x;
    Node rear;

    for(int i = 0; i<size; i+=2) {
        x.coef = input[i];
        x.exp = input[i+1];
        if (i == 0) {
            fx = addItem(fx, x);
            rear = fx;
        } 
        else {
            addToNode(rear, x);
            rear = rear->link;
        }
    }

    return fx;
}

void printPolyList(List fx) {
    writeListItem(fx);
}

//compares exp
int compExp(Element e1, Element e2) {
    return e1.exp - e2.exp;
}

//returns e1 + e2 if exp is same
Element addTwoElement(Element e1, Element e2) {
    Element res = {0, 0};
    if (e1.exp != e2.exp) {
        printf("exp must be same\n");
    }
    else {
        res.coef = e1.coef + e2.coef;
        res.exp = e1.exp;
    }
    return res;
}

//returns the addition of two polyLists
List addPolyList(List l1, List l2) {
    List result = NULL;
    Element dummy = {0, 0}; //addToNode cannot be NULL
    result = addItem(result, dummy);
    Node rear = result;

    Node n1 = l1;
    Node n2 = l2;

    while(n1 && n2) { //if both not null
        if (compExp(n1->value, n2->value) == 0) {
            addToNode(rear, addTwoElement(n1->value, n2->value)); //adds 0 coef too
            n1 = n1->link;
            n2 = n2->link;
        } 
        else if (compExp(n1->value, n2->value) > 0) {
            addToNode(rear, n1->value);
            n1 = n1->link;
        }
        else {
            addToNode(rear, n2->value);
            n2 = n2->link;
        }
        rear = rear->link; //move rear
    }

    for(;n1;n1=n1->link) {
        addToNode(rear, n1->value);
        rear = rear->link;
    }
    for(;n2;n2=n2->link) {
        addToNode(rear, n2->value);
        rear = rear->link;
    }

    result = deleteFirstItem(result); //first node was dummy data
    return result;
}

List subPolyList(List l1, List l2) {
    //copy l2 while negating
    List temp = NULL;
    Element e = l2->value;
    e.coef = e.coef * -1;
    temp = addItem(temp, e); //add first item

    Node rear = temp;
    Node copy = l2->link;
    
    for(;copy; copy = copy->link) {
        e = copy->value;
        e.coef = e.coef * -1;
        addToNode(rear, e); //add rest to rear
        rear = rear->link;
    }

    return addPolyList(l1, temp);
}