#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6011)
#define _GNU_SOURCE
#define LINKED_QUEUE
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Queue.h"
#include <time.h>
int main() {
	int n;
	scanf("%d", &n);
	Queue queue = InitializeQueue();
	for (int i = 0; i < n; i++)
	{
		printf("\nInsert number #%d: ", i + 1);
		int temp;
		scanf("%d", &temp);
		Put(queue, temp);
	}
	printf("Queue line completed. Printing..\n");
	for (int i = 0; i < n; i++)
	{
		printf("\n#%d: %d", i + 1, Get(queue));
		long tm = clock();
		while (tm + CLOCKS_PER_SEC / 2 > clock());
	}
}