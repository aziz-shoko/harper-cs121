/*
Azizbek Shokosimov
Week 4 Q4
Using if and else statements
09/15/2022
csc121
*/

#include <iostream>                         // Library for cout and cin
using namespace std;                        // avoid using std:: 

bool x{}, y{};

int main(){
    cout << "\n0 = false and 1 = true \n\n";


    cout << "\n&& Boolean\n"; 
    cout << "\nx false, y false = " << ( 0 & 0);
    cout << "\nx true, y false = " << ( 1 & 0);
    cout << "\nx false, y true = " << ( 0 & 1);
    cout << "\nx true, y true = " << ( 1 & 1);


    cout << "\n\n|| Boolean\n";
	cout << "\nx false, y false = " << (0 | 0);
	cout << "\nx true, y false = " << (1 | 0);	
	cout << "\nx false, y true = " << (0 | 1);
	cout << "\nx true, y true = " << (1 | 1) << endl;


    cout << "\n\n^= Boolean\n";
	cout << "\nx false, y false = " << (x ^= y);
    x = 1;
    y = 0;
	cout << "\nx true, y false = " << (x ^= y);
    x = 0;
    y = 1; 
	cout << "\nx false, y true = " << (x ^= y);	
	x = 1;
    y = 1;					
	cout << "\nx true, y true = " << (x ^= y) << endl;
}