

#include <iostream> 
#include <vector>															
using namespace std;


int main() {
	string word;
	bool repeat = true;
	while (repeat) {
		repeat = false;											
		cout << "Please enter your word : ";
		cin >> word;
		cin.ignore(numeric_limits<streamsize> :: max(), '\n');								
		try {
			cout << "\nThe 6th letter of your word is : '"									
				<< word.at(5) << "'.\n";													
		}
		catch (out_of_range) {
			repeat = true;																	
			cout << "\nYour word isn't long enough for our purposes.\n"						
				<< "Please try again with a longer word...\n";
		}
	}
}