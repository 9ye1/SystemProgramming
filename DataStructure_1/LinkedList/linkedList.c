/**
 * linkedList :  링크드 리스트 구현  
 * @Author : 구예원
 * @Email : jastu111@naver.com
 * @Version : 1.0
 * @Date : 2022.12.03
*/

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int IsEmpty(List L){
    if(L == NULL){
        return 1;
    }else{
        return 0;
    }
}

void WriteListItem(List L){
    list_pointer tnode;
    tnode = L;
    while(tnode!=NULL){
        print("%d\t",tnode->value);
        tnode=tnode->link;
    }

}
List addItem(List L, Element el){
    list_pointer ptrNode;
    ptrNode = (list_pointer)malloc(sizeof(struct list_node));
    if(ptrNode ==NULL){
        print("::Unable to allocate more memory!!!\n");
        exit(0);
    }
    ptrNode->value = el;
    ptrNode->link = L;
    L=ptrNode;
}

Node FindItem(List L, Element el){
    Node tnode; /*list_pointer*/
    tnode = L;
    while(tnode!=NULL){
        if(L->value == el){
            return tnode;
        }else{
            tnode = tnode->link;
        }
    }
    print("%d does not exist",el);
    return NULL;
}

List DeleteFirstItem(List L){
    Node anode = L;
    if(anode=NULL){
        print("L is empty\n");
    }else{
        L = anode->link;
        free(anode);
    }
    return L;
}


List DeleteItem(List L, Element el){
    
}
List MakeListEmpty(List L){
    
}

