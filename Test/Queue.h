#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6011)
#ifndef QUEUE_MAX
#define QUEUE_MAX 100
#endif // !QUEUE_MAX

#include<stdio.h>
#include <stdlib.h>


#ifdef ARRAY_QUEUE
typedef struct {
	int head,tail,count;
	int queue[QUEUE_MAX];
} *Queue;


Queue InitializeQueue() {
	Queue newqueue = (Queue)malloc(sizeof(Queue));
	newqueue->count = 0;
	newqueue->head = 0;
	newqueue->tail = 0;
	return newqueue;

}
void Put(Queue queue,int data) {
	if (queue->count >= QUEUE_MAX)return;
	if (queue->tail == QUEUE_MAX)queue->tail = 0;
	queue->queue[queue->tail++] = data;
	queue->count++;
}
int Get(Queue queue) {
	if (queue->count == 0)return NULL;
	queue->count--;
	return queue->queue[queue->head++];
}

#endif // ARRAY_QUEUE
#ifndef ARRAY_QUEUE
typedef struct node {
	int data;
	struct node* next;
} *Node;


typedef struct {
	Node head, tail; int count;
} *Queue;

Queue InitializeQueue() {
	Queue newqueue = (Queue)malloc(sizeof(Queue));
	newqueue->head = newqueue->tail = NULL;
	newqueue->count = 0;
	return newqueue;
}
void Put(Queue queue,int data) {
	Node p = (Node)malloc(sizeof(Node));
	p->data = data;
	p->next = NULL;
	queue->count++;
	if (queue->head == NULL) { queue->head = queue->tail = p; return; }
	queue->tail->next = p;
	queue->tail = queue->tail->next;
}
int Get(Queue queue) {
	if (queue->head == NULL)return NULL;
	queue->count--;
	int tmp = (int)queue->head->data;
	Node tmpNode = queue->head;
	queue->head = queue->head->next;
	free(tmpNode);
	return tmp;
}
#endif // LINKED_QUEUE
