#include <iostream>
#include "DynamicArray.h"

using namespace std;

DynamicArray::DynamicArray()
{
	capacity = INITIAL_CAPACITY;
	used = 0;
	transactions = new Transaction[capacity];
}

DynamicArray::~DynamicArray()
{
	delete[] transactions;
}

void DynamicArray::push_back(const Transaction & newTransaction)
{
	if (used < capacity)
	{
		transactions[used++] = (newTransaction);
	}
	else
	{
		Realloc();
		transactions[used++] = (newTransaction);
	}
}

int DynamicArray::size() const
{
	return used;
}

int DynamicArray::currentCapacity() const
{
	return capacity;
}

Transaction & DynamicArray::at(int index)
{
	return transactions[index];
}

void DynamicArray::Realloc()
{
	capacity *= 2;
	Transaction *tmp = new Transaction[capacity];
	for (int i = 0; i < used; i++)
	{
		tmp[i] = transactions[i];
	}
	delete[] transactions;
	transactions = tmp;
}
