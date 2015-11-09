/*************************************************************************
	> File Name: is_pop_order.c
	> Author: NinthCode
	> Mail: admin@ninthcode.com 
	> Created Time: Wed 21 Oct 2015 11:26:23 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int is_pop_order(int *pPush,int *pPop,int iLength);

typedef struct STACKNODE
{
	int iVal;
	struct STACKNODE *pPrev;
}StackNode;

StackNode *pTop = NULL;
int main()
{
	int iPush[] = {1};
	int iPop[] = {1};
	printf("%d\n",is_pop_order(iPush,iPop,1));
	return 0;
}
void pop()
{
	if(pTop == NULL)
	{
		return;
	}
	StackNode *pDel = pTop;
	pTop = pTop->pPrev;
	free(pDel);
	pDel = NULL;
}
void push(int iVal)
{
	if(pTop == NULL)
	{
		pTop = (StackNode*)malloc(sizeof(StackNode));
		pTop->iVal = iVal;
		pTop->pPrev = NULL;
	}
	StackNode *pTemp = (StackNode*)malloc(sizeof(StackNode));
	pTemp->iVal = iVal;
	pTemp->pPrev = pTop;
	pTop = pTemp;
}
int top()
{
	if(pTop == NULL)
	{
		return -1;
	}
	return pTop->iVal;
}
void del()
{
	StackNode *pDel = NULL;
	while(pTop)
	{
		pDel = pTop;
		pTop = pTop->pPrev;
		free(pDel);
		pDel = NULL;
	}
}
int is_pop_order(int *pPush,int *pPop,int iLength)
{
	if(pPush == NULL || pPop == NULL || iLength <= 0)
	{
		return -1;	
	}
	int iPushIter = 0;
	int iPopIter = 0;
	while(iPopIter < iLength)
	{
		if(top() == pPop[iPopIter])
		{
			pop();
			++iPopIter;
		}
		else
		{
			while(iPushIter < iLength && top() != pPop[iPopIter])
			{

				push(pPush[iPushIter]);
				++iPushIter;
			}
			if(iPushIter >= iLength && top() != pPop[iPopIter])
			{
				return -1;
			}
		}
	}
	return 0;
}
