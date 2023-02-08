#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

int main() {
    string fname;
    cout << "Enter file name: ";
    cin >> fname;

    ifstream input (fname, ios::in);
    if (input.is_open()) {
        double sum=0.0;
        int count=0, x=0;
        input >> x;                         // stores what it read into variable x
        while (!input.fail()) {             // if succesfully stored, then execute the followings commands
            cout << x << endl;
            sum += x;
            count++;
            input >> x;
        }
        if (input.eof()) {
            cout << "Average: " << sum/count << endl;
        } else {
            cerr << "Error! could not read from file!\n";
        }
        input.close();
    } else {
        cerr << "Error! Cannot open file!\n";
    }
}