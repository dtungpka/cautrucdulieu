#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
//Struct key value
//Search
//
struct item {
	int key;
	int value;
} ;
typedef struct node{
	item curr;
	struct node* next;

} *Node;
#define SIZE 20

Node buckets[SIZE] = { NULL };
//Hash function

int hash(int key) {
	return key % SIZE;
}

//Search function
item *Search(int key) {
	int index = hash(key);
	if (buckets[index] == NULL)return NULL;
	for (Node n = buckets[index]; n != NULL; n = n->next)
	{
		if (n->curr.key == key) return &(n->curr);
	}
	return NULL;
}


//Delete function
//Insert function

item Insert(int key,int value) {
	item* newitem = (item*)malloc(sizeof(item*));
	newitem->key = key;
	newitem->value = value;

}



int main() {

	printf("Hi");
}