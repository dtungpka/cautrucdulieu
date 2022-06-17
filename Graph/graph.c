#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6011)
#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>

#define INF 3.402823466e+38F /* max value */
#define FLT_MIN 1.175494351e-38F /* min positive value */
#define MAX_NEIGHBORS_CONNECTION 10
#define MAX_VERTEXS 20
struct v_;
typedef struct c_ {
	struct v_* vertex1;
	struct v_* vertex2;
	float edge;
} *link;
typedef struct v_ {
	int value;
	link links[MAX_NEIGHBORS_CONNECTION];

} *vertex;

typedef struct node {
	vertex data;
	float distance;
	vertex lastnode;
	struct node* next;
} *Node;


typedef struct {
	Node head, tail; int count;
} *Queue;

#pragma region Queue
Queue InitializeQueue() {
	Queue newqueue = (Queue)malloc(sizeof(Queue));
	newqueue->head = newqueue->tail = NULL;
	newqueue->count = 0;
	return newqueue;
}
void Put(Queue queue, vertex data, float distance, vertex lastnode) {
	Node p = (Node)malloc(sizeof(Node) * 10);
	p->data = data;
	p->distance = distance;
	p->lastnode = lastnode;
	p->next = NULL;
	queue->count++;
	if (queue->head == NULL) { queue->head = queue->tail = p; return; }
	queue->tail->next = p;
	queue->tail = queue->tail->next;
}
vertex Get(Queue queue, float* dist, vertex* lastnode) {
	if (queue->head == NULL)return NULL;
	queue->count--;
	vertex tmp = (vertex)queue->head->data;
	*dist = queue->head->distance;
	*lastnode = queue->head->lastnode;
	Node tmpNode = queue->head;
	queue->head = queue->head->next;
	//free(tmpNode);
	return tmp;
}
float getDist(Queue queue, vertex val) {
	if (queue == NULL)return INF;
	for (Node node = queue->head; node != NULL; node = node->next)if (node->data == val)return node->distance;
	return INF;
}
bool inQueue(Queue queue, vertex val) {
	if (queue == NULL)return false;
	for (Node node = queue->head; node != NULL; node = node->next)if (node->data == val)return true;
	return false;
}
#pragma endregion
vertex create_vertex(int value) {
	float ft[MAX_NEIGHBORS_CONNECTION];
	vertex new_v = (struct v_*)malloc(sizeof(struct v_));
	new_v->value = value;
	for (int i = 0; i < MAX_NEIGHBORS_CONNECTION; i++)
	{
		new_v->links[i] = NULL;
	}
	return new_v;
}
bool adjacent(vertex x, vertex y) {

	if (x == y)return true;
	for (int i = 0; i < MAX_NEIGHBORS_CONNECTION; i++)
	{
		if (x->links[i] != NULL) {
			if (x->links[i]->vertex1 == y)return true;
			if (x->links[i]->vertex2 == y)return true;
		}
	}
	return false;
}

void add_edge(vertex x, vertex y, float edge) {
	link new_link = (link)malloc(sizeof(struct c_));
	new_link->vertex1 = x;
	new_link->vertex2 = y;
	new_link->edge = edge;
	int link_y = -1;
	for (int i = 0; i < MAX_NEIGHBORS_CONNECTION; i++)
	{
		if (x->links[i] == NULL)
		{
			for (int j = 0; j < MAX_NEIGHBORS_CONNECTION; j++)
			{
				if (y->links[j] == NULL)
				{
					link_y = j;
					break;
				}
				if (y->links[j]->vertex1 == x || y->links[j]->vertex2 == x)goto cant_link;

			}
			if (link_y == -1)goto cant_link;
			y->links[link_y] = new_link;
			x->links[i] = new_link;
			return;
		}
		if (x->links[i]->vertex1 == y || x->links[i]->vertex2 == y)goto cant_link;

	}
cant_link:
	//free(new_link);
	printf("Can\'t link");
	return;
}
void add_vertex(vertex parent, int value, float edge) {
	vertex v = create_vertex(value);
	add_edge(parent, v, edge);
}

//get_vertex_value(G, x) : returns the value associated with the vertex x;
int get_vertex_value(vertex x) {
	return x->value;
}
//set_vertex_value(G, x, v) : sets the value associated with the vertex x to v.
void set_vertex_value(vertex x, int val) {
	x->value = val;
}

