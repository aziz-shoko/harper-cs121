/*
Azizbek Shokosimov
Week 4 Q4
Using if and else statements
09/15/2022
csc121
*/

#include <iostream>                         // Library for cout and cin
using namespace std;                        // avoid using std:: 

bool x{}, y{};                                          // Declaring variable boox x and y

int main(){     
    cout << "\n0 = false and 1 = true \n\n";                // Output text in quotes


    cout << "\n&& Boolean\n";                   
    cout << "\nx false, y false = " << ( 0 & 0);            // program check for false and false
    cout << "\nx true, y false = " << ( 1 & 0);             // program check for true and false
    cout << "\nx false, y true = " << ( 0 & 1);             // program check for false and true
    cout << "\nx true, y true = " << ( 1 & 1);              // program check for false and false


    cout << "\n\n|| Boolean\n";
	cout << "\nx false, y false = " << (0 | 0);             // program check for false or false
	cout << "\nx true, y false = " << (1 | 0);	            // program check for true or false
	cout << "\nx false, y true = " << (0 | 1);              // program check for false or true
	cout << "\nx true, y true = " << (1 | 1) << endl;       // program check for true or true


    cout << "\n\n^= Boolean\n";
	cout << "\nx false, y false = " << (x ^= y);            // program check for false or false
    x = 1;
    y = 0;
	cout << "\nx true, y false = " << (x ^= y);             // program check for true or false
    x = 0;
    y = 1; 
	cout << "\nx false, y true = " << (x ^= y);	            // program check for false or true
	x = 1;
    y = 1;					
	cout << "\nx true, y true = " << (x ^= y) << endl;      // program check for true or true
}