#ifndef __LIST
#define __LIST__
#include "Node.h"
#include "Iterator.h"

class List
{
public:

	List();
	~List();
	void push_front(const int& data);
	void push_back(const int& data);
	void remove(const int& data);
	void PrintList();
	Iterator begin();
	Iterator end();
	int Size();

private:
	Node * head;
	int size;
};

#endif