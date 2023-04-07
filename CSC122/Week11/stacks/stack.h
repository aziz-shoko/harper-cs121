#include "linkedlist.h"

#ifndef STACK_H
#define STACK_H

class Stack : public List
{
	public:
		bool Push(long value);
		long Pop();
};

#endif