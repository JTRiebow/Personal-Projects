
#ifndef __SEARCH__
#define __SEARCH__
#include <iostream>
#include <random>
#include "RecursionCounter.h"

class Search
{
public:
	// add your code here  
	Search() = default;
	Search(int size);
	~Search();
	bool SequentialSearch(int target);
	bool RecursiveBinarySearch(int target);
	bool IterativeBinarySearch(int target);
	void InitSortedArray();
	int *GetDataArray();


private:
	bool RecursiveBinarySearchHelper(int lowIndex, int highIndex, int target) const;
	// add your code here
	int size;
	int * array;
};


#endif