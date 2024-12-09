#ifndef _STACK_

#define _STACK_

#define LEN 10
struct stack {
  int  top;
  char item[LEN];
};

int isfull(struct stack *ps);
int isempty(struct stack *ps);
void push(struct stack *ps,char a);
void pop(struct stack *ps);
void display(struct stack *ps);

#endif