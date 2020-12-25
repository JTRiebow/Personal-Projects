#include <iostream>
#include <cstdlib>
#include "BinarySearchTree.h"
#include "RecursionCounter.h"

using namespace std;

BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
	size = 0;
}

BinarySearchTree::~BinarySearchTree()
{
	DestructorHelper(root);
	root = nullptr;
}

void BinarySearchTree::Insert(int data)
{
	root = InsertHelper(root, data);
}

Node * BinarySearchTree::Search(int data)
{
	return SearchHelper(root, data);
}

void BinarySearchTree::Remove(int data)
{
	root = RemoveHelper(root, data);
}

void BinarySearchTree::InOrderTraversal()
{
	InOrderHelper(root);
}

void BinarySearchTree::Print()
{
	return PrintHelper("", root);
}

int BinarySearchTree::Size()
{
	return SizeHelper(root);
}

Node * BinarySearchTree::RemoveHelper(Node * cursor, int data)
{
	RecursionCounter neededForUnitTest;
	if (cursor == nullptr)
	{
		return cursor;
	}
	else if (data < cursor->data) // If data is less than cursor
	{
		cursor->leftChild = RemoveHelper(cursor->leftChild, data);
	}
	else if (data > cursor->data) //  If data is greater than cursor
	{
		cursor->rightChild = RemoveHelper(cursor->rightChild, data);
	}
	else
	{
		if (cursor->leftChild == nullptr && cursor->rightChild == nullptr) // If cursor is a leaf
		{
			delete cursor;
			return nullptr;
		}
		else if (cursor->leftChild == nullptr && cursor->rightChild != nullptr) // If cursor has a right child
		{
			Node* child = cursor;
			child = cursor->rightChild;
			delete cursor;
			child->UpdateHeight();
			return child;
		}
		else if (cursor->leftChild != nullptr && cursor->rightChild == nullptr) // If cursor has a left child
		{
			Node* child = cursor;
			child = cursor->leftChild;
			delete cursor;
			child->UpdateHeight();
			return child;
		}
		else // If cursor has two children
		{
			Node* successor = SuccessorNode(cursor->rightChild);
			cursor->data = successor->data;
			cursor->rightChild = RemoveHelper(cursor->rightChild, successor->data);
		}
	}
	cursor->UpdateHeight();
	return cursor;
}

void BinarySearchTree::InOrderHelper(Node * cursor)
{
	RecursionCounter neededForUnitTest;
	PrintHelper(" ", cursor->leftChild);
	cout << cursor->data << " (" << cursor->height << ")" << endl;
	PrintHelper(" ", cursor->rightChild);
}

void BinarySearchTree::PrintHelper(std::string offset, Node * cursor)
{
	RecursionCounter neededForUnitTest;
	if (cursor == nullptr)
	{
		cout << offset << "[Empty]" << endl;
		return;
	}
	else
	{
		cout << offset << cursor->data << " (" << cursor->height << ") ";

		if (cursor->leftChild == nullptr && cursor->rightChild == nullptr)
		{
			cout << "[leaf]" << endl;
			return;
		}
		cout << endl;

		PrintHelper(offset + "   ", cursor->leftChild);
		PrintHelper(offset + "   ", cursor->rightChild);
	}
	
}

int BinarySearchTree::SizeHelper(Node * cursor)
{
	RecursionCounter neededForUnitTest;

	if (cursor == nullptr)
	{
		return size;
	}
	else
	return 1 + SizeHelper(cursor->leftChild) + SizeHelper(cursor->rightChild);

}

void BinarySearchTree::DestructorHelper(Node * cursor)
{
	if (cursor == nullptr)
	{
		return;
	}

	DestructorHelper(cursor->leftChild);
	DestructorHelper(cursor->rightChild);
	delete cursor;
}

Node * BinarySearchTree::SuccessorNode(Node* cursor)
{
	if (cursor->leftChild == nullptr)
	{
		return cursor;
	}

	return SuccessorNode(cursor->leftChild);
}

Node * BinarySearchTree::InsertHelper(Node * cursor, int data)
{
	RecursionCounter neededForUnitTest;
	if (cursor == nullptr)
	{
		return new Node(data, nullptr, nullptr);
	}
	if (data <= cursor->data)
	{
		cursor->leftChild = InsertHelper(cursor->leftChild, data);
	}
	else
	{
		cursor->rightChild = InsertHelper(cursor->rightChild, data);
	}
	cursor->UpdateHeight();
	return cursor;
}

Node * BinarySearchTree::SearchHelper(Node * cursor, int data)
{
	RecursionCounter neededForUnitTest;
	if (cursor == nullptr)
	{
		return cursor;
	}
	else if (cursor->data == data)
	{
		return cursor;
	}
	else if (data > cursor->data)
	{
		return SearchHelper(cursor->rightChild, data);
	}
	else if (data < cursor->data)
	{
		return SearchHelper(cursor->leftChild, data);
	}
	return cursor;
}
