//Tìm đường đi ngắn nhắt từ đỉnh 0 đến đỉnh 6
//


#include <stdio.h>
#include <stdlib.h>



// Định nghĩa đỉnh
typedef struct Vertex {
    int id;
    int dist;
    int prev;
} Vertex;

// Định nghĩa danh sách đỉnh
typedef struct List {
    int n;
    Vertex *vertex;
} List;
//tạo queue
typedef struct Queue {
    int n;
    int front;
    int rear;
    List *list;
} Queue;
//hàm put và get
void put(Queue *queue, int id, int dist, int prev) {
    if (queue->n == queue->list->n) {
        printf("Queue is full\n");
        return;
    }
    queue->list->vertex[queue->rear].id = id;
    queue->list->vertex[queue->rear].dist = dist;
    queue->list->vertex[queue->rear].prev = prev;
    queue->rear = (queue->rear + 1) % queue->list->n;
    queue->n++;
}
int get(Queue *queue) {
    if (queue->n == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    int id = queue->list->vertex[queue->front].id;
    queue->front = (queue->front + 1) % queue->list->n;
    queue->n--;
    return id;
}
//hàm dijkstra
void dijkstra(List *graph, int u) {
    Queue queue;
    queue.n = 0;
    queue.front = 0;
    queue.rear = 0;
    queue.list = graph;
    for (int i = 0; i < graph->n; i++) {
        graph->vertex[i].dist = -1;
        graph->vertex[i].prev = -1;
    }
    graph->vertex[u].dist = 0;
    put(&queue, u, 0, -1);
    while (queue.n > 0) {
        int u = get(&queue);
        for (int i = 0; i < graph->n; i++) {
            if (graph->vertex[i].dist == -1) {
                if (graph->vertex[u].dist + graph->vertex[u].dist < graph->vertex[i].dist) {
                    graph->vertex[i].dist = graph->vertex[u].dist + graph->vertex[u].dist;
                    graph->vertex[i].prev = u;
                    put(&queue, i, graph->vertex[i].dist, u);
                }
            }
        }
    }
    //in ra kết quả
    for (int i = 0; i < graph->n; i++) {
        printf("%d %d %d\n", i, graph->vertex[i].dist, graph->vertex[i].prev);
    }
}

//hàm main
int main() {
    int i, j;
    int n;
    int u;
    List graph;
    printf("Nhap so dinh cua do thi: ");
    scanf("%d", &n);
    graph.n = n;
    graph.vertex = (Vertex *) malloc(n * sizeof(Vertex));
    for (i = 0; i < n; i++) {
        graph.vertex[i].id = i;
        graph.vertex[i].dist = 0;
        graph.vertex[i].prev = -1;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                graph.vertex[i].dist = 0;
            } else {
                graph.vertex[i].dist = rand() % 10;
            }
        }
    }
    printf("Nhap dinh bat dau: ");
    scanf("%d", &u);
    dijkstra(&graph, u);
    return 0;
}