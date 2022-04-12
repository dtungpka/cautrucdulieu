// TestCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6011)
#include <queue>
#include <stack>
using namespace std;
template <typename T>
T findMin(T num1, T num2) { return num1 < num2 ? num1 : num2 ; }
template <typename V> class Node
{
	
public:
	Node(int Nodedata, Node* nextNode)
	{
		data = Nodedata;
		next = nextNode;
	}
	~Node() //destructor
	{
		printf("%h", next);
		delete& data;
		delete next;
	}
	Node<V>* next;
	V data;
	
private:

};
template <typename Z>
void printNode( Node<Z>* startNode) {
	while (startNode != NULL)
	{
		printf("%d \n", startNode->data);
		startNode = startNode->next;
	}
}

int main()
{
	queue<int> a;
	a.push(1);
	int b = a.size();
    int length;
	Node<char> node1('a', NULL);
	Node<char> node2('a', &node1);
	printNode<char>(&node2);
	delete &node1, &node2;
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
