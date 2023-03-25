#include <iostream>

unsigned long Factorial(unsigned long num);

unsigned long Factorial(unsigned long num)
{
	unsigned long sum=1;
	for (unsigned long i=1; i <= num; i++) {
		sum *= i;
	}
	return sum;
}

int main()
{
	std::cout << Factorial(0) << std::endl;
	std::cout << Factorial(2) << std::endl;
	std::cout << Factorial(5) << std::endl;
	return 0;
}