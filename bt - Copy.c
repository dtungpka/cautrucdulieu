#include<stdio.h>

#include<stdlib.h>

struct node {
  int data;
  struct node * next;
};
struct node * head = NULL;
struct node * current = NULL;
void * createNode(int x) {

  struct node p = (struct node) malloc(sizeof(struct node));
  p -> next = NULL;
  p -> data = x;
  return p;
}
void printlist() {
  struct node * ptr = head;
  while (ptr != NULL) {
    printf(" %d", ptr -> data);
    ptr = ptr -> next;
  }
}
struct node * insert(int data) {
  struct node link = (struct node) malloc(sizeof(struct node));
  link -> data = data;
  current = head;
  if (head == NULL) {
    head = link;

  } else {
    while (current -> next != NULL) {

      current = current -> next;
    }
    current -> next = link;
  }
  return head;
}
int main() {
  int n;
  scanf("%d", & n);
  for (int i = 0; i < n; i++) {
    int data;
    scanf("%d", & data);
    insert(data);
  }
  printlist();
}