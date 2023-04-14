#include <iostream>
#include <exception>
#include "tree.h"


Node::Node()
{
	value=0.0;
	left=nullptr;
	right=nullptr;
}

Node::Node(long val)
{
	value=val;
	left=nullptr;
	right=nullptr;
}


Tree::Tree()
{
	data=nullptr;
}

Tree::~Tree()
{
	Clear();
}

void Tree::Clear(Node* ptr)
{
	if (ptr->left != nullptr)
		Clear(ptr->left);
	if (ptr->right != nullptr) 
		Clear(ptr->right);
	delete ptr;
}

void Tree::Clear()
{
	if (data)
		Clear(data);
}

void Tree::InsertNode(Node* ptr, Node* newNode)
{
	if (ptr->value == newNode->value)
		return;
	if (ptr->value > newNode->value) {
		if (ptr->left != nullptr) {
			InsertNode(ptr->left, newNode);
		}
		else {
			ptr->left=newNode;
		}
	}
	else {
		if (ptr->right != nullptr) {
			InsertNode(ptr->right, newNode);
		}
		else {
			ptr->right=newNode;
		}
		
	}
}

bool Tree::AddValue(long value)
{
	bool rv=true;
	try {
		Node* newNode=new Node(value);
		if (newNode != nullptr) {
			if (data != nullptr) {
				InsertNode(data, newNode);
			}
			else {
				data=newNode;
			}
		}	
		else {
			rv=false;
		}

	}
	catch (std::exception& e) {
		std::cerr<<e.what()<<std::endl;
		rv=false;
	}

	return rv;
}

bool Tree::Exists(Node* ptr, long value)
{
	if (ptr->value==value) 
		return true;
	if (ptr->value > value) 
		return (ptr->left==nullptr)?false:Exists(ptr->left,value);
	return (ptr->right==nullptr)?false:Exists(ptr->right,value);
}

bool Tree::Exists(long value)
{
	if (data == nullptr) 
		return false;
	return Exists(data, value);
}

void Tree::Output(std::ostream& out, Node* ptr)
{
	if (ptr->left) 
		Output(out,ptr->left);
	out << ptr->value << " ";
	if (ptr->right) 
		Output(out,ptr->right);
}

std::ostream& operator << (std::ostream& out, Tree& l)
{
	if (l.data)
		l.Output(out, l.data);
	else 
		out << "Tree is empty.\n";
	return out;
}

std::istream& operator >> (std::istream& in, Tree& l)
{
	long value=0;
	in >> value;
	if (!in.fail()) {
		l.AddValue(value);
	}
	return in;
}


