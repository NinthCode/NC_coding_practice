/*************************************************************************
	> File Name: test.c
	> Author: NinthCode
	> Mail: admin@ninthcode.com 
	> Created Time: Thu 22 Oct 2015 12:17:43 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

int main()
{
	Stack *pStack = create_stack();
	int i;
	for(i = 0;i < 10;i++)
	{
		int *iTemp = (int*)malloc(sizeof(int));
		*iTemp = i;
		pStack->push(pStack,(void*)iTemp);
	}
	while(!pStack->empty(pStack))
	{
		printf("%d ",*(int*)pStack->top(pStack));
		free(pStack->top(pStack));
		pStack->pop(pStack);
	}
	return 0;
}
