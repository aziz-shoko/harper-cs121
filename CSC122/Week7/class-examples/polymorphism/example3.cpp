#include <iostream>
#include "sphere.h"

int main()
{
	Sphere* sphere_ptr=nullptr;
	sphere_ptr=new Sphere;
	if (sphere_ptr != nullptr) {
		sphere_ptr->Input();
		sphere_ptr->Display(std::cout);
	}

	return 0;
}