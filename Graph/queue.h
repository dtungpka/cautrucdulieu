#pragma once
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6011)
#include <limits.h>
#include<stdio.h>
#include <stdlib.h>

#define MAX_NEIGHBORS_CONNECTION 5

typedef struct v_ {
	int value;
	float neighbors_edge[MAX_NEIGHBORS_CONNECTION];
	struct v_* neighbors_vertex[MAX_NEIGHBORS_CONNECTION];

} *vertex;
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
void Put(Queue queue, int data) {
	Node p = (Node)malloc(sizeof(Node));
	p->data = data;
	p->next = NULL;
	queue->count++;
	if (queue->head == NULL) { queue->head = queue->tail = p; return; }
	queue->tail->next = p;
	queue->tail = queue->tail->next;
}
int Get(Queue queue) {
	if (queue->head == NULL)return INT_MIN;
	queue->count--;
	int tmp = (int)queue->head->data;
	Node tmpNode = queue->head;
	queue->head = queue->head->next;
	//free(tmpNode);
	return tmp;
}
int get_(Queue queue) {
	if (queue->head == NULL)return INT_MIN;
	queue->count--;
	int tmp = (int)queue->head->data;
	queue->head = queue->head->next;
	return tmp;
}
void Print(Node start) {
	printf("\nLinked list node: ");
	for (Node node = start; node != NULL; node = node->next)printf("%d ", node->data);
}
Node Index(Node start, int inx) {
	if (start == NULL || inx < 0)return NULL;
	Node tmpNode = start;
	for (int i = 0; i < inx && inx != 0; i++)if (tmpNode != NULL)tmpNode = (tmpNode)->next; else return NULL;
	return tmpNode;
}
void PutRev(Queue queue, int num) {
	Node p = (Node)malloc(sizeof(Node));
	p->data = num;
	p->next = NULL;
	queue->count++;
	if (queue->head == NULL) { queue->head = queue->tail = p; return; }
	p->next = queue->head;
	queue->head = p;
}
Queue cpy(Queue queue) {
	Queue qnew = InitializeQueue();
	int tmpcount = queue->count;
	Node tmpNode = queue->head;
	while (queue->count > 0)
	{
		Put(qnew, get_(queue));
	}
	queue->head = tmpNode;
	queue->count = tmpcount;
	return qnew;
}
void ReverseQueue(Queue* queue) {
	Queue qnew = InitializeQueue();
	while ((*queue)->count > 0)
	{
		PutRev(qnew, Get(*queue));
	}
	*queue = qnew;
}