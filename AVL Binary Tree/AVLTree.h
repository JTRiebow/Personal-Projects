#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

class AVLTree
{
public:
	AVLTree();
	~AVLTree();

	Node* GetRoot() {return root;};   // Used for testing.
	void Insert(int value);
	void PreOrderTraversal();
	void Print();

private:
	Node* InsertHelper(Node* cursor, int value);
	void PreOrderHelper(Node* cursor);
	void PrintHelper(string offset, Node* cursor);
	Node* RotateRight(Node* cursor);
	Node* RotateLeft(Node* cursor);
	void DestructorHelper(Node* cursor);
	int GetBalance(Node* cursor);

	Node* root;
	int balance;
};

