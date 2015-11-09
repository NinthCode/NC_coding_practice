/*************************************************************************
	> File Name: struct_shift_point_test.c
	> Author: NinthCode
	> Mail: admin@ninthcode.com 
	> Created Time: Fri 23 Oct 2015 01:51:18 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct NODE
{
	int iVal;
	struct NODE *pNext;
	void (*print_1)();
	void (*print_2)(int iTemp);
}Node;
Node* create_node();

int main()
{

}
void print_1()
{
	int *p = ()
	printf("I'm print one\n");
}
void print_2(int iTemp)
{
	printf("I'm %d\n",iTemp);
}
Node* create_node()
{
	Node *pTemp = (Node*)malloc(sizeof(Node));
	pTemp->iVal = 100;
	pTemp->pNext = NULL;
	pTemp->print_1 = print_1;
	pTemp->print_2 = print_2;
}

