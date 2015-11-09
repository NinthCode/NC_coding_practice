#include <stdio.h>
#include <stdlib.h>
typedef struct LISTNODE{
	int val;
	struct LISTNODE *next;
}ListNode;
void insert_node(ListNode **pHead,ListNode **pTail,int val);
void show_list(ListNode *pHead);
void delete_list(ListNode **pHead);
void turn_list(ListNode **pHead,ListNode **pTail);

int main()
{
	int i = 0;
	ListNode *pHead = NULL,*pTail = NULL;
	for(i = 0;i < 10;i++)
	{
		insert_node(&pHead,&pTail,i);
	}
	//show_list(pHead);
	turn_list(&pHead,&pTail);
	show_list(pHead);
	delete_list(&pHead);
	return 0;
}

void insert_node(ListNode **pHead,ListNode **pTail,int val)
{
	ListNode *pTemp = (ListNode*)malloc(sizeof(ListNode));
	pTemp->val = val;
	pTemp->next = NULL;
	if(*pHead == NULL)
	{
		*pHead = pTemp;	
	}
	else
	{
		(*pTail)->next = pTemp;
	}
	(*pTail) = pTemp;
}
void show_list(ListNode *pHead)
{
	while(pHead)
	{
		printf("%d\n",pHead->val);
		pHead = pHead->next;
	}
}
void delete_list(ListNode **pHead)
{
	ListNode *pDel = NULL;
	while(*pHead)
	{
		pDel = *pHead;
		(*pHead) = (*pHead)->next;
		free(pDel);
	}
}
void turn_list(ListNode **pHead,ListNode **pTail)
{
	ListNode *pNext = NULL;
	ListNode *pNow = (*pHead);
	ListNode *pPrev = pNow->next;
	if(pHead == NULL || *pHead == NULL || pTail == NULL)
	{
		return ;
	}
	*pTail = *pHead;
	while(pPrev)
	{
		pNext = pPrev->next;
		pPrev->next = pNow;
		pNow = pPrev;
		pPrev = pNext;
	}
	(*pTail)->next = NULL;
	(*pHead) = pNow;
}
