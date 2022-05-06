#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6011)
#pragma warning(disable:6001)
#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
};
struct node* head = NULL;
struct node* current = NULL;
struct node* createNode(int x) {

	struct node* p = (struct node*)malloc(sizeof(struct node));
	p->next = NULL;
	p->data = x;
	return p;
}
void printlist(struct node* head) {
	struct node* ptr = head;
	while (ptr != NULL) {
		printf(" %d", ptr->data);
		ptr = ptr->next;
	}
}
struct node* addHead(struct node* head, int data) {
	struct node* p = createNode(data);
	if (head != NULL) p->next = head;
	return p;
	
}
void insert(struct node* head, int data) {
	struct node* link = (struct node*)malloc(sizeof(struct node));
	link->data = data;
	link->next = NULL;
	current = head;
	if (head == NULL) {
		head = link;
		return;
	}

	else {
		while (current->next != NULL) {


			current = current->next;
		}
		current->next = link;
	}

}
void addAt(struct node** head, int k, int x) {

	if (k == 0) {  *head = addHead(*head, x);
	return; }
	else {
		current = *head;
		struct node* newNode = createNode(x);
		int count = 0;
		while (current->next != NULL) {
			count++;
			if (count == k) {
				newNode->next = current->next;
				current->next = newNode;

				break;
			}
			current = current->next;
		}
	}

}
int main() {
	int n, data,k;
	scanf("%d", &n);
	struct node* head;
	scanf("%d", &data);
	head = createNode(data);
	for (int i = 0; i < n-1; i++) {
		scanf("%d", &data);
		insert(head, data);
	}
	scanf("%d", &k);
	scanf("%d", &data);
	addAt(&head, k, data);
	printlist(head);
}