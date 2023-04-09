#include <iostream>
#include "doubly.h"
using namespace std;

Node::Node() {
    value = 0.0;
    next = nullptr;
    previous = nullptr;
}

List::List() {
    data = nullptr;
    head = nullptr;
    tail = nullptr;
    size = 0;
}

List::~List() {
    Node* ptr = data;
    while (ptr != nullptr) {
        Node* next = ptr->next;
        delete ptr;
        ptr=next;
        cout << "RELEASED: " << ptr->value << endl;
    }
}

// Function for adding a new node
void List::InsertNode(double val) {                     // accepts a given double data type value to store
    Node* node = new Node();                            // Allocate new memory for a node to store the passed in data
    node->value = val;                                  // set the value of the node to the passed in data
    node->next = nullptr;                               // set the next pointer to null (will always be null because this represents a node at the end of the list)
    node->previous = tail;                              // sets the previous to the value of tail of the last node 
    if (size == 0) {                                    // if its the first node, then then it becomes the head
        head = node;
    } else {                                            // if its not the first node, then it will get added to the last part of the list
        tail->next = node;                              // by setting the next value of previous to point to the new node
    }
    tail = node;                                        // the new node now becomes the tail
    size++;                                             // the size is incremented by 1
}

void List::RemoveNode(double val) {
    Node* terminator;
    while (terminator != nullptr) {

    }
}

void List::ValueSetter(double x) {
    value = x;
}

double List::ValueGetter() {
    return value;
}

void List::DisplayForward() {
    Node* forward = head;
    while (forward != nullptr) {
        cout << forward->value << " ";
        forward = forward->next;
    }
    cout << endl;
}

void List::DisplayBackward() {
    Node* backward = tail;
    while (backward != nullptr) {
        cout << backward->value << " ";
        backward = backward->previous;
    }
    cout << endl;
}