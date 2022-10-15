#include <iostream> 
#include <vector>															//need vector header to use vectors
using namespace std;


int main() {
	string word;
	bool repeat = true;
	while (repeat) {
		repeat = false;											
		cout << "Please enter your word : ";
		cin >> word;
		cin.ignore(numeric_limits<streamsize> :: max(), '\n');								//ignores cin value
		try {
			cout << "\nThe 6th letter of your word is : '"									//it will try to evaluate word.at(5). if it works,
				<< word.at(5) << "'.\n";													//the statement will be printed out
		}
		catch (out_of_range) {
			repeat = true;																	//if try does not work and we catch an outofrange error
			cout << "\nYour word isn't long enough for our purposes.\n"						//this statement is printed
				<< "Please try again with a longer word...\n";
		}
	}
}