//get_edge_value(x, y) : returns the value associated with the edge(x, y);
float get_edge_value(vertex x, vertex y) {
	if (x == y)return 0;
	for (int i = 0; i < MAX_NEIGHBORS_CONNECTION; i++)
	{
		if (x->links[i] != NULL)
			if (x->links[i]->vertex1 == y || x->links[i]->vertex2 == y)
			{
				return x->links[i]->edge;
			}
	}
	return INF;

}
//set_edge_value(G, x, y, v) : sets the value associated with the edge(x, y) to v.
void set_edge_value(vertex x, vertex y, float val) {
	for (int i = 0; i < MAX_NEIGHBORS_CONNECTION; i++)
	{
		if (x->links[i]->vertex1 == y || x->links[i]->vertex2 == y)
		{
			x->links[i]->edge = val;
		}
	}
	return;
}
vertex find(vertex G[], int value) {
	for (int j = 0; j < MAX_VERTEXS; j++) {
		if (G[j] == NULL)return NULL;
		if (G[j]->value == value)return G[j];
	}
	return NULL;
}
float Shortest(vertex x, float base, vertex* o) {
	float min = INF;
	for (int i = 0; i < MAX_NEIGHBORS_CONNECTION; i++)
	{
		if (x->links[i] != NULL) {
			if (min > x->links[i]->edge && x->links[i]->edge > base)
			{
				min = x->links[i]->edge;
				if (x == x->links[i]->vertex1)*o = x->links[i]->vertex2;
				else *o = x->links[i]->vertex1;
			}
		}
	}
	return min;
}
int index(vertex vertexs[], vertex x, int n) {
	for (int i = 0; i < n; i++)
	{
		if (vertexs[i] == x)return i;
	}
	return INT_MIN;
}
bool complete(vertex vts[], float shts[]) {
	for (int i = 0; i < MAX_VERTEXS; i++)
		if (vts[i] != NULL && shts[i] == INF)return false;
	return true;

}
bool found(vertex vtxs[], float shts[], vertex vts) {
	for (int i = 0; i < MAX_VERTEXS; i++)if (shts[index(vtxs, vts, MAX_VERTEXS)] != INF)return true;
	return false;
}
int vertex_list[] = { 1,0,3,5,7,8,6,4,2 }; //len=9
float edge_associated[] = { 2.5,2.1,2.5,2.0,2.0,1.7,2.3,0.6 };//len=8
float shortest[MAX_VERTEXS] = { INF };
vertex vertexs[MAX_VERTEXS] = { NULL };






int main() {
	vertex G = create_vertex(vertex_list[0]);
	vertexs[0] = G;
	vertex last_v = G;
	for (int i = 1; i < sizeof(vertex_list) / sizeof(vertex_list[0]); i++)
	{
		vertex v = create_vertex(vertex_list[i]);
		add_edge(last_v, v, edge_associated[i - 1]);
		last_v = v;
		vertexs[i] = v;
		shortest[i] = INF;
	}
	add_edge(find(vertexs, 1), find(vertexs, 4), 1.0f);
	add_edge(find(vertexs, 0), find(vertexs, 2), 2.0f);
	add_edge(find(vertexs, 2), find(vertexs, 5), 1.5f);
	add_edge(find(vertexs, 5), find(vertexs, 6), 1.9f);
	add_edge(find(vertexs, 6), find(vertexs, 7), 1.8f);
	for (int i = 0; i < 9; i++)
	{
		printf("%8d ", vertexs[i]->value);
	}
	printf("\n");
	for (int i = 0; i < 9; i++)
	{
		printf("---------");
	}
	printf("\n");
	int start_value = 6;
	vertex start_vertex = find(vertexs, start_value);
	shortest[index(vertexs, start_vertex, MAX_VERTEXS)] = 0;

	Queue queue = InitializeQueue();
	vertex t;
	//Khoi tao
	for (int i = 0; i < MAX_VERTEXS; i++)
	{
		if (vertexs[i] != NULL)
		{
			float e = get_edge_value(start_vertex, vertexs[i]);
			if (e == 0)printf("       0 ");
			else printf(" (INF,-) ");
		}

	}
	printf("\n");
	// Vong lap
	vertex t_;
	Put(queue, start_vertex, 0, &t_);
	int a = 10;
	while (!complete(vertexs, shortest))
	{
		float curr_val = 0;
		for (int i = 0; i < MAX_NEIGHBORS_CONNECTION; i++)
		{


			if (start_vertex->links[i] != NULL) {
				vertex q_;
				curr_val = Shortest(start_vertex, curr_val, &q_);
				if (!inQueue(queue, q_) && !found(vertexs, shortest, q_)) Put(queue, q_, curr_val, start_vertex);
			}
		}
		float distance;
		vertex last_;
		start_vertex = Get(queue, &distance, &last_);

		start_value = start_vertex->value;
		for (int i = 0; i < MAX_VERTEXS; i++)
		{
			if (vertexs[i] != NULL)
				if (shortest[i] != INF)printf("       - ");
				else {
					float srt = Shortest(start_vertex, 0, &t);
					if (inQueue(queue, vertexs[i]) && srt != get_edge_value(start_vertex, vertexs[i])) {
						printf(" (%3.1f,%d) ", getDist(queue, vertexs[i]), last_->value < 0 ? start_value : last_->value);
						continue;
					}


					float e = get_edge_value(start_vertex, vertexs[i]);
					if (adjacent(vertexs[i], start_vertex))
					{


						if (e == srt) {
							printf(" [%3.1f,%d] ", e + distance, start_value);
							shortest[i] = e;
						}
						else {
							printf(" (%3.1f,%d) ", e + distance, start_value);
						}
					}
					else printf(" (INF,-) ");
				}
		}
		printf("\n");
		if (a-- < 0)return 0;
	}


}