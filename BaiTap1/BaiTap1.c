// BaiTap1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include "commonmath.h"
#pragma warning(disable:4996)
#pragma warning(disable:6031)

void Bai2() {
	int a, b, a_, b_;
	printf("Nhap a:");
	scanf("%d", &a);
	printf("Nhap b:");
	scanf("%d", &b);
	a_ = a; b_ = b;
	while (a != b) {
		a = a > b ? a - b : a;
		b = b > a ? b - a : b;
	}
	printf("UCLN cua a va b la %d", a);
	while (a != b) {
		a = a > b ? a - b : a;
		b = b > a ? b - a : b;
	}
	printf("BCNN cua a va b la: %.1f", (float)(a_ / a) * b_);
}
void Bai3() {
	int time[4] = { 0,0,0,0 }; // HH,MM,SS,AM/PM (0/1)
	bool AM = false;
	printf("Nhap gio theo dinh dang HH:MM:SS AM  ");

	int x = 0;
	char stream;
	do
	{

		scanf(x < 3 ? "%d%c" : "%c%c", & time[x], & stream); // 1_2_3.. \n=break
		x++;
	} while (stream != '\n' && x < 4);

	int time24 = time[3] == 'A' ? time[0] : time[0] + 12;
	printf("%02d:%02d:%02d %cM -> %02d:%02d:%02d", time[0], time[1], time[2], time[3], time24, time[1], time[2]);
	getch();
}
void getuserinput(int* a, int* b, int* c) {
	printf("Nhap a:");
	scanf("%d", a);
	printf("Nhap b:");
	scanf("%d", b);
	printf("Nhap c:");
	scanf("%d", c);
}
int sumOfSquares(int a, int b) {
	return a * a + b * b;
}
void Bai4() {
	//read int a,b,c and save as a list
	int a, b, c;
	getuserinput(&a, &b, &c);
	int list[3] = { a,b,c };
	printf("Chon bai can tinh:\n");
	printf("1. Tim so lon nhat, nho nhat\n");
	printf("2. Tim so nguyen to trong a,b,c\n");
	printf("3. Tong binh phuong cac so lon nhat va nho nhat\n");
	int choice;
	scanf("%d", &choice);
	switch (choice)
	{

	case 1:
		printf("So lon nhat: %d\n", findmax(&list[0], 3));
		printf("So nho nhat: %d\n", findmin(&list[0], 3));
		break;
	case 2:
		printf("So nguyen to trong a,b,c:");
		for (int i = 0; i < 3; i++)
		{
			if (isPrime(list[i]))
				printf("%d ", list[i]);
		}
		break;
	case 3:
		printf("Tong binh phuong cac so lon nhat va nho nhat: %d", sumOfSquares(findmax(&list[0], 3), findmin(&list[0], 3)));
		break;
	default:
		printf("Khong co bai nay");
		break;
	}

}
int roundPoint(int point) {
	if (point < 38) return point;
	return point % 5 > 2 ? point + (5 - point % 5) : point;

}
int nhapBai5() {
	int point;
	printf("Nhap diem can tinh: ");
	scanf("%d", &point);
	return point;
}
Bai5() {
	int point = nhapBai5();
	printf("%d -> %d\n", point, roundPoint(point));
}


//Cats and mouse! 2D plane
//-C---
//----C
//--M--
//
enum direction {
	Stop = 0,
	Up = 1,
	Right = 2,
	Left = 3,
	Down = 4
	
};

unsigned int playGround[100][100];

Bai6() {
	


}
int main()
{
	Bai5();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
