#include <stdio.h>
#include <stdlib.h> //malloc

typedef struct _node{
    int data;
    struct _node* next;
}Node;

typedef struct _list
{
   Node* head;
    
}List;
Node* search(int data, List* list){
    Node* pPre = NULL;
    Node* pLoc = list->head;

    while(pLoc!=NULL && pLoc->data < data){
        pPre = pLoc;
        pLoc = pLoc->next;
    }

    return pPre;
}

void insert(int data, List* list){
    Node* pPre = search(data, list); 
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if(pPre==NULL){
        newNode->next = list->head;
        list->head = newNode;
    }else{
        newNode->next = pPre->next;
        pPre->next = newNode;
    }
}


void traverse(List* list){
    Node *p = list->head;
    while(p!=NULL){
        printf("%d --> ", p->data);
        p = p->next;
    }
    printf("\n");
}

void delete(int data, List* list){
    Node* pPre = search(data, list);
    if(pPre == NULL){
        list->head = list->head->next;
    }else{
        pPre->next = pPre->next->next;
    }
    //메모리 free 추가 구현
    //예외처리 : 해당 data가 list에 없을 경우 
}

int main(){

    List* list = malloc(sizeof(List));
    list->head = NULL;

    insert(2, list);
    insert(4, list);
    insert(7, list);

    traverse(list); //오름차순 -1 --> 2 --> 7

    delete(2, list); // -1 --> 7

    return 0;
}