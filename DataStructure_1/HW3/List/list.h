#ifndef _List_H_
#define _List_H_

#define T 1
#define F 0

typedef struct Element {
    double coef;
    int exp;
} Element;
typedef struct list_node *list_pointer;
typedef list_pointer List;
typedef list_pointer Node;
typedef struct list_node {
    Element value;
    list_pointer link;
} list_node;

int compElement(Element, Element);
int isEmpty(List);
void writeListItem( List );
List addItem( List, Element);
Node findItem( List, Element);
List deleteFirstItem( List );
List deleteItem(List, Element);
List makeListEmpty( List );
void addToNode(Node, Element);

#endif