#include "stack.h"

long Stack::Pop()
{
	if (Size() == 0) {
		throw ("Error! Queue is empty!");
	}

	//long rv=GetValue(Size()-1);
	//DeleteValue(Size()-1);
	long rv=GetValue(0);
	DeleteValue(0);
	return rv;
}

bool Stack::Push(long value)
{
	//return AddValue(value,Size());
	return AddValue(value,0);
}