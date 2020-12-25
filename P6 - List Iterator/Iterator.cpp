#include <cassert>
#include <iostream>
#include "Iterator.h"

using namespace std;

Iterator::Iterator(Node * start)
{
	current = start;
}

int Iterator::operator*()
{
	return current->data;
}

Iterator Iterator::operator++()
{
	current = current->next;
	return *this;
}

bool Iterator::operator!=(const Iterator & other)
{
	return current != other.current;
}

bool Iterator::is_item()
{
	if (current != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
