#ifndef _DList_H_
#define _DList_H_

#define T 1
#define F 0

typedef char Element; //change element depending on useage
typedef struct list_node *list_pointer;
typedef list_pointer List;
typedef list_pointer Node;
typedef struct list_node {
    Element value;
    list_pointer llink;
    list_pointer rlink;
} list_node;

int compElement(Element, Element);
void printElement(Element);
int isEmpty(List);
void writeListItem( List );
List addItem( List, Element);
Node findItem( List, Element);
List deleteFirstItem( List );
List deleteItem(List, Element);
List makeListEmpty( List );

#endif