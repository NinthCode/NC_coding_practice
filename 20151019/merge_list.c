/*************************************************************************
	> File Name: merge_list.c
	> Author: ninthcode
	> Mail: admin@ninthcode.com 
	> Created Time: Mon 19 Oct 2015 11:09:26 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct LISTNODE
{
	int val;
	struct LISTNODE *next;
}ListNode;
ListNode* create_list(int i_start_seed);
void show_list(ListNode *p_head);
ListNode* merge_list(ListNode *p_list_one,ListNode *p_list_two);
ListNode* merge_list_iterator(ListNode *p_list_one,ListNode *p_list_two);

int main()
{
	ListNode *p_list_one = create_list(1);
	ListNode *p_list_two = create_list(2);
	show_list(p_list_one);
	show_list(p_list_two);
	p_list_one = merge_list_iterator(p_list_one,p_list_two);
	show_list(p_list_one);
	return 0;
}

ListNode* create_list(int i_start_seed)
{
	int i_count = 0;
	ListNode *p_temp = NULL;
	ListNode *p_head = NULL;
	p_head = (ListNode*)malloc(sizeof(ListNode));
	p_head->val = i_start_seed;
	p_head->next = NULL;
	p_temp = p_head;
	for(i_count = 1;i_count < 10;i_count++)
	{
		p_temp->next = (ListNode*)malloc(sizeof(ListNode));
		p_temp->next->val = i_start_seed + i_count;
		p_temp->next->next = NULL;
		p_temp = p_temp->next;
	}
	return p_head;
}
void show_list(ListNode *p_head)
{
	while(p_head)
	{
		printf("%d\t",p_head->val);
		p_head = p_head->next;
	}
	printf("\n");

}
ListNode* merge_list(ListNode *p_list_one,ListNode *p_list_two)
{
	if(p_list_one == NULL)
	{
		return p_list_two;
	}
	else if(p_list_two == NULL)
	{
		return p_list_one;
	}
	ListNode *p_temp = NULL;
	if(p_list_one->val < p_list_two->val)
	{
		p_temp = p_list_one;
		p_temp->next = merge_list(p_list_one->next,p_list_two);
	}
	else
	{
		p_temp = p_list_two;
		p_temp->next = merge_list(p_list_one,p_list_two->next);
	}
	return p_temp;
}
ListNode* merge_list_iterator(ListNode *p_list_one,ListNode *p_list_two)
{
	ListNode *p_temp = NULL;
	ListNode *p_head = NULL;
	while(p_list_one && p_list_two)
	{
		if(p_list_one->val < p_list_two->val)
		{
			p_temp = p_list_one;
			p_list_one = p_list_one->next;
		}
		else
		{
			p_temp = p_list_two;
			p_list_two = p_list_two->next;
		}
		if(!p_head)
		{
			p_head = p_temp;
		}
		p_temp = p_temp->next;
	}
	if(p_list_one || p_list_two)
	{
		if(p_head)
		{
			p_temp = p_list_one?p_list_one:p_list_two;
		}
		else
		{
			return p_list_one?p_list_one:p_list_two;
		}
	}
	return p_head;
}
