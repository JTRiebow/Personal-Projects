#include <cstdlib>


#include "HashMap.h"


HashMap::HashMap(int size)
{
	hashArray = new Node*[size];
	for (int i = 0; i < size; i++)
	{
		hashArray[i] = nullptr;
	}
	sizeOfArray = size;
}

HashMap::~HashMap()
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		if (hashArray[i] != nullptr) {
			Node* head = hashArray[i];
			while (head != nullptr)
			{
				Node * toBeDeleted = head;
				head = head->next;
				delete toBeDeleted;
			}
		}
	}
	delete[] hashArray;
}

bool HashMap::IsKeyPresent(string const & key) const
{
	int index = GenerateHash(key);

	if (hashArray[index] == nullptr)
	{
		return false;
	}
	else
	{
		Node * current = hashArray[index];
		while (current != nullptr)
		{
			if (current->key == key)
			{
				current->value = current->value + 1;
				return true;
			}
			else
			{
				current = current->next;
			}
		}
	}
	return false;
}

void HashMap::SetKeyValue(string const & key, int value)
{
	int index = GenerateHash(key);
	Node* current = hashArray[index];

	if (current == nullptr)
	{
		hashArray[index] = new Node(key, value, nullptr);
		return;
	}
	while (current != nullptr)
	{
		if (current->key == key)
		{
			current->value = value;
			return;
			
		}
		if (current->next == nullptr)
		{
			current->next = new Node(key, value, nullptr);
			return;
		}
		current = current->next;
	}
}

bool HashMap::GetKeyValue(string const & key, int & value)
{
	int index = GenerateHash(key);
	Node* current = hashArray[index];
	while (current != nullptr)
	{
		if (current->key == key)
		{
			value = current->value;
			return true;
		}
		else
		{
			current = current->next;
		}
	}
	return false;
}

int HashMap::GenerateHash(string key) const
{
	int hashValue = 12345;
	for (size_t i = 0; i < key.size(); i++)
	{
		hashValue += key.at(i);
	}

	return abs(hashValue) % sizeOfArray;
}


