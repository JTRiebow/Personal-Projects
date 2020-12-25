#include <string>
#include "Node.h"

using namespace std;

class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();

	void Insert(int data);
	Node* Search(int data);
	void Remove(int data);
	void InOrderTraversal();
	void Print();
	int Size();

private:
	Node* InsertHelper(Node* cursor, int data);
	Node* SearchHelper(Node* cursor, int data);
	Node* RemoveHelper(Node* cursor, int data);
	void InOrderHelper(Node* cursor);
	void PrintHelper(std::string offset, Node* cursor);
	int SizeHelper(Node* cursor);
	void DestructorHelper(Node* cursor);
	Node* SuccessorNode(Node* cursor);

	Node* root;
	int size;
};