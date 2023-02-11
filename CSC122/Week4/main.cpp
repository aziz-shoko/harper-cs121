#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "dollar.h"
using namespace std;

$ dollarObj;
double fileRate, fileMonth, fileBalance;
string readFileName;
void readFunc(string);
void writeFunc(string);
void monthlyCompound(double, double, double);

int main() {
    cout << "Enter filename (to read from): ";
    cin >> readFileName;
    readFunc(readFileName);
    monthlyCompound(fileBalance, fileRate, fileMonth);
}

void readFunc(string readFileName) {
    ifstream read(readFileName, ios::in);
    if (read.is_open()) {
        int i = 0;
        char balenciaga1[100];
        cout << "\n\t------File Contents------\n";
        while (!read.fail() && i < 3) {
            if (i == 0){
                read >> balenciaga1;
                if (!dollarObj.dollarValidator(balenciaga1)) {
                    cerr << "\nFile contains invalid dollar input!\n";
                    exit(0);
                }
                fileBalance = dollarObj.doubleConvertor(balenciaga1);
                cout << "\n\tInitial Balance: " << balenciaga1 << endl;
            } else if (i == 1){
                read >> fileRate;
                cout << "\tInterest Rate: " << fileRate << endl;
            } else if (i == 2) {
                read >> fileMonth;
                cout << "\tNumber of Months: " << fileMonth << "\n\n";
            } 
            i++;
        }
        read.close();
    } else {
        cerr << "Error Opening File!\n";
    }
}

void monthlyCompound(double x, double y, double z) {
    double newBalance, a{0}, b{0};
    string outputFile;
    a = (1+y/12);
    cout << "\t---Monthly Compound---\n\n";
    for (double i = 0; i <= z; i++) {
        b = 12*(i/12);
        newBalance = x*pow(a, b);
        cout << setw(10) << i << "   $" << newBalance << endl;
    }
    cout << "\n\nEnter filname to save: ";
    cin >> outputFile;
    ofstream output(outputFile, ios::out);

    if (output.is_open()) {
        for (double i = 0; i <= z; i++) {
            int p = i;
            b = 12*(i/12);
            newBalance = x*pow(a, b);
            output.width(5);
			output.setf(ios::fixed|ios::showpoint|ios::right);
            output << defaultfloat << p << "   $" << fixed << setprecision(2) << newBalance << endl;
        }
    }
}