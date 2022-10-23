/*
Azizbek Shokosimov
Week9 Q4
Make factorial
10/22/2022
csc121
*/

#include <iostream>                                     // cin and cout file headers
using namespace std;                                    // avoid using namespace std:: 

int factorial(int);                                     // declare function factorial

int main() {
    for (int i = 0; i < 11; i++) {                      // run program 10 times
        cout << i << "! = " << factorial(i) << endl;    // call function factorial and output the factorials
    }
}

int factorial(int i) {
    if (i > 1) {                                        // as long as i is greater than 1,
        return i*factorial(i - 1);                      // take i * call function again with i - 1 and return it
    } else {
        return 1;                                       // when i <= 1, return 1
    }
}