#pragma once
#include <math.h>
#include <stdbool.h>
//Check if n is prime number
bool isPrime(int n) {
	
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)return true;
	}
	return false;
};
//find the largest value in a list and return it 
int findmax(int *p,int n) {

	int max = *p;
	int* p_ = p;
	for (int i = 0; i < n; i++)
	{
		max = *p_ > max ? *p_ : max;
		p_++;
	}
	return max;
};
//find the smallest value in a list and return it 
int findmin(int* p,int n) {
	int min = *p;
	int* p_ = p;
	for (int i = 0; i < n; i++)
	{
		min = *p_ < min ? *p_ : min;
		p_++;
	}
	return min;
};
//create a function that take a list of numbers and return the average of the numbers
double findaverage(int* p[], int n) {
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += *p[i];
	}
	return sum / n;
};


