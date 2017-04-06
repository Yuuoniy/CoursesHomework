#include <stdlib.h>
#include <stdio.h>
#include "stack.h"


void pop(Stack *s)
{
	Node *Pt = (*s).top;
	(*s).top = (*s).top->next;
	free(Pt); 
	(*s).size--;
	
}
int top(Stack *s)
{
	return (*s).top->data;
}
void push(Stack *s, int i)
{
	(*s).top = createNode(i, (*s).top) ;
	(*s).size++;
}
int size(Stack *s)
{
	return (*s).size;
}
int empty(Stack *s)
{
	if((*s).size==0)
		return 1;
	else 
		return 0;
}