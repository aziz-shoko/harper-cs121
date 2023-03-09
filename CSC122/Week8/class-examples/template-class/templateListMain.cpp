#include <iostream>
#include <cstdlib>
#include <ctime>
#include "templateList.h"

void ShowData(List<double>& l);


void ShowData(List<double>& l)
{
	try {
		std::cout << "List:\n";
		l.Display(std::cout);
		std::cout << "Num: " << l.Count() << std::endl;
		std::cout << "Min: " << l.Min() << std::endl;
		std::cout << "Max: " << l.Max() << std::endl;
		std::cout << "Avg: " << l.Average() << std::endl;
		std::cout << "Med: " << l.Median() << std::endl;
		l.Sort();
		std::cout << "Sorted list:\n";
		l.Display(std::cout);
		std::cout << "\n\n";

	}

	catch (const char* e) {
		std::cerr << e << std::endl;
	}
}

int main()
{
	List<double> l;
	srand(time(0));

	l.Random(20,1,100);
	ShowData(l);

	std::cout << "Removing duplicates\n";
	l.Unique();
	ShowData(l);

	return 0;
}