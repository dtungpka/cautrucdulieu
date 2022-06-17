#pragma warning(disable:4996)
#pragma warning(disable:6031)

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>

int* creatNewArr(int* arr, int n) {
    arr = (int*)calloc(n, sizeof(int));
    return arr;
}

void input(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu arr[%d]: ", i);
        scanf("%d", (arr + i));
    }
}

void output(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
bool check(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void delete(int* arr, int *n, int k) {
    int index=*n;
    for (int i = 0; i < *n; i++) {
        if (arr[i] == k) {
            index = i;
        }
    }
    for (int i = index; i < *n; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

int main() {
    int* arr, n;
    bool loz;
    printf("Nhap so phan tu cua mang: "); scanf("%d", &n);
    arr = creatNewArr(arr, n);
    input(arr, n);
    printf("Mang da nhap: ");
    output(arr, n);
    delete(arr, &n, 3);
    printf("\n");
    output(arr, n);
}