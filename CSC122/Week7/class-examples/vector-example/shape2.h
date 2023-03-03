#include <string>

#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
        public:
                Shape();
                virtual double Volume()=0;
                virtual double Area()=0;
                virtual void Input()=0;

                virtual void Display(std::ostream& out);
                virtual std::string Name();
};

#endif