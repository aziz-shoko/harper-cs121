#include "linkedlist.h"

#ifndef QUEUE_H
#define QUEUE_H

class Queue : public List
{
	public:
		bool Enqueue(long value);
		long Dequeue();
};

#endif