#include <iostream>
#include "input.h"

using namespace std;

bool IsPrime(unsigned long num, unsigned long divisor=2); 

bool IsPrime(unsigned long num, unsigned long divisor) 
{
	if (num == 2)
		return true;
	if (num < 2)
		return false;
	if (num % divisor == 0) 
		return false;
	if (divisor * divisor > num)
		return true;
	return IsPrime(num, divisor+1);
}


int main()
{
	unsigned long number=ReadValue<unsigned long>("Enter a number: ");

	if (IsPrime(number))
		cout << "Number is prime.\n";
	else
		cout << "Number is not prime.\n";
	return 0;
}