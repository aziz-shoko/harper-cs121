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

#include<iostream>			                        // Place a comment next to each change
using namespace std;                                // Moved the using namespace std to the top

int a(int);
double b(double);
char c(char);
string d(string);

string name;                                        // Declaring name variable for the c and d functions

int main()
{
	int x = a(4);				                // Turned the 3.5 into 4, so we can get 4 * 2 later on for 8				

	double y = b(5.0 / 2);					    // Both 5 and 2 were int, turned 5 into a double by 5.0		

    string w = d("Enter your name ");       // Changed the order, the variable needs to be defined before being called

    char g = w[0];                                  // Added char g so we can have the first letter of the name variable 

	char z = c(g);                              // Added g so now we can have z output the first initial as a char

	cout << "\n\n\tx = " << x << endl << "\ty = " << y << endl << "\n\tname = " << w << endl << "\tfirst init = " << z << endl;
	return 0;
}

int a(int ax) 
{
	return ax * 2;                                                                                // Changed to 2, a whole number so we can 2 * 4 = 8
}

double b(double by)
{
	// cout << "\n\t in Double b( ) we see that 5 / 2 is incorrectly listed as "<<by;             // Commented text because we no longer need it
	return by;
}

char c(char cz)
{
	// cout << "\nyour first initial is " << name[0];                                             // Commented text because we no longer need it
	return name[0];
}

string d(string prompt)
{
	cout << prompt;
	cin >> name;
	return name;                                                                                  // No need for the index, need the full name
}