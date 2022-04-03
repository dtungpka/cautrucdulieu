

#include <iostream>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

#pragma warning(disable:4996)
#pragma warning(disable:6031)
//DONE: Nhap vao mang co do dai 5 -> tong 4 so nho nhat va lon nhat
#pragma region commonmath
/// <summary>
/// Find the largest value in a list and return it
/// </summary>
/// <param name="*p">The pointer of the first value in list </param>
/// <param name="n"> Size of the list</param> 
int findmax(int* p, int n) {

	int max = *p;
	int* p_ = p;
	for (int i = 0; i < n; i++)
	{
		max = *p_ > max ? *p_ : max;
		p_++;
	}
	return max;
};
/// <summary>
/// Find the smallest value in a list and return it 
/// </summary>
/// <param name="*p">The pointer of the first value in list </param>
/// <param name="n"> Size of the list</param> 
int findmin(int* p, int n) {
	int min = *p;
	int* p_ = p;
	for (int i = 0; i < n; i++)
	{
		min = *p_ < min ? *p_ : min;
		p_++;
	}
	return min;
};
void InputArray(int arr[],int n)
{

	int *index = arr--;
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap gia tri mang[%d]=", i);
		scanf("%d", index);
		index++;

	}


}
#pragma endregion
//Tim tong 4 so lon nhat
int SumMax(int a[], int n) { 
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i] == findmin(a, n) ? 0 : a[i];
	}
	
	return sum;
}
//Tim tong 4 so nho nhat
int SumMin(int a[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i] == findmax(a, n) ? 0 : a[i];
	}
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
void Divable(int a[], int b[], int c, int d) {
	
	for (int i = 0; i < d; i++)
	{
		int div_count = 0;
		for (int j = 0; j < c; j++)
		{
			if (*b % *a == 0)div_count++;
		}
		if (div_count == c)
		{
			printf("%d chia het cho tat ca cac so trong mang a\n", *b);
		}
		b++;
		a++;
	}
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
	Divable(a, b, c, d);


}
int main()
{
	Bai5();
	Bai4();
	Bai3();
	Bai2();
	Bai1();
}

