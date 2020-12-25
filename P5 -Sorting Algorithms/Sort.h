#ifndef __SORT__
#define __SORT__
#include <iostream>
#include <algorithm>
#include <cstdlib>

#include "RecursionCounter.h"
class Sort
{
public:
	// add code here
	Sort() = default;
	Sort(int size);
	~Sort();

	void InitArray();

	void SelectionSort();
	void InsertionSort();
	void AlgorithmSort();
	void MergeSort();
	void QuickSort();

	int GetSize() const;
	int *GetDataArray() const;
private:
	// add code here
	int * array;
	int size;
	int Partition(int start, int end);
	void MergeSortRecursionHelper(int indexI, int indexK);
	void Merge(int low, int mid, int high);
	void QuickSortRecursionHelper(int initialLowIndex, int initialHighIndex);
};

#endif
