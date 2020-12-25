#include "AVLTree.h"



AVLTree::AVLTree()
{
	root = nullptr;
}


AVLTree::~AVLTree()
{
	DestructorHelper(root);
	root = nullptr;
}

void AVLTree::Insert(int value)
{
	root = InsertHelper(root, value);
}

void AVLTree::PreOrderTraversal()
{
	PreOrderHelper(root);
	cout << endl;
}

void AVLTree::Print()
{
	PrintHelper("", root);
	cout << endl;
	cout << endl;
}

Node * AVLTree::InsertHelper(Node * cursor, int value)
{
	if (cursor == nullptr)
	{
		return new Node(value, nullptr, nullptr);
	}
	if (value <= cursor->value)
	{
		cursor->left = InsertHelper(cursor->left, value);
	}
	else
		cursor->right = InsertHelper(cursor->right, value);

	cursor->UpdateHeight();
	balance = GetBalance(cursor);

	if (balance > 1 && value < cursor->left->value)
		return RotateRight(cursor);

	if (balance < -1 && value > cursor->right->value)
		return RotateLeft(cursor);

	if (balance > 1 && value > cursor->left->value)
	{
		cursor->left = RotateLeft(cursor->left);
		return RotateRight(cursor);
	}

	if (balance < -1 && value < cursor->right->value)
	{
		cursor->right = RotateRight(cursor->right);
		return RotateLeft(cursor);
	}

	return cursor;
}

void AVLTree::PreOrderHelper(Node * cursor)
{
	if (cursor == nullptr)
		return;
	else
	{
		cout << cursor->value << ", ";
		PreOrderHelper(cursor->left);
		PreOrderHelper(cursor->right);
	}
}

void AVLTree::PrintHelper(string offset, Node * cursor)
{
	if (cursor == nullptr)
	{
		cout << offset << "[Empty]" << endl;
		return;
	}
	else
	{
		cout << offset << cursor->value << " (" << cursor->height << ") ";

		if (cursor->left == nullptr && cursor->right == nullptr)
		{
			cout << "[leaf]" << endl;
			return;
		}
		cout << endl;

		PrintHelper(offset + "   ", cursor->left);
		PrintHelper(offset + "   ", cursor->right);
	}
}

Node * AVLTree::RotateRight(Node * cursor)
{
	Node* tmp1 = cursor->left;
	Node* tmp2 = tmp1->right;
	tmp1->right = cursor;
	cursor->left = tmp2;
	cursor->UpdateHeight();
	tmp1->UpdateHeight();
	return tmp1;
}

Node * AVLTree::RotateLeft(Node * cursor)
{
	Node* tmp1 = cursor->right;
	Node* tmp2 = tmp1->left;
	tmp1->left = cursor;
	cursor->right = tmp2;
	cursor->UpdateHeight();
	tmp1->UpdateHeight();
	return tmp1;
}

void AVLTree::DestructorHelper(Node * cursor)
{
	if (cursor == nullptr)
	{
		return;
	}

	DestructorHelper(cursor->left);
	DestructorHelper(cursor->right);
	delete cursor;
}

int AVLTree::GetBalance(Node * cursor)
{
	if (cursor == nullptr)
		return 0;

	int leftChild;
	int rightChild;

	if (cursor->left == nullptr)
		leftChild = -1;
	else
		leftChild = cursor->left->height;

	if (cursor->right == nullptr)
		rightChild = -1;
	else
		rightChild = cursor->right->height;

	return leftChild - rightChild;
}
