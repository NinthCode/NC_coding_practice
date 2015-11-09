/*************************************************************************
	> File Name: get_min_stack.c
	> Author: NinthCode
	> Mail: admin@ninthcode.com 
	> Created Time: Wed 21 Oct 2015 10:44:24 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
void push(int iVal);
void pop();
int top();
int min();
typedef struct STACKNODE
{
	int iVal;
	struct STACKNODE *pPrev;
}StackNode,*pSNode;
pSNode pDataTop = NULL;
pSNode pMinTop = NULL;
int main()
{
	int i,j;
	for(i = 10;i > 0;i--)
	{
		push(i);
		printf("%d\t",min());
	}
	printf("\n");
	for(i = 10;i > 0;i--)
	{
		pop();
		printf("%d\t",min());
	}
	printf("\n");
	return 0;
}
void push(int iVal)
{
	pSNode pTemp = NULL;
	if(pDataTop == NULL)
	{
		pDataTop = (pSNode)malloc(sizeof(StackNode));
		pMinTop = (pSNode)malloc(sizeof(StackNode));
		pDataTop->iVal = iVal;
		pDataTop->pPrev = NULL;
		pMinTop->iVal = iVal;
		pMinTop->pPrev = NULL;
	}
	else
	{
		pTemp = (pSNode)malloc(sizeof(StackNode));
		pTemp->iVal = iVal;
		pTemp->pPrev = pDataTop;
		pDataTop = pTemp;
		if(iVal < min())
		{
			pTemp = (pSNode)malloc(sizeof(StackNode));
			pTemp->iVal = iVal;
			pTemp->pPrev = pMinTop;
			pMinTop = pTemp;
		}
	}
}
void pop()
{
	if(pDataTop == NULL || pMinTop == NULL)
	{
		return ;
	}
	pSNode pDel = NULL;
	if(pMinTop->iVal == pDataTop->iVal)
	{
		pDel = pMinTop;
		pMinTop = pMinTop->pPrev;
		free(pDel);
		pDel = NULL;
	}
	pDel = pDataTop;
	pDataTop = pDataTop->pPrev;
	free(pDel);
	pDel = NULL;
}
int top()
{
	if(pDataTop != NULL)
	{
		return pDataTop->iVal;
	}
	return -1;
}
int min()
{
	if(pMinTop != NULL)
	{
		return pMinTop->iVal;
	}
	return -1;
}
