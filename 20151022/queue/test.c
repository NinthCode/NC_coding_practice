/*************************************************************************
	> File Name: test.c
	> Author: NinthCode
	> Mail: admin@ninthcode.com 
	> Created Time: Thu 22 Oct 2015 01:30:53 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"queue.h"
void self_del(void *pVoid);

int main()
{
	Queue *pQueue = create_queue();
	int i;
	for(i = 0;i < 10;i++)
	{
		int *iTemp = (void*)malloc(sizeof(int));
		*iTemp = i;
		pQueue->push(pQueue,(void*)iTemp);
	}
	pQueue->del(&pQueue,self_del);
	return 0;
}
void self_del(void *pVoid)
{
	int *iTemp = (int*)pVoid;
	free(iTemp);
}

