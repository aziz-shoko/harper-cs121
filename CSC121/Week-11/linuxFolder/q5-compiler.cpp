/*
Azizbek Shokosimov
Week11 Q5
Demonstrate Linux
11/05/2022
csc121
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string userInput{};

int main() {
  while (true) {
    cout << "Enter your name: ";
    cin >> userInput;

    fstream file ("names.txt", ios::app);
    file << userInput << endl; 
    file.close();
  } 
 
}
