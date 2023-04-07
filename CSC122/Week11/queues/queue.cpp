#include "queue.h"

long Queue::Dequeue()
{
	if (Size() == 0) {
		throw ("Error! Queue is empty!");
	}

	long rv=data->value;
	DeleteValue(0);
	return rv;
}

bool Queue::Enqueue(long value)
{
	return AddValue(value,Size());
}