#ifndef TREE_H
#define TREE_H

#include <iostream>

struct Node 
{
	public:
		long value;
		Node* left;
		Node* right;
		Node();
		Node(long value);
};

class Tree
{
	protected:
		Node* data;
		void Clear(Node* ptr);
		void InsertNode(Node* ptr, Node* newNode);
		void Output(std::ostream& out, Node* ptr);
		bool Exists(Node* ptr, long value);

	public:
		Tree();
		~Tree();
		bool AddValue(long value);
		bool Exists(long value);
		void Clear();

		friend std::ostream& operator << (std::ostream& out, Tree& l);
		friend std::istream& operator >> (std::istream& in, Tree& l);
};

#endif
