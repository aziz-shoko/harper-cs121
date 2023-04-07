#include <iostream>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node 
{
	public:
		long value;
		Node* next;
		Node();
		Node(long value);
};

class List
{
	protected:
		Node* data;
		long size;

	public:
		List();
		~List();
		long Size();
		bool AddValue(long value, long position);
		bool DeleteValue(long position);
		bool SetValue(long value, long position);
		long GetValue(long position);

		friend std::ostream& operator << (std::ostream& out, List& l);
};

#endif
