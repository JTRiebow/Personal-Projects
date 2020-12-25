#include <random>
#include <algorithm>
#include <cstdlib>
#include "Sort.h"


int Sort::Partition(int start, int end)
{
	int pivot = array[end];
	int PIndex = start;

	for (int i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			std::swap(array[i], array[PIndex]);
			PIndex++;
		}
	}
	std::swap(array[PIndex], array[end]);
	return PIndex;

}

//void Sort::Merge(int i, int k)
//{
//	int * temp;
//	int copied = 0;
//	int copied1 = 0;
//	int copied2 = 0;
//	int j;
//
//	temp = new int[i + k];
//	while ((copied1 < i) && (copied2 < k))
//	{
//		if (array[copied1] < (array + i)[copied2])
//		{
//			temp[copied++] = array[copied1++];
//		}
//		else
//		{
//			temp[copied++] = (array + i)[copied2++];
//		}
//	}
//
//	while (copied1 < i)
//	{
//		temp[copied++] = array[copied1++];
//	}
//	while (copied2 < k)
//	{
//		temp[copied++] = (array + i)[copied2++];
//	}
//
//	for (j = 0; j < i + k; ++j)
//	{
//		array[j] = temp[j];
//	}
//
//	delete[] temp;
//}

void Sort::MergeSortRecursionHelper(int i, int k)
{
	RecursionCounter rcTmp;	// used for Unit Testing. DO NOT REMOVE
   // add more code here
	if (i < k)
	{
		int middle = i + (k - i) / 2;
		MergeSortRecursionHelper(i, middle);
		MergeSortRecursionHelper(middle + 1, k);

		Merge(i, middle, k);
	}

}

void Sort::Merge(int low, int mid, int high)
{
	int * helper;

	helper = new int[low + high];

	for (int i = low; i <= high; i++)
	{
		helper[i] = array[i];
	}

	int j = low;
	int k = mid + 1;
	int l = low;

	while (j <= mid && k <= high)
	{
		if (helper[j] <= helper[k])
		{
			array[l] = helper[j];
			j++;
		}
		else
		{
			array[l] = helper[k];
			k++;
		}
		l++;
	}

	while (j <= mid)
	{
		array[l] = helper[j];
		l++;
		j++;
	}
}

void Sort::QuickSortRecursionHelper(int initialLowIndex, int initialHighIndex)
{
	RecursionCounter rcTmp;	// used for Unit Testing. DO NOT REMOVE

   // add more code here
	if (initialLowIndex < initialHighIndex)
	{
		int PIndex = Partition(initialLowIndex, initialHighIndex);
		QuickSortRecursionHelper(initialLowIndex, PIndex - 1);
		QuickSortRecursionHelper(PIndex + 1, initialHighIndex);
	}
}

Sort::Sort(int size)
{
	array = new int[size];
	this->size = size;
}

Sort::~Sort()
{
	delete[] array;
}

void Sort::InitArray()
{
	srand(0);

	array[0] = rand() % 5;
	for (int i = 0; i < size - 1; i++)
	{
		array[i + 1] = array[i] + rand() % 5;
	}
}

void Sort::SelectionSort()
{
	int i;
	int j;
	int index_of_largest;
	int largest;

	if (GetSize() == 0)
	{
		return;
	}
	for (i = size - 1; i > 0; --i)
	{
		largest = array[0];
		index_of_largest = 0;
		for (j = 0; j <= i; j++)
		{
			if (array[j] > largest)
			{
				largest = array[j];
				index_of_largest = j;
			}
		}
		std::swap(array[i], array[index_of_largest]);
	}
}

void Sort::InsertionSort()
{
	for (int i = 0; i < size - 1; i++)
	{
		int value = array[i];
		int hole = i;
		while ((hole > 0) && (array[hole - 1] > value))
		{
			array[hole] = array[hole - 1];
			hole = hole - 1;
		}
		array[hole] = value;
	}
}

void Sort::AlgorithmSort()
{
	std::sort(array, array + size);
}

void Sort::MergeSort()
{
	MergeSortRecursionHelper(0, size - 1);
}

void Sort::QuickSort()
{
	return QuickSortRecursionHelper(0, size - 1);
}

int Sort::GetSize() const
{
	return size;
}

int * Sort::GetDataArray() const
{
	return array;
}
