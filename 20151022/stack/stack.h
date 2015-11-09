/*************************************************************************
	> File Name: stack.h
	> Author: NinthCode
	> Mail: admin@ninthcode.com 
	> Created Time: Thu 22 Oct 2015 11:20:42 AM CST
 ************************************************************************/

#ifndef _STACK_H_
#define _STACK_H_
typedef struct STACKNODE
{
	void *pNode;
	struct STACKNODE *pPrev;
}StackNode;
typedef struct STACK
{
	StackNode *pTop;
	void (*push)(struct STACK *pStack,void *pNode);
	void (*pop)(struct STACK *pStack);
	void* (*top)(struct STACK *pStack);
	int (*empty)(struct STACK *pStack);
	void (*del)(struct STACK *pStack,void (*self_del)(void*));
}Stack;
Stack* create_stack();
#endif

