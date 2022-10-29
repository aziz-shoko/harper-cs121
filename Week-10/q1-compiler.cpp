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
The synxtax for opening a file: void open(const char *filename, ios::openmode mode);
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
    string filename{};
    cout<< "Enter file name: ";
    cin >> filename;

    ofstream file (filename, ios::app);    // opens file names.txt, if it already exists, it then creates it
    if (!file.is_open()) {
        cout << "File couldn't be opened";
    }

    file << "\nAzizbek Shokosimov";           // outputs the text into the file
    file.close();                             // closefile
}