#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6011)
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node {
    int data;
    struct node* next;
}*Node;

typedef struct {
    Node head, tail;
    int count;
}*Queue;

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
    if (queue->head == NULL)
    {
        queue->head = queue->tail = p;
        return;
    }
    queue->tail->next = p;
    queue->tail = queue->tail->next;
}
int Get(Queue queue) {
    if (queue->head = NULL) return NULL;
    queue->count--;
    int tmp;
    tmp = (int)queue->head->data;
    Node tmpNode = queue->head;
    queue->head = queue->head->next;
    return tmp;
}
int main() {
    int n;
    printf("nhap gia tri n: ");
    scanf("%d", &n);
    Queue queue1 = InitializeQueue();
    Put(queue1, n);
    printf("gia tri vua nhap la: %d", Get(queue1));
}