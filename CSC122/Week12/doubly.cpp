#include <iostream>
#include "doubly.h"
using namespace std;

Node::Node() {                                          // constructor with default values
    value = 0.0;
    next = nullptr;
    previous = nullptr;
}

List::List() {                                          // constructor with default values
    data = nullptr;
    head = nullptr;
    tail = nullptr;
    size = 0;
}

List::~List() {                                         // destructor
    Node* destruct = head;
    while (destruct != nullptr) {
        Node* next = destruct->next;
        cout << "\nRELEASING: " << destruct->value;
        delete destruct;
        destruct = next;
        cout << " ...RELEASED!";
    }
    head = nullptr;                                     // Reset nodes to nullptr
    tail = nullptr;
    size = 0;
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
                terminator->previous->next = terminator->next;              // terminator's previous pointer points to the node before it and updates that nodes next pointer to the terminator's next pointer which points to the next node
                terminator->next->previous = terminator->previous;          // terminator's next pointer oints to the node after it and updates that nodes previous pointer with it's own previous pointer which points to the node before it 
            }
            delete terminator;                                              // delete terminator
            size--;                                                         // decrement size by 1
        }
        terminator = terminator->next;                                      // just set terminator to terminator next value
    }
}



void List::ValueSetter(double x) {                                          // set value for value
    value = x;
}

double List::ValueGetter() {                                                // get value for value
    return value;
}

void List::DisplayForward() {                                               // display the linked list forwards
    Node* forward = head;
    while (forward != nullptr) {
        cout << forward->value << " ";                                      // output value
        forward = forward->next;                                            // move on to the next node
    }
    cout << endl;
}

void List::DisplayBackward() {                                              // display the linked list backwards
    Node* backward = tail;
    while (backward != nullptr) {
        cout << backward->value << " ";                                     // output the value
        backward = backward->previous;                                      // move on to the previous node
    }
    cout << endl;
}

double& List::operator[](int& numerator) {
    if (numerator < 0 || numerator >= size) {
        throw std::out_of_range("numerator out of range");
    }

    Node* doodoo = head;
    for (int i = 0; i < numerator; i++) {
        doodoo = doodoo->next;
    }

    return doodoo->value;
}

// Useful Links: 
// https://www.youtube.com/watch?v=e9NG_a6Z0mg&list=PLBlnK6fEyqRg7pacSDMgPn7vDVhz3N1uf&index=2&ab_channel=NesoAcademy
// https://www.tutorialspoint.com/delete-a-node-in-a-doubly-linked-list-in-cplusplus