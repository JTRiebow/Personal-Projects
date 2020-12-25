#ifndef __ITERATOR__
#define __ITERATOR__
#include "Node.h"

class Iterator
{
public:

	Iterator(Node * start);
	~Iterator() = default;
	int operator*();
	Iterator operator++();
	bool operator!=(const Iterator& other);
	bool is_item();

private:
	Node * current = nullptr;
};

#endif