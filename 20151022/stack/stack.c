/*************************************************************************
	> File Name: stack.c
	> Author: NinthCode
	> Mail: admin@ninthcode.com 
	> Created Time: Thu 22 Oct 2015 11:51:15 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

void push(Stack *pStack,void *pNode)
{
	if(pStack == NULL)
	{
		return;
	}
	StackNode *pTemp = (StackNode*)malloc(sizeof(StackNode));
	pTemp->pNode = pNode;
	pTemp->pPrev = pStack->pTop;
	pStack->pTop = pTemp;
}
void pop(Stack *pStack)
{
	if(pStack == NULL || pStack->pTop == NULL)
	{
		return ;
	}
	StackNode *pDel = pStack->pTop;
	pStack->pTop = (pStack->pTop)->pPrev;
	free(pDel);
	pDel = NULL;
}
void* top(Stack *pStack)
{
	if(pStack == NULL || pStack->pTop == NULL)
	{
		return NULL;
	}
	return pStack->pTop->pNode;
}
int empty(Stack *pStack)
{
	return (pStack->pTop == NULL)?1:0;
}
void del(Stack *pStack,void (*self_del)(void*))
{
	if(pStack == NULL || self_del == NULL)
	{
		return;
	}
	StackNode *pDel = NULL;
	while(pStack->pTop)
	{
		pDel = pStack->pTop;
		pStack->pTop = pStack->pTop->pPrev;
		self_del(pDel->pNode);
		free(pDel);
		pDel = NULL;
	}
}
Stack* create_stack()
{
	Stack *pTemp = (Stack*)malloc(sizeof(Stack));
	pTemp->pTop = NULL;
	pTemp->push = push;
	pTemp->pop = pop;
	pTemp->top = top;
	pTemp->del = del;
	pTemp->empty = empty;
	return pTemp;
}
