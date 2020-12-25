/********************************************************************************************
**	Project: Search Project
**  Programmer: Jonathan Riebow
**  Course:		cs2420
**	Section:	001
**	Assignment: 4
**	Data:		Feb 4, 2019
**
**	I certify that I wrote all code in this project except that which was
**	provided by the instructor.
**
***********************************************************************************************/

#include <iostream>
#include <random>
#include "Timer.h"
#include "Search.h"

using namespace std;

// used for Recursion Unit Testing. DO NOT REMOVE
int RecursionCounter::currentDepth = 0;
int RecursionCounter::maxDepth = 0;

// add code here

int main()
{
	Search s(10000000);
	Timer ti;

	cout << "Creating a sorted array of 10000000" << endl;
	s.InitSortedArray();
	cout << "Finished creating a sorted array of 10000000" << endl;
	cout << "\n";

	cout << "Searching for a number at the start of the array" << endl;
	ti.Start();
	cout << "\t" << "s.sequencialSearch() returned " << s.SequentialSearch(500) << " in " << ti.DurationInNanoSeconds() << endl;
	ti.End();
	ti.Start();
	cout << "\t" << "s.IterativeBinarySearch() returned " << s.IterativeBinarySearch(500) << " in " << ti.DurationInNanoSeconds() << endl;
	ti.End(); 
	ti.Start();
	cout << "\t" << "s.RecursiveBinarySearch() returned " << s.RecursiveBinarySearch(500) << " in " << ti.DurationInNanoSeconds() << endl;
	ti.End();

	cout << "Searching for a number in the middle of the array" << endl;
	ti.Start();
	cout << "\t" << "s.sequencialSearch() returned " << s.SequentialSearch(5000000) << " in " << ti.DurationInNanoSeconds() << endl;;
	ti.End();
	ti.Start();
	cout << "\t" << "s.IterativeBinarySearch() returned " << s.IterativeBinarySearch(5000000) << " in " << ti.DurationInNanoSeconds() << endl;
	ti.End();
	ti.Start();
	cout << "\t" << "s.RecursiveBinarySearch() returned " << s.RecursiveBinarySearch(5000000) << " in " << ti.DurationInNanoSeconds() << endl;
	ti.End();

	cout << "Searching for a number at the end of the array" << endl;
	ti.Start();
	cout << "\t" << "s.sequencialSearch() returned " << s.SequentialSearch(9000100) << " in " << ti.DurationInNanoSeconds() << endl;
	ti.End();
	ti.Start();
	cout << "\t" << "s.IterativeBinarySearch() returned " << s.IterativeBinarySearch(9000100) << " in " << ti.DurationInNanoSeconds() << endl;
	ti.End();
	ti.Start();
	cout << "\t" << "s.RecursiveBinarySearch() returned " << s.RecursiveBinarySearch(9000100) << " in " << ti.DurationInNanoSeconds() << endl;
	ti.End();

	cout << "Searching for a number NOT in the array" << endl;
	ti.Start();
	cout << "\t" << "s.sequencialSearch() returned " << s.SequentialSearch(-1) << " in " << ti.DurationInNanoSeconds() << endl;
	ti.End();
	ti.Start();
	cout << "\t" << "s.IterativeBinarySearch() returned " << s.IterativeBinarySearch(-1) << " in " << ti.DurationInNanoSeconds() << endl;
	ti.End();
	ti.Start();
	cout << "\t" << "s.RecursiveBinarySearch() returned " << s.RecursiveBinarySearch(-1) << " in " << ti.DurationInNanoSeconds() << endl;
	ti.End();

	return 0;
}