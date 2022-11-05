/*
Azizbek Shokosimov
Week11 Q2
Use pointers
11/2/2022
csc121
*/

/*
Indirect addressing is just calling the memory address of the operand rather than the operand itself. 

Indirection operator is the * symbol that is used to work along with the & operator to call and store memory addresses. 

A pointer can be used to store the memory address of a variable.  So call a function and pass on the memeory address with &varName and store the address using a pointer variable. 
Then simply use dereferencing to modify the values of the variable. Note! This will also change the value of the original variable.
*/

#include <iostream>                 // file headers
using namespace std;                // avoid using std::

void example(string*);              // declare function example

int main() {
    string testCase{"text"};        // set value of testCase to text
    example(&testCase);             // pass on memory address of testCase

    cout << testCase << endl;       // output new value of testCase
}

void example (string *memory) {     // store memory address in memory
    *memory = "Changed text";       // set value to Changed text
}
