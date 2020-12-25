#include "Search.h"

bool Search::RecursiveBinarySearchHelper(int lowIndex, int highIndex, int target) const
{
	RecursionCounter rcTmp;	// used for unit testing DO NOT REMOVE
   // add more code here...
	bool found = false;
	int low = lowIndex;
	int high = highIndex;

	int mid = (low + high) / 2;

	if (high >= low)
	{
		if (array[mid] == target)
		{
			found = true;
			return found;
		}
		else if (array[mid] > target)
		{
			return RecursiveBinarySearchHelper(low, mid - 1, target);
		}
		else
		{
			return RecursiveBinarySearchHelper(mid + 1, high, target);
		}
	}
	return found;
}

// add more code here

Search::Search(int size)
{

	array = new int[size];
	this ->size = size;
}

Search::~Search()
{
	delete[] array;
}

bool Search::SequentialSearch(int target)
{
	bool found = false;
	for (int i = 0; i < size; i++)
	{
		if (array[i] == target)
		{
			found = true;
			return true;
		}
	}
	return found;
}

bool Search::RecursiveBinarySearch(int target)
{
	int low = 0;
	int high = size - 1;

	return RecursiveBinarySearchHelper(low, high, target);
}

bool Search::IterativeBinarySearch(int target)
{
	bool found = false;
	int high = size - 1;
	int low = 0;


	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (array[mid] == target)
		{
			found = true;
			return true;
		}
		else if (array[mid] < target)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return found;
}

void Search::InitSortedArray()
{
	srand(0);

	array[0] = rand() % 5;
	for (int i = 0; i < size; i++)
	{
		array[i + 1] = array[i] + rand() % 5;
	}
}

int * Search::GetDataArray()
{
	return array;
}
