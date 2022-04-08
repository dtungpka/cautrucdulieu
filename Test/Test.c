#include <stdio.h>
#include <conio.h>
#pragma warning(disable:6031)
#pragma warning(disable:4996)
int main() {
	int t;
	int R, C,j,i;
	scanf("%d", &t);
	for ( t; t > 0; t--)
	{
		fflush(stdin);
		scanf("%d %d", &R, &C);
		for (int a = 0; a < C; a++)printf(a < 2 ? "." : a % 2 == 0 ? "+" : "-");
		for ( j = 0; j < R; j++)
		{
			printf("\n");
			if (j % 2 ==0)
			{
				if(j==1)printf("|");
				for ( i = 0; i < C; i++)
				{
					printf( i == 0 && j == 0 ? "." : ".|");
				}
				
				
			}
			else {
				for ( i = 0; i < C; i++)
				{
					printf(i % 2 == 0 ? "+" : "-");
				}
			}
			
		}
		
	}


}