/*************************************************************************
	> File Name: queue.h
	> Author: NinthCode
	> Mail: admin@ninthcode.com 
	> Created Time: Thu 22 Oct 2015 12:28:31 PM CST
 ************************************************************************/
#ifndef _QUEUE_H_
#define _QUEUE_H_
typedef struct QUEUENODE
{
	void *pNode;
	struct QUEUENODE *pNext;
}QueueNode;
typedef struct QUEUE
{
	QueueNode *pFront;
	QueueNode *pTail;
	void (*push)(struct QUEUE *pQueue,void *pNode);
	void (*pop)(struct QUEUE *pQueue);
	void* (*front)(struct QUEUE *pQueue);
	void* (*tail)(struct QUEUE *pQueue);
	int (*empty)(struct QUEUE *pQueue);
	void (*del)(struct QUEUE **pQueue,void (*self_del)(void*));
}Queue;
Queue* create_queue();
#endif

