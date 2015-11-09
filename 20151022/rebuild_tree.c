/*************************************************************************
	> File Name: rebuild_tree.c
	> Author: NinthCode
	> Mail: admin@ninthcode.com 
	> Created Time: Thu 22 Oct 2015 02:02:06 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct TREENODE
{
	int iVal;
	struct TREENODE *pLeft;
	struct TREENODE *pRight;
}TreeNode;
TreeNode* rebuild_tree(int *pFront,int *pMiddle,int iLen);
void pre_order(TreeNode *pRoot);

int main()
{
	int iFront[] = {1,2,4,5,8,3,6,9,7};
	int iMiddle[] = {4,2,8,5,1,9,6,3,7};
	TreeNode *pRoot = rebuild_tree(iFront,iMiddle,9);
	pre_order(pRoot);
	return 0;
}

void pre_order(TreeNode *pRoot)
{
	if(pRoot == NULL)
	{
		return;
	}
	printf("%d ",pRoot->iVal);
	pre_order(pRoot->pLeft);
	pre_order(pRoot->pRight);
}

TreeNode* rebuild(int *pFrontStart,int *pFrontEnd,int *pMiddleStart,int *pMiddleEnd)
{
	int iRoot = *pFrontStart;
	TreeNode *pRoot = (TreeNode*)malloc(sizeof(TreeNode));
	pRoot->iVal = iRoot;
	pRoot->pLeft = pRoot->pRight = NULL;
	if(pFrontStart == pFrontEnd)
	{
		if(pMiddleStart == pMiddleEnd && *pFrontStart == *pMiddleStart)
		{
			return pRoot;
		}
		else
		{
			printf("input error\n");
			exit(1);
		}
	}
	int *pRootInMiddle = pMiddleStart;
	while(pRootInMiddle <= pMiddleEnd && *pRootInMiddle != iRoot)
	{
		++pRootInMiddle;
	}
	if(pRootInMiddle > pMiddleEnd)
	{
		printf("input error\n");
		exit(1);
	}
	int iLeftSubLength = pRootInMiddle - pMiddleStart;
	int *pLeftSubEnd = pFrontStart + iLeftSubLength;
	if(iLeftSubLength > 0)
	{
		pRoot->pLeft = rebuild(pFrontStart + 1,pLeftSubEnd,pMiddleStart,pRootInMiddle - 1);
	}
	if(iLeftSubLength < pFrontEnd - pFrontStart)
	{
		pRoot->pRight = rebuild(pLeftSubEnd + 1,pFrontEnd,pRootInMiddle + 1,pMiddleEnd);
	}
	return pRoot;
}
TreeNode* rebuild_tree(int *pFront,int *pMiddle,int iLen)
{
	if(pFront == NULL || pMiddle == NULL || iLen <= 0)
	{
		return NULL;
	}
	return rebuild(pFront,pFront + iLen - 1,pMiddle,pMiddle + iLen - 1);
}

