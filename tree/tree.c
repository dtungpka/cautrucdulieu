
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)


typedef struct node {
	int value;
	struct node* left;
	struct node* right;
} *Node;
Node transversalTree(Node root, int compareValue) {
	if (root == NULL)return NULL;
	if (compareValue < root->value) {
		if (root->left == NULL)return root; else transversalTree(root->left, compareValue);
	}
	else if (compareValue == root->value)return root;
	else {
		if (root->right == NULL)return root; else transversalTree(root->right, compareValue);
	}
}
Node addNode(Node root, int value) {
	if (root == NULL) return NULL;
	Node newNode = (Node)malloc(sizeof(Node));
	newNode->value = value;
	newNode->right = NULL;
	newNode->left = NULL;
	Node parentNode = transversalTree(root, value);
	if (parentNode->value > value)parentNode->left = newNode;
	else parentNode->right = newNode;
	return newNode;
}
Node createTree(int value) {
	Node newNode = (Node)malloc(sizeof(Node));
	newNode->value = value;
	newNode->right = NULL;
	newNode->left = NULL;
	return newNode;
}
void printTree(Node root) {
	if (root == NULL)return;

	if (root->left != NULL)printTree(root->left);
	printf("%d ", root->value);
	if (root->right != NULL)printTree(root->right);
}
int getTreeLevel(Node root) {
	if (root == NULL)return 0;
	int leftLevel = getTreeLevel(root->left);
	int rightLevel = getTreeLevel(root->right);
	return (leftLevel > rightLevel ? leftLevel : rightLevel) + 1;
}
Node findNode(Node root, int value) {
	//big O notation
	if (root == NULL) return NULL;
	Node nd = value < root->value&& value != root->value ? findNode(root->left, value) : findNode(root->right, value);
	if (nd == NULL) return NULL;
	if (nd->value == value) return root;
	if (nd != NULL && nd->value == value)return nd;
	return NULL;
}
void drawTree(Node root, int level) {
	if (root == NULL)return;
	for (int i = 0; i < level; i++)
	{
		printf("  ");
	}
	printf("%d\n", root->value);
	drawTree(root->left, level + 1);
	drawTree(root->right, level + 1);
	return;
}
void deleteNode(Node root, int value) {
	if (root == NULL)return;
	if (root->value == value) {
		if (root->left == NULL && root->right == NULL) {
			free(root);
			return;
		}
		if (root->left == NULL) {
			Node temp = root->right;
			free(root);
			root = temp;
			return;
		}
		if (root->right == NULL) {
			Node temp = root->left;
			free(root);
			root = temp;
			return;
		}
		Node temp = root->right;
		while (temp->left != NULL) {
			temp = temp->left;
		}
		root->value = temp->value;
		deleteNode(root->right, temp->value);
	}
	else if (root->value > value)deleteNode(root->left, value);
	else deleteNode(root->right, value);
}
int dataset[] = { 4,5,3,2,8,9,1,7 };
int main() {
	Node root = createTree(dataset[0]);
	for (int i = 1; i < sizeof(dataset)/sizeof(dataset[0]); i++)
	{
		addNode(root, dataset[i]);
	}
	printTree(root);
	printf("\nMax tree level: %d\n\n", getTreeLevel(root));
	drawTree(root, 0);
	//printf("Found: %d", findNode(root, 5)->value);
	return 0;





}