/*************************************************************************
	> File Name: print_from_top_to_button.c
	> Author: NinthCode
	> Mail: admin@ninthcode.com 
	> Created Time: Wed 21 Oct 2015 10:19:11 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct TREENODE
{
	int iVal;
	struct TREENODE *pLeft;
	struct TREENODE *pRight;
}TreeNode;
typedef struct QUEUENODE
{
	TreeNode *pNode;
	struct QUEUENODE *pNext;
}QueueNode;
typedef struct QUEUE
{
	QueueNode *pFront;
	QueueNode *pTail;
}Queue;
Queue queue;

TreeNode* create_tree();
void pre_order(TreeNode *pRoot);
void print_ttob(TreeNode *pRoot);
int main()
{
	TreeNode *pRoot = create_tree();
	pre_order(pRoot);
	printf("\n");
	print_ttob(pRoot);
	return 0;
}

TreeNode* create_tree()
{
	int iTemp;
	TreeNode *pRoot = NULL;
	scanf("%d",&iTemp);
	if(iTemp == -1)
	{
		return NULL;
	}
	pRoot = (TreeNode*)malloc(sizeof(TreeNode));
	pRoot->iVal = iTemp;
	pRoot->pLeft = create_tree();
	pRoot->pRight = create_tree();
	return pRoot;
}

void pre_order(TreeNode *pRoot)
{
	if(pRoot == NULL)
	{
		return ;
	}
	printf("%d ",pRoot->iVal);
	pre_order(pRoot->pLeft);
	pre_order(pRoot->pRight);
}

void pop()
{
	if(queue.pFront == NULL)
	{
		return;
	}
	QueueNode *pDel = queue.pFront;
	queue.pFront = (queue.pFront)->pNext;
	free(pDel);
	pDel = NULL;
}
void push(TreeNode *pNode)
{
	QueueNode *pTemp = (QueueNode*)malloc(sizeof(QueueNode));
	pTemp->pNode = pNode;
	pTemp->pNext = NULL;
	if(queue.pFront == NULL)
	{
		queue.pFront = pTemp;
	}
	else
	{
		(queue.pTail)->pNext = pTemp;
	}
	queue.pTail = pTemp;
}

TreeNode *get_front()
{
	if(queue.pFront == NULL)
	{
		return NULL;
	}
	return (queue.pFront)->pNode;
}
int empty()
{
	return (queue.pFront == NULL)?1:0;
}
void del_queue()
{
	while(queue.pFront)
	{
		pop();
	}
	queue.pTail = NULL;
}

void print_ttob(TreeNode *pRoot)
{
	if(pRoot == NULL)
	{
		return ;
	}
	push(pRoot);
	TreeNode *pTemp = NULL;
	while(!empty())
	{
		pTemp = get_front();
		pop();
		printf("%d ",pTemp->iVal);
		if(pTemp->pLeft)
		{
			push(pTemp->pLeft);
		}
		if(pTemp->pRight)
		{
			push(pTemp->pRight);
		}
	}
	printf("\n");
}
