#include <string>

#include "Node.h"
#include "HashMap.h"
using namespace std;

Iterator::Iterator()
{
}

Iterator::Iterator(int index, Node **hashArray, int sizeOfArray)
{
	current = hashArray[index];
	this->sizeOfArray = sizeOfArray;
	this->hashArray = hashArray;
	this->index = index;
}

string Iterator::operator*()
{
	if (current == nullptr)
	{
		return "";
	}
	return current->key;
}

void Iterator::operator++()
{
	if (current != nullptr && current->next != nullptr)
	{
		current = current->next;
		return;
	}
	else
	{
		index = index + 1;
		while (index < sizeOfArray && hashArray[index] == nullptr)
		{
			index = index + 1;
		}
		if (index == sizeOfArray)
		{
			current = nullptr;
		}
		else
		{
			current = hashArray[index];
		}
	}

}

bool Iterator::operator!=(Iterator & other)
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

Iterator HashMap::begin()
{
	int value = 0;
	while (hashArray[value] == nullptr && value < sizeOfArray)
	{
		value++;
	}
	return Iterator(value, hashArray, sizeOfArray);
}

Iterator HashMap::end()
{
	return Iterator(sizeOfArray, hashArray, sizeOfArray);
}