#include <iostream>
#include <string>

using namespace std;

enum fruit {apple=0, pear, peach, cherry, banana};

istream& operator>> (istream& in, fruit& x);
ostream& operator<< (ostream& out, fruit& x);

ostream& operator<< (ostream& out, fruit& x)
{
	if (x==apple) {
		out << "apple";
	}
	else if (x==pear) {
		out << "pear";
	}
	else if (x==peach) {
		out << "peach";
	}
	else if (x==cherry) {
		out << "cherry";
	}
	else if (x==banana) {
		out << "banana";
	}
	else {
		throw "Error! Unknown fruit!";
	}
	return out;
}

istream& operator>>(istream& in, fruit& x)
{
	string input;
	in >> input;
	if (input=="apple") {
		x=apple;
	}
	else if (input=="pear") {
		x=pear;
	}
	else if (input=="peach") {
		x=peach;
	}
	else if (input=="cherry") {
		x=cherry;
	}
	else if (input=="banana") {
		x=banana;
	}
	else {
		throw "Error! Unknown fruit!";
	}
	return in;
}

int main() 
{
	try {
		fruit f;
		cout << "Enter a fruit: ";
	
		cin >> f; 
	
		cout << "You entered: " << f << endl;
	}

	catch (const char* msg) {
		cerr << msg << endl;
	}

	return 0;
}

// watch this for more info on operator overload
// https://www.youtube.com/watch?v=BnMnozsSPmw&ab_channel=CodeBeauty