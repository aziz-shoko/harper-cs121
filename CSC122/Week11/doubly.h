#include <iostream>
using namespace std;

#ifndef DOUBLY
#define  DOUBLY

class Doubly {
    protected:
        double alpha;

    public:
        Doubly();
        ~Doubly();
        void Insert();
        void Remove();
        void Setter();
        double Getter();
};  

#endif