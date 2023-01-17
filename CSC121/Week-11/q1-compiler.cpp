/*
Azizbek Shokosimov
Week11 Q1
Use pointers
11/2/2022
csc121
*/

/*
Pointers allow us to store the memory address of variables in a another variable
The syntax is as follows:
Variable declaration: string *varName
Dereferencing: *varaName
*/
#include <iostream>
using namespace std;

int main() {
    int x{500};
    int *pointerX{&x};
    cout << "Interger pointer: " << *pointerX;

    char y{'a'};
    char *pointerY{&y};
    cout << "\nCharacter pointer: " << *pointerY;

    string z{"randomString"};
    string *pointerZ {&z};
    cout << "\nString pointer: " << *pointerZ << endl;
}