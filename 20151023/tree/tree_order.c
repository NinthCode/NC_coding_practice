/*************************************************************************
	> File Name: tree_order.c
	> Author: NinthCode
	> Mail: admin@ninthcode.com 
	> Created Time: Fri 23 Oct 2015 11:05:29 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct TREENODE
{
	int iVal;
	struct TREENODE *pLeft;
	struct TREENODE *pRight;
}TreeNode;
TreeNode* create_tree();
void pre_order_by_recursion(TreeNode *pRoot);
void pre_order_by_iterator(TreeNode *pRoot);
int main()
{
	TreeNode *pRoot = create_tree();

	return 0;
}

TreeNode* create_tree()
{
	int iTemp;
	TreeNode *pTemp;
	scanf("%d",&iTemp);
	if(iTemp == 0)
	{
		return NULL;
	}
	pTemp = (TreeNode*)malloc(sizeof(TreeNode));
	pTemp->iVal = iTemp;
	pTemp->pLeft = create_tree();
	pTemp->pRight = create_tree();
	return pTemp;
}
void pre_order_by_recursion(TreeNode *pRoot)
{
	if(pRoot == NULL)
	{
		return ;
	}
	printf("%d ",pRoot->iVal);
	pre_order_by_recursion(pRoot->pLeft);
	pre_order_by_recursion(pRoot->pRight);
}
void pre_order_by_iterator(TreeNode *pRoot)
{
	if(pRoot == NULL)
	{
		return ;
	}
	Stack *pStack = create_stack();
	while(pRoot || !pStack->empty(pStack))
	{
		while(pRoot)
		{
			printf("%d ",pRoot->iVal);
			pStack->push()
		}
	}
}
