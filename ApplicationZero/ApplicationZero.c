//tao chuong trinh kiem tra so nguyen to
#include <stdio.h>
#include <math.h>
#include <conio.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)
//TODO: Nhập một số từ bàn phím và kiểm tra xem số đó có phải là số nguyên tố hay không.
int bai1()
{
	int n,i,flag=0;
	printf("Nhap n:");
	scanf("%d",&n);
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			flag=1;
			break;
		}
	}
	
	if(flag==0)
		printf("%d la so nguyen to",n);
	else
		printf("%d khong la so nguyen to",n);
	return 0;
}
//tao ham tim so lon nhat a,b,c 
int bai2()
{
	int a,b,c;
	printf("Nhap a:");
	scanf("%d",&a);
	printf("Nhap b:");
	scanf("%d",&b);
	printf("Nhap c:");
	scanf("%d",&c);
	if(a>b)
	{
		if(a>c)
			printf("%d la so lon nhat",a);
		else
			printf("%d la so lon nhat",c);
	}
	else
	{
		if(b>c)
			printf("%d la so lon nhat",b);
		else
			printf("%d la so lon nhat",c);
	}
	return 0;
}
//tinh tong binh phuong cac so le tu 1 den n
int bai3()
{
	int n,i,s=0;
	printf("Nhap n:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(i%2!=0)
			s+=i*i;
	}
	printf("Tong binh phuong cac so le tu 1 den n la:%d",s);
	return 0;
}
int bai4(){
	//kiem tra so chan hay le
	int n;
	printf("Nhap n:");
	scanf("%d",&n);
	if(n%2==0)
		printf("%d la so chan",n);
	else
		printf("%d la so le",n);
	return 0;
}
//tao ham main
int main()
{

	int n;
	printf("Nhap bai can thuc hien:");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			bai1();
			break;
		case 2:
			bai2();
			break;
		case 3:
			bai3();
			break;
		case 4:
			bai4();
			break;
		default:
			printf("Khong co chuong trinh nay");
	}
	//wait for input
	n = getch();
	return 0;
}
