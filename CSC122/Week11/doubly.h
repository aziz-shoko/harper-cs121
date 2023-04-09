#include <iostream>
using namespace std;

#ifndef DOUBLY
#define  DOUBLY

struct Node {
    double value;
    Node* next;
    Node* previous;
    Node();
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
        void RemoveNode();
        void ValueSetter(double);
        double ValueGetter();

        void DisplayForward();
        void DisplayBackward();
};

#endif