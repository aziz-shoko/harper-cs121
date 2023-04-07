#include <iostream>
#include <exception>
#include "linkedlist.h"


Node::Node()
{
	value=0.0;
	next=nullptr;
}

Node::Node(long value)
{
	this->value=value;
	next=nullptr;
}


List::List()
{
	data=nullptr;
	size=0;
}

List::~List()
{
	Node* ptr=data;
	while (ptr) {
		std::cout << "List::~List(): DELETING " << ptr->value << std::endl;
		Node* next=ptr->next;
		delete ptr;
		ptr=next;
	}
}

long List::Size()
{
	return size;
}

bool List::AddValue(long value, long position)
{
	bool rv=false;
	Node* newNode=nullptr;

	if (position >= 0 && position <= size) {

		// Allocate node
		try {
			newNode=new Node(value);
			if (newNode == nullptr) {
				std::cerr << "List::AddValue: Error allocating node!\n";
				return rv;
			}
		}
		catch (std::exception& e) {
			std::cerr << "List::AddValue: Error allocating node!\n";
			return rv;
		}

		rv=true;

		if (position==0) {
			newNode->next=data;
			data=newNode;
		}
		else {
			Node* ptr=data;
			for (long count=1; count < position; count++) {
				ptr=ptr->next;
			}
			newNode->next=ptr->next;
			ptr->next=newNode;
		}
		++size;
	}
	return rv;
}

bool List::DeleteValue(long position)
{
	bool rv=false;
	Node* delNode;
	Node* ptr;
	if (position >=0 && position < size) {
		ptr=data;
		if (position==0) {
			delNode=ptr;
			data=data->next;
		}
		else {
			for (long count=1;count<position;count++) {
				ptr=ptr->next;
			}
			delNode=ptr->next;
			ptr->next=delNode->next;
		}
		delete delNode;
		size--;
	}
	return rv;
}

std::ostream& operator << (std::ostream& out, List& l)
{
	Node* ptr=l.data;
	while (ptr) {
		out << ptr-> value << " ";
		ptr=ptr->next;
	}
	out << "\n";
	return out;
}




bool List::SetValue(long value, long position)
{
	bool rv=false;
	if (position >=0 and position < size) {
		Node* ptr=data;
		for (long count=0;count<position;count++) {
			ptr=ptr->next;
		}
		ptr->value=value;
	}
	return rv;
}

long List::GetValue(long position)
{
	if (position >= Size() || position < 0 ) {
		throw ("List::GetValue: position out of range!");
	}
	long count=0;
	Node* ptr=data;
	while (count != position) {
		ptr=ptr->next;
		count++;
	}
	return ptr->value;
}


