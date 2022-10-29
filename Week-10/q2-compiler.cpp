/*
Azizbek Shokosimov
Week10 Q1
IFstream
10/29/2022
csc121
*/

/*
ifstream is used to open a file and read from it
do ifstream object-name ("filename", arg); to open a file
then use while loops or for loops to output data into console
eof means end of file
*/

#include <iostream>                         // file headers
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("names.txt");             // open file names.txt and read from it

    string names;                           // declare var names
    while (file >> names) {                 // while data from file is streamed into names
        cout << names << " ";               // output the names value
    }
}