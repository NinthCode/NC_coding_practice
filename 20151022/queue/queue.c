/*************************************************************************
	> File Name: queue.c
	> Author: NinthCode
	> Mail: admin@ninthcode.com 
	> Created Time: Thu 22 Oct 2015 12:48:31 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"queue.h"
void push(Queue *pQueue,void *pNode)
{
	if(pQueue == NULL)
	{
		return ;
	}
	QueueNode *pTemp = (QueueNode*)malloc(sizeof(QueueNode));
	pTemp->pNode = pNode;
	pTemp->pNext = NULL;
	if(pQueue->pFront == NULL)
	{
		pQueue->pFront = pTemp;
	}
	else
	{
		pQueue->pTail->pNext = pTemp;
	}
	pQueue->pTail = pTemp;
}
void pop(Queue *pQueue)
{
	if(pQueue == NULL || pQueue->pFront == NULL)
	{
		return ;
	}
	QueueNode *pDel = pQueue->pFront;
	pQueue->pFront = (pQueue->pFront)->pNext;
	free(pDel);
	pDel = NULL;
}
void* front(Queue *pQueue)
{
	if(pQueue == NULL || pQueue->pFront == NULL)
	{
		return NULL;
	}
	return pQueue->pFront->pNode;
}
void* tail(Queue* pQueue)
{
	if(pQueue == NULL || pQueue->pFront == NULL)
	{
		return NULL;
	}
	return pQueue->pTail->pNode;
}
int empty(Queue *pQueue)
{
	if(pQueue == NULL || pQueue->pFront == NULL)
	{
		return 1;
	}
	return 0;
}
void del(Queue **pQueue,void (*self_del)(void*))
{
	if(pQueue == NULL || *pQueue == NULL|| self_del == NULL)
	{
		return ;
	}
	void *pTemp = NULL;
	while(!empty(*pQueue))
	{
		pTemp = front(*pQueue);
		pop(*pQueue);
		self_del(pTemp);
	}
	free(*pQueue);
	*pQueue = NULL;
}

Queue* create_queue()
{
	Queue *pTemp = (Queue*)malloc(sizeof(Queue));
	pTemp->pFront = NULL;
	pTemp->pTail = NULL;
	pTemp->push = push;
	pTemp->pop = pop;
	pTemp->front = front;
	pTemp->tail = tail;
	pTemp->empty = empty;
	pTemp->del = del;
	return pTemp;
}
