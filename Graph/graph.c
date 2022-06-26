#pragma warning(disable:6011)
#include <stdio.h>
#include <stdlib.h>

//Đồ thị bằng mảng


void create_graph(int n, int* vertices, int** edges) {
	vertices = (int*)calloc(n, sizeof(int));
	edges = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++)
		edges[i] = (int*)calloc(n, sizeof(int));
	return;
}

