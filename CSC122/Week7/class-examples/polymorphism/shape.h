#include <string>

#ifndef SHAPE_H
#define SHAPE_H

class Shape {
    public: 
        Shape(); 
        virtual std::string Name() ;
        virtual double Volume();
        virtual double Area(); 
        virtual void Display (std::ostream & out);
        virtual void Input();
};

#endif
