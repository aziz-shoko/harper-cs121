#include <iostream>
#include <unistd.h>
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

double& List::operator[](int& alpha) {                                        // operator overload that accepts the index value
    if (alpha < 0 || alpha >= size) {                                           // error message if the passed on index value is out of range
        cout << "\nIndex out of range!\n";
        cout << "Crashing program...";
        sleep(1);
        cout << "\nCPU Failure!!";
        sleep (1);
        cout << "\nMEMORY Failure!";
        sleep (1);
        cout << "\n01100010 01101100 01111001 01100001 01110100!!";
        exit(0);
    } 

    Node* doodoo = head;                                                    // add new node doodoo and set it to the head (we will start from the beginning)
    for (int i = 0; i < alpha; i++) {                                         // for loop that loops through the nodes until it reaches the index value node and stops
        doodoo = doodoo->next;                                              // set doodoo to the next pointer so that it can traverse through the nodes
    }                                                                       // when the loop stops, the corresponding index will become that node  

    return doodoo->value;                                                   // return the value of doodoo (the data that it stores)
}

List& List::operator+(double& data) {                                       // get the piece of data to add
    InsertNode(data);                                                       // call the insert node function to add the new node
    return *this;                                                           // return return this  or current object                                 
}

void List::Factorize(int theta) {
    int op = 0;
    bool prime = true;
    if (theta == 1 || theta == 2) {
        cout << "Prime Number: " << theta << endl;
        op = 1;
    }

    if (op != 1) {
        for (int i = 2; i*i <= theta; i++) {
            if (theta%i == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            cout << "Prime Number: " << theta << endl;
        } else {
            cout << "\nFactorized: ";
            int num = 2;
            while (theta > 1) {
                if (theta % num == 0) {
                    cout << num << " ";
                    theta /= num;
                } else {
                    num++;
                }
            }
            cout << "\n\b\b";
        }
    }
}

// Useful Links: 
// https://www.youtube.com/watch?v=e9NG_a6Z0mg&list=PLBlnK6fEyqRg7pacSDMgPn7vDVhz3N1uf&index=2&ab_channel=NesoAcademy
// https://www.tutorialspoint.com/delete-a-node-in-a-doubly-linked-list-in-cplusplus