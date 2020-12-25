#include <iostream>

#include "List.h"
using namespace std;



List::List()
{
	size = 0;
	head = nullptr;
}

List::~List()
{
	while (head != nullptr)
	{
		Node* toBeDeleted = head;
		head = head->next;
		delete toBeDeleted;
		size--;
	}
}

void List::push_front(const int & data)
{
	head = new Node(head, data);
	size++;
}

void List::push_back(const int & data)
{
	if (head == nullptr)
	{
		head = new Node(head, data);
	}
	else 
	{
		Node* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = new Node(nullptr, data);
	}
	size++;
}

void List::remove(const int & data)
{
	if (head->data == data)
	{
		Node * toBeDeleted = head;
		head = head->next;
		delete toBeDeleted;
		size--;
	}



	Node * current = head;
	while (current->next != nullptr)
	{
		if (current->next->data == data)
		{
			Node * tmp = current->next;
			current->next = tmp->next;
			delete tmp;
			size--;
		}
		else
		{
			current = current->next;
		}
	}
}

void List::PrintList()
{
	Node * current = head;
	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

Iterator List::begin()
{
	return Iterator(head);
}

Iterator List::end()
{
	Node * end = head;
	while (end != nullptr)
	{
		end = end->next;
	}
	return Iterator(end);
}

int List::Size()
{
	return size;
}
