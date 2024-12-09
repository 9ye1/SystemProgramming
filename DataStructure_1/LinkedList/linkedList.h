/**
 * linkedList.h 
 * @Author : 구예원
 * @Email : jastu111@naver.com
 * @Version : 1.0
 * @Date : 2022.12.03
*/

#ifndef _List_H_  /*#ifndef : 헤더파일의 중복을 막기 위함*/
#define _Lisr_H_


typedef int Element; /*value field of a node*/
typedef struct list_node *list_pointer; /*node pointer*/
typedef list_pointer List; /*a list pointer*/
typedef list_pointer Node; 
struct list_node{  /*definition of a node*/
    int value;
    list_pointer link;
};


int IsEmpty(List);
void WriteListItem(List);
List addItem(List, Element);
Node FindItem(List, Element);
List DeleteFirstItem(List);
List DeleteItem(List, Element);
List MakeListEmpty(List);


#endif /*_List_H_*/