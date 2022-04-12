#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6011)
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void printNode(struct Node* startNode) {
    while (startNode != NULL)
    {
        printf("%d \n", startNode->data);
        startNode = startNode->next;
    }
}
void push(struct Node** nextNode, int data) { //Obj node
    struct Node* backNode = (struct Node*)malloc(sizeof(struct Node));
    backNode->data = data;
    backNode->next = *nextNode; // pointer 
    *nextNode = backNode; // change
}

int main()
{
    int length = 10;
    struct Node* startNode = (struct Node*)malloc(sizeof(struct Node));
    startNode->data = 0;
    for (int  i = 0; i < length; i++)
    {
        push(&startNode, rand() % 100);
    }
   
    printNode(startNode);

}