#include <stdio.h>
#include <stdlib.h>

typedef struct node { int data; struct node* nextNode;} *Node;
Node CreateNewNode(){Node newNode = (Node)malloc(sizeof(struct node*)); newNode->nextNode = NULL; return newNode;}
void Print(struct node* list){for(Node a = list; a != NULL; a = a->nextNode)printf("%d ",a->data);}
void Append(Node *head,int data,int index){Node newNode = (Node)malloc(sizeof(struct node*));newNode->data = data;if (index == 0){newNode->nextNode = *head;*head = newNode;return;}Node tmp = *head;for(int i = 0; i < index || tmp->nextNode != NULL;i++)tmp = tmp->nextNode;newNode->nextNode = tmp->nextNode;tmp->nextNode = newNode;}
int main() { Node nodeA = CreateNewNode(); nodeA->data = 999;for(int i = 0; i < 10; i++)Append(&nodeA, i,i);Print(nodeA);}

	

