/*
Azizbek Shokosimov
Week-2 Lab-2
Troubleshoot data types and casting
09/03/2022
csc121
*/

/* Lab 2 Fix the code
The output should be:
x = 8
y = 2.5
name = gary
first init = g

*/

#include<iostream>			// Place a comment next to each change

int a(int);
double b(double);
char c(char);
string d(string);

using namespace std;
int main()
{
	int x = a(3.5);								

	double y = b(5 / 2);							

	char z = c(w);

	string w = d("Enter your name ");

	cout << "\n\nBack in main() \n\tx = " << x << "\ty = " << y << "\n\tname = " << w << "\tfirst init = "<<z<<endl;
	return 0;
}

int a(int ax) 
{
	return ax * 2.5;
}

double b(double by)
{
	cout << "\n\t in Double b( ) we see that 5 / 2 is incorrectly listed as "<<by;
	return by;
}

char c(char cz)
{
	cout << "\nyour first initial is " << name[0];
	return name;
}

string d(string prompt)
{
	cout << prompt;
	cin >> name;
	return name[0];
}

