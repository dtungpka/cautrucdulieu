#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6011)
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	char data;
	struct node* next;
} *String;
//DONE: Insert function 

void AppendChar(String start, int index, char data) {
	String tempNode = (String)malloc(sizeof(String));
	for (int i = 0; index > -1 ? i < index : start->next != NULL; i++)start = start->next;
	tempNode->next = start->next == NULL ? NULL : start->next;
	tempNode->data = data;
	start->next = tempNode;
}
void Append(String str1, String str2) {
	for (int i = 0; str1->next != NULL; i++)str1 = str1->next;
	str1->next = str2;
}
//DONE: Find function

String Find(String start, char data) {
	for (String n = start; n != NULL; n = n->next)if (n->data == data)return n;
	return NULL;
}

//DONE: Index function -> pointer
String Index(String start, int index) {
	for (int i = 0; i <= index && start->next != NULL; i++) {
		if (start->next != NULL)start = start->next;
		if (i == index)return start;
	}
	return NULL;

}

//DONE: Delete function (pop, delete = find)

int Pop(String start, int index) {
	for (int i = 0; i <= index && start->next != NULL; i++) {
		if (i == index - 1) {

			start->next = start->next->next;
			//free(start);
			return 1;
		}
		if (start->next != NULL)start = start->next;

	}
	return 0;
}
int Remove(String start, String item) {
	for (String temp = start; temp->next != NULL; temp = temp->next)
	{
		if (temp->next == item) {
			temp->next = item->next;
			item->next = NULL;
			//free(item);
			return 1;
		}
	}
	return 0;
}
/// <summary>
/// Print linked list
/// </summary>

void Print(String start) {
	for (String node = start; node != NULL; node = node->next)printf("%c", node->data);
}


/// <summary>
/// Create a new linked list with int type
/// </summary>
/// <param name="length:">length of the list</param>
/// <param name="randRange:"> max random input, 0 to manually type</param>
/// <returns>Return the first node</returns>
String LinkedList(int length, int randRange) {

	int inx = 0;
	String nodeZero = (String)malloc(sizeof(String));
	nodeZero->next = NULL;

	if (randRange == 0) { printf("[%d]:", inx++); scanf("%d", &nodeZero->data); }
	else nodeZero->data = rand() % randRange;
	if (length > 1) {
		String nodeOne = (String)malloc(sizeof(String));
		nodeZero->next = nodeOne;
		nodeOne->next = NULL;
		if (randRange == 0) { printf("[%d]:", inx++); scanf("%d", &nodeOne->data); }
		else nodeOne->data = rand() % randRange;

		for (int i = 0; i < length - 2; i++)
		{
			String nodeN = (String)malloc(sizeof(String));
			if (randRange == 0) { printf("[%d]:", inx++); scanf("%d", &nodeN->data); }
			else nodeN->data = rand() % randRange;
			nodeOne->next = nodeN;
			nodeN->next = NULL;
			nodeOne = nodeN;
		}
	}
	return nodeZero;
}
String GetString() {
	char stream;
	String linkedList = LinkedList(0, 1);
	do
	{
		stream = getchar();
		if (stream != '\n')AppendChar(linkedList, -1, stream);
	} while (stream != '\n');
	fflush(stdin);
	return linkedList;

}
String ToString(char c[]) {
	char stream;
	String linkedList = LinkedList(0, 1);
	do
	{
		stream = *c;
		if (stream != '\0')AppendChar(linkedList, -1, stream);
		c++;
	} while (stream != '\0');
	return linkedList;
}

