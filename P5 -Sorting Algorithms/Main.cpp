/********************************************************************************************
**	Project: Sort
**  Programmer: Jonathan Riebow
**  Course:		cs2420
**	Section:	001
**	Assignment: 5
**	Data:		February 15, 2019
**
**	I certify that I wrote all code in this project except that which was
**	provided by the instructor.
**
***********************************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include "Sort.h"
#include "Timer.h"

using namespace std;

// used for Unit Testing. DO NOT REMOVE
int RecursionCounter::currentDepth = 0;
int RecursionCounter::maxDepth = 0;

int main()
{
	Sort s(10000);
	Timer ti;

	s.InitArray();
	cout << "starting SelectionSort" << endl;
	ti.Start();
	s.SelectionSort();
	cout << "Selection Sort duration: " << ti.DurationInMicroSeconds() << "ms.\n" << endl;
	ti.End();
	

	s.InitArray();
	cout << "starting InsertionSort" << endl;
	ti.Start();
	s.InsertionSort();
	cout << "Insertion Sort duration: " << ti.DurationInMicroSeconds() << "ms.\n" << endl;
	ti.End();
	

	//s.InitArray();
	//cout << "starting MergeSort" << endl;
	//ti.Start();
	//s.MergeSort();
	//cout << "Merge Sort duration: " << ti.DurationInMicroSeconds() << "ms.\n" << endl;
	//ti.End();
	

	s.InitArray();
	cout << "starting QuickSort" << endl;
	ti.Start();
	s.QuickSort();
	cout << "Quick Sort duration: " << ti.DurationInMicroSeconds() << "ms.\n" << endl;
	ti.End();
	

	s.InitArray();
	cout << "starting std::sort()" << endl;
	ti.Start();
	s.AlgorithmSort();
	cout << "std::sort() duration of: " << ti.DurationInMicroSeconds() << "ms.\n" << endl;
	ti.End();
	
}