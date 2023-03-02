#include <iostream>
#include "sphere.h"

int main()
{
	Shape* shape_ptr=nullptr;
	shape_ptr=new Sphere;

	if (shape_ptr != nullptr) {
		shape_ptr->Input();
		shape_ptr->Display(std::cout);
	}

	return 0;
}