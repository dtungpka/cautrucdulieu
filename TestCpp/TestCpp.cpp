// TestCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

using namespace std;
bool HoanChinh(int num) {
	int sum = 0;

	for (int i = 1; i < num; i++)if (num % i == 0)sum += i;
	return num == sum;
}

void SolveEqu(int a1, int b1, int c1,int a2 ,int b2, int c2) {
	return;
}
#include <iostream>
#include <iomanip>
using namespace std;

//void fillArray(int* array, int row, int col)
//{
//    int i, j;
//    cout << "Enter Data in array" << endl;
//    for (i = 0; i < row; i++)
//    {
//        for (j = 0; j < col; j++)
//        {
//            cout << "Enter element [" << i << "][" << j << "]: ";
//            cin >> array[i][j];
//        }
//    }
//}
//void showArray(int* array, int row, int col)
//{
//    int i, j;
//    cout << "Table of contents" << endl;
//    for (i = 0; i < row; i++)
//    {
//        for (j = 0; j < col; j++)
//        {
//            cout << setw(3) << array[i][j];     //show row in one line
//        }
//        cout << endl;
//    }
//}
int main()
{
    int row, col;
    cout << "Enter row: ";
    cin >> row;
    cout << "Enter col: ";
    cin >> col;

    //int array[row][col];    //declare array
    //fillArray(array, row, col);
    //showArray(array, row, col);
    return 0;
}
int MaxSumRows(int arr[][100], int rows, int cols) {
    int maxRow = -1;
    for (int i = 0; i < rows; i++)
    {
        int sum = 0,maxSum=0;
        for (int j = 0; j < cols; j++)sum += arr[i][j]; 
        if (maxSum < sum) { maxSum = sum; maxRow = i; }

    }
    return maxRow;
}



bool MaPhuong(int arr[][100], int rows, int cols) {
    if (rows != cols)return false;
    int firstSum = 0;
    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < cols; j++)sum += arr[i][j];
        if (firstSum == 0)  firstSum = sum;
        if (firstSum != sum)return false;
    }
    for (int i = 0; i < cols; i++)
    {
        int sum = 0;
        for (int j = 0; j < rows; j++)sum += arr[j][i];
        if (firstSum != sum)return false;
    }
    int sum = 0;
    for (int i = 0; i < cols; i++)sum += arr[i][i];
    if (firstSum != sum)return false;
    int sum = 0;
    for (int i = 0; i < cols; i++)sum += arr[cols - i][i];
    if (firstSum != sum)return false;
    return true;
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
