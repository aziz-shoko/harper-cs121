/*
Azizbek Shokosimov
Week9 Q1
Global, Local, and Static
10/17/2022
csc121
*/

#include <iostream>
using namespace std;

void a(int);
int b(void);
void c(void);

int x = 1; 											//Global x

int main()
{
	int x = 5;										// Local x has jurisdiction
	cout << "x = " << x;							// should output x = 5 because local variable declaration takes precedence
	x *= 3;											// should output 15 because x locla value is 5 and times 3 equals 15

	{
		int x = 7;									// start a new scope within main( )
		cout << "\nx = " << b();					// new scope so x = 7, and call function b() and outputs v = 3 and v = 12 (v final value rn is 12)
	}

	a(10);										// passing on a int value 10 for function a() and x = 10, x = 50
	x = b();										// v is 12 right now not, so it returns v = 12 and v = 48
	c();											// output x = 5 and x = 35

	a(8);										// output x = 8 and x = 40
	x = b();										// v final is 48 rn so x = 192 and v = 48 and v = 192
	c();											// x = 5 and x = 35

	cout << "\nlocal x in main() = " << x << endl;			// x = 12
	return 0;
}
void a(int x) {
	// local x takes jurisdiction
	cout << "\nx = " << x;
	x *= 5;
	cout << "\nx = " << x;
}
int b(void) {
	static int v = 3;							// Static is NOT destroyed when leaving  ==> global ability to remember ==> only run the first time
	cout << "\nv = " << v;
	v *= 4;
	cout << "\nv = " << v;
	return v;
}
void c(void) {
	int x = 5;	// no local declarations for x – global will “fill in”
	cout << "\nx = " << x;
	x *= 7;
	cout << "\nx = " << x;
}