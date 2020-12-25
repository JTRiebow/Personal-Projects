#include <iostream>
#include "LinkedList.h"
LinkedList::~LinkedList()
{
	DestructorHelper(head);
}
void LinkedList::PrintList() const
{
	PrintListHelper(head);
}
void LinkedList::Insert(Course * newCourse)
{
	head = InsertHelper(head, newCourse);
}
int LinkedList::Size() const
{
	return SizeHelper(head);
}
double LinkedList::CalculateGPA() const
{

	return (CalculateTotalGradePoints(head) / CalculateTotalCredits(head));

}
Course * LinkedList::InsertHelper(Course * head, Course * newCourse)
{
	RecursionCounter rcTmp;   // used for testing purposes
   // add your code here...

	if (head == nullptr)
	{
		Course* tmp = new Course(*newCourse);
		return tmp;
	}

	else if (head->courseNumber >= newCourse->courseNumber)
	{
		Course* tmp = new Course(*newCourse);
		tmp->next = head;
		return tmp;
	}

	else
	{
		head->next = InsertHelper(head->next, newCourse);
		return head;
	}


	return 0;
}

int LinkedList::SizeHelper(Course const * cursor) const
{
	RecursionCounter rcTmp;   // used for testing purposes
   // add your code here
	int size = 0;

	if (cursor == nullptr)
	{
		return size;
	}
	size = 1 + SizeHelper(cursor->next);
	return size;
}

void LinkedList::PrintListHelper(Course const * cursor) const
{
	RecursionCounter rcTmp;   // used for testing purposes
   // add your code here
	if (cursor != nullptr)
	{
		std::cout << "cs" << cursor->courseNumber << " ";
		std::cout << cursor->courseName << " ";
		std::cout << "Grade:" << cursor->grade << " ";
		std::cout << "Credit Hours: " << cursor->credits << std::endl;

		return PrintListHelper(cursor->next);
	}
	return;
}

void LinkedList::DestructorHelper(Course * cursor)
{
	RecursionCounter rcTmp;   // used for testing purposes
   // add your code here
	if (cursor == nullptr)
	{
		return;
	}

	DestructorHelper(cursor->next);
	delete cursor;
}


double LinkedList::CalculateTotalGradePoints(Course const * cursor) const
{
	RecursionCounter rcTmp;   // used for testing purposes
   // add your code here
	if (cursor == nullptr)
	{
		return 0;
	}
	else
	{
		return cursor->grade * cursor->credits + CalculateTotalGradePoints(cursor->next);
	}
}

unsigned int LinkedList::CalculateTotalCredits(Course const * cursor) const
{
	RecursionCounter rcTmp;   // used for testing purposes
   // add your code here
	if (cursor == nullptr)
	{
		return 0;
	}
	else
	{
		return cursor->credits + CalculateTotalCredits(cursor->next);
	}
}
