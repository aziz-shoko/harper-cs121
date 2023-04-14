#include <iostream>
#include <list>
#include <iterator>
#include "input.h"

using namespace std;

bool IsPrime(long num, list<long>& l);

bool IsPrime(long num, list<long>& l)
{
	bool rv=true;
	long size=l.size();
	for(auto itr=l.begin(); itr != l.end() && rv==true; itr++) {
		long div=*itr;
		if (num % div == 0) {
			rv=false;
		}
	}
	return rv;
}

int main()
{
	list<long> primes;
	primes.push_back(2);
	long count = ReadValue<long>("How many prime numbers? ",1) - 1;
	long num=3;
	while (count) {
		if (IsPrime(num,primes)) {
			primes.push_back(num);
			count--;
		}
		num++;
	}

	cout << "Prime Numbers:\n";

	for(auto itr=primes.begin(); itr != primes.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;
	return 0;
}