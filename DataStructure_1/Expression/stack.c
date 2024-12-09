#include<stdio.h>

#define LEN 10

struct stack {
  int  top;
  char item[LEN];
};

//1 if full 0 if not
int isfull(struct stack *ps) {
  if(ps->top==LEN-1){
    return(1);
  } else {
    return(0);
  }
}

//1 if empty 0 if not
int isempty(struct stack *ps) {
  if(ps->top==-1){
    return(1);
  } else {
    return(0);
  }
}

void push(struct stack *ps,char a) {
  ps->top++;
  ps->item[ps->top]=a;
}

void pop(struct stack *ps) {
  char c = ps->item[ps->top];
  if (c != '(')
    printf("%c", ps->item[ps->top]);
  ps->top--;
}

void display(struct stack *ps) {
  int i=ps->top;
  printf("\nthe stack contains:\n");
  for(i=ps->top;i!=-1;--i) {
     printf("%c",ps->item[i]);
  }
}
