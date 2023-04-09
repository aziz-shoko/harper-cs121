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

void List::RemoveNode(double val) {                                         // RemoveNode function that accepts a double data type value
    Node* terminator = head;                                                // Create a new node and set it equal to head (gonna have to start at head)
    while (terminator != nullptr) {                                         // while loop to loop through the nodes (nullptr means the end of the list)
        if (terminator->value == val) {                                     // condition for checking to see if the value of terminator equals to the passed in value
            if (terminator == head) {                                       // if the passed in value happens to be the head,
                head = terminator->next;                                    // head now becomes the next node because it stores the value of the terminator's next pointer
                if (head != nullptr) {                                      // condition for head not being a nullptr
                    head->previous = nullptr;                               // must set the head previous to nullptr since we will no longer have a node before it
                } else {
                    tail = nullptr;                                         // sets the tail to nullptr as well because incase of empty list, we would want tail to also be a nullptr
                }
            } else if (terminator == tail) {                                // condition for if the node being deleted is the last one
                tail = terminator->previous;                                // tail now becomes the previous node
                if (tail != nullptr) {                                      // condition for nullptr
                    tail->next = nullptr;                                   // the tail next must be set to nullptr to cut off the last node pointer connection 
                } else {
                    head = nullptr;                                         // again, if the list is empty, then the head will also be a nullptr
                }
            } else {                                                        // condition if the node being is removed is neither the head or tail
                terminator->previous->next = terminator->next;              // the previous pointer of the node before the terminator node is updated to point to the node after it
                terminator->next->previous = terminator->previous;          // the next pointer of the node after terminator node is being updated to point to the node before it 
            }
            delete terminator;                                              // delete terminator
            size--;                                                         // decrement size by 1
        } else {
            cout << "\nDid not match any existing data!\n\n";               // Error message in case the user puts in not matching data
            break;
        }
        terminator = nullptr;                                               // just set terminator to nullptr after deletion
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