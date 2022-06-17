//tao ngan xep stack
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node* next;
} *Node;
typedef struct {
	Node head; int count;
} *Stack;
Stack InitializeStack() {
	Stack newstack = (Stack)malloc(sizeof(Stack));
	newstack->head =  NULL;
	newstack->count = 0;
	return newstack;
}
void Put(Stack stack, int data) {
	Node p;
	p = (Node)malloc(sizeof(Node));
	p->data = data;
	p->next = NULL;
	stack->count++;
	if (stack->head == NULL) { stack->head = p; return; }
	p->next = stack->head;
	stack->head = p;
}
int Get(Stack stack) {
	if (stack->head == NULL)return NULL;
	stack->count--;
	int tmp = (int)stack->head->data;
	Node tmpNode = stack->head;
	stack->head = stack->head->next;
	//free(tmpNode);
	return tmp;
}
int IsEmpty(Stack stack) {
    if (stack->head == NULL)return 1;
    return 0;
}
