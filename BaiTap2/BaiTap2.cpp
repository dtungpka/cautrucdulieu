
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <iostream>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <commonmath.h>

//DONE: Nhap vao mang co do dai 5 -> tong 4 so nho nhat va lon nhat
//Tim tong 4 so lon nhat
int SumMax(int a[], int n) { 
	int sum = 0;
	for (int i = 0; i < n; i++)sum += a[i] == findmin(a, n) ? 0 : a[i];
	
	return sum;
}
//Tim tong 4 so nho nhat
int SumMin(int a[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) sum += a[i] == findmax(a, n) ? 0 : a[i];
	return sum;
}
void Bai1() {
	int mang[5];
	InputArray(mang, 5);
	printf("\nTong 4 so lon nhat trong mang: %d", SumMax(mang, 5));
	printf("\nTong 4 so nho nhat trong mang: %d", SumMin(mang, 5));

}

int MaxCount(int a[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == findmax(a, n)) count++;
	}
	return count;
}
//Tim so lan xuat hien so lon nhat trong mang
void Bai2() {
	int mang[5];
	printf("Nhap mang: ");
	InputArray(mang, 5);
	printf("So lon nhat la %d", findmax(mang, 5));
	printf("\nSo lan xuat hien lon nhat trong mang: %d", MaxCount(mang, 5));

}
void ArrayRatio(int arr[], int n,float result[]) {
	int tempArr[3] = { 0,0,0 };
	for (int i = 0; i < n; i++)
	{
		int temp = *arr > 0 ? 2 : *arr < 0 ? 0 : 1; // 1 | 0 | -1
		tempArr[temp] += 1;
		arr++;
	}
	for (int i = 0; i < 3; i++)*(result++) = (float)tempArr[i]/n;
}

void Bai3() {
	int mang[1000];
	int n;
	float ans[3];
	printf("Nhap kich thuoc mang n=");
	scanf("%d", &n);
	InputArray(mang, n);
	ArrayRatio(mang, n, ans);
	printf("Ti le giua cac gia tri trong mang:\nNho hon 0: %0.1f %\nBang 0: %0.1f %\nLon hon 0: %0.1f %\n ",ans[0],ans[1],ans[2]);
}
void FindDuplicate(char str[], char value) {
	int count=0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (value == str[i])
		{
			printf("Ki tu '%c' xuat hien tai vi tri %d\n", value, i+1);
			count++;
		}
	}
	printf("Co tat ca %d ki tu '%c' trong cau \"%s\"\n", count, value,str);
}
void Bai4() {
	fflush(stdin);
	char str[] = "lua nep la lua nep lang";
	printf("Nhap ki tu can tim: ");
	char key;
	scanf("%c", &key);
	FindDuplicate(str, key);
}
int CountDiv(int a, int arr[],int n) {
	int count = 0;
	for (int j = 0; j < n; j++)
	{
		if (a % *arr == 0)count++;
		arr++;
	}
	return count;
}
int Divable(int a[], int b[], int c, int d) {
	int count = 0;
	for (int j = 1; j <= findmax(b,d)/2; j++)
	{
		int countDiv_b = 0;
		if (CountDiv(j,a,c) == c)
		{
			for (int i = 0; i < d; i++)
			{
				if (*b % j == 0)countDiv_b++;
				b++;
			}
		}
		if (countDiv_b == d)
		{
			printf("So %d thoa man\n", j);
			count++;
		}
		
	
	}
	return count;
}

void Bai5() {
	int a[100],b[100],c,d;
	inputarr:
	printf("Nhap kich thuoc a: ");
	scanf("%d", &c);
	printf("Nhap kich thuoc b: ");
	scanf("%d", &d);
		if (a >= b)goto inputarr;
	InputArray(a, c);
	InputArray(b, d);
	printf("Co %d so thoa man dau bai\n", Divable(a, b, c, d));
}
void SumSubArray(int arr[], int n, int length,int max,bool consecutive) {
	int tempArr[12];
	for (int i = 0; i < n; i++)
	{
		int* pointer_1 = arr;
		int sum = max,sumCount = 0;
		for (int j = 0; j < (consecutive ? length : n) && sum > 0; j++)
		{
			if (sum - *pointer_1 >= 0)
			{
				tempArr[sumCount] = *pointer_1;
				sum -= *pointer_1;
				sumCount++;
			}
			pointer_1++;
		}
		if (sum == 0 && sumCount == length)
		{
			printf("Mang con [");
			for (int x = 0; x < length; x++) { printf("%d,", (tempArr[x])); }
			printf("] co tong bang %d\n", max);
		}
		arr++;
	}
}
void Bai6() {
	int s[100],n, d, m;
	printf("\n1<= d <= 31, 1<= m <= 12");
	printf("\nNhap: n d m\n");
	scanf("%d %d %d", &n, &d, &m);
	InputArray(s, n, 1, 5);
	SumSubArray(s, n, m, d, true);
	
}
void Bai7() {
	int n, m;
	do
	{
		printf("Nhap vao ma tran nxm(n,m<20):");
		scanf("%dx%d", &n, &m);
	} while (n < 0 && m < 0);
	int maTran[20][20];
	for (int x = 0; x < sizeof(maTran) / sizeof(maTran[0]); x++)
		for (int y = 0; y < sizeof(maTran)[0] / sizeof(maTran[0][0]); y++)
			maTran[x][y] = 0;
	printf("Nhap du lieu theo hang (VD:1 2 3 4..):\n");
	for (int x = 0; x < n; x++)
	{
		printf("Hang %d: ", x + 1);
		char stream;
		int y = 0;
		do
		{

			int ip = scanf("%d%c", &maTran[x][y], &stream); // 1_2_3.. \n=break
			y++;
		} while (stream != '\n');

	}
	printf("Gia tri tren duong cheo chinh: ");
	for (int x = 0; x < n; x++)
	{
		printf("\nO so %dx%d: %d", x + 1, x + 1, maTran[x][x]);
	}
}
int main()
{
	Bai6();
	Bai5();
	Bai4();
	Bai3();
	Bai2();
	Bai1();
}

