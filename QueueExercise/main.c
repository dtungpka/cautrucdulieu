#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6011)
#include "../Test/Queue.h"


int main() {
	Queue a = InitializeQueue();
	printf("\n");
	for (int  i = 0; i < 10; i++)
	{
		int c = rand() % 10;
		Put(a, c);
		printf(" %d ",  c);
		
	}
	Queue b = cpy(a);

	Sort(b);
ReverseQueue(&a);
printf("\n");
while (b->count > 0)
{
	printf(" %d ", Get(b));
}
printf("\n");
	while (a->count > 0 )
	{
		printf(" %d ", Get(a));
	}
	return;
}