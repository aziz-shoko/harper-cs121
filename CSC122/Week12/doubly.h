#include <iostream>
using namespace std;

#ifndef DOUBLY
#define  DOUBLY

// struct for one Node 
struct Node {
    double value;
    Node* next;
    Node* previous;
    Node();                             // make sure specify the Node as contructor here or else you will get noexcept errors in the other file(doubly.cpp)
};
class List: public Node {
    protected:
        Node* data;
        Node* head;
        Node* tail;
        int size;

    public:
        List();
        ~List();
        void InsertNode(double);
        void RemoveNode(double);
        void ValueSetter(double);
        double ValueGetter();

        void DisplayForward();
        void DisplayBackward();

    
    double& operator[](int&);
    List& operator+(double&);
};

#endif