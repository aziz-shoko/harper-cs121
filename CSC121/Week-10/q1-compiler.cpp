/*
Azizbek Shokosimov
Week10 Q1
OFstream
10/29/2022
csc121
*/

/*
The ofsteam needs fstream fileheader
Ofstream is used to create and write into files
The syntax for opening a file: void open(const char *filename, ios::openmode mode);
ofstream somename ("filename", argument);  this opens file
file.close(); closes file and is optional for c++11
ios::out -  overrides previous text

ios::app - doesnt override previous text

ios::in - reads text from the file.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename{};                     // declare string filename
    cout<< "Enter file name: ";            // ask for filename
    cin >> filename;                       // store in filename var

    // file stands for the object name, and filename is the actual filename
    ofstream file (filename, ios::app);    // opens file with value filename, if it already exists, it then creates it
    if (!file.is_open()) {                 // if it fails to open, cout the text in quotes
        cout << "File couldn't be opened";
    }

    file << "\nAzizbek Shokosimov";           // outputs the text into the file
    file.close();                             // closefile
}