#include <iostream>                                                                             // file headers
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include "dollar.h"                                                                             // includes the dollar validator from week 2 assignment
using namespace std;

$ dollarObj;                                                                                    // create object for the class in dollar.h
double fileRate, fileMonth, fileBalance;                                                        // declare my variables and functions
string readFileName, balance;
void readFunc(string);
void writeFunc(string);
void monthlyCompound(double, double, double);
string dollarFormatter(double);

int main() {
    cout << "Enter filename (to read from): ";                                                  // get filename to read from
    cin >> readFileName;
    readFunc(readFileName);                                                                     // pass the filename into readFunc
    monthlyCompound(fileBalance, fileRate, fileMonth);                                          // pass the three set variables readFunc to monthlyCompound func for calculation and writing into a file
}

void readFunc(string readFileName) {
    ifstream read(readFileName, ios::in);                                                       // open filename for read
    if (read.is_open()) {
        int i = 0;                                                                              // variable for incrementing purposes
        char balenciaga1[100];                                                                  // char array to store the read inputs
        cout << "\n\t------File Contents------\n";
        while (!read.fail()) {                                                                  // loop through file contents 
            if (i == 0){                                                                        // first read item
                read >> balenciaga1;                                                            // store the first read item into balenciaga1
                if (!dollarObj.dollarValidator(balenciaga1)) {                                  // make sure the first input value is a valid dollar format by checking it in dollarValidator method
                    cerr << "\nFile contains invalid dollar input!\n";                          // if not valid dollar, then exit program
                    exit(0);
                }
                fileBalance = dollarObj.doubleConvertor(balenciaga1);                           // convert the obtained dollar value into a double for calculation purposes by called the doubleConvertor function
                cout << "\n\tInitial Balance: " << balenciaga1 << endl;                         // output the value of the initial balance
            } else if (i == 1){                                                                 // second item
                read >> fileRate;                                                               // store the second item inside the filerate double var
                cout << "\tInterest Rate: " << fileRate << endl;                                // display the value of the interest rate
            } else if (i == 2) {                                                                // third item
                read >> fileMonth;                                                              // store number of months inside the fileMonth varialbe
                cout << "\tNumber of Months: " << fileMonth << "\n\n";                          // display the number of months 
            } 
            i++;                                                                                // increment i by 1
            if (read.eof()) {                                                                   // exit the loop when end of file is reached
                break;
            }
        }
        read.close();                                                                           // close file
    } else {
        cerr << "Error Opening File!\n";                                                        // in case file fails to open, exit program and display error message
        exit(0);
    }
}

// Needed variables for the calculation: x = initial balance, y = interest rate, z = number of months
void monthlyCompound(double x, double y, double z) {                                            // function for calculating the monthly compound and outputting into a file
    double newBalance, a{0}, b{0};                                                              // needed variables for calculations
    string outputFile;
    a = (1+y/12);                                                                               // first part of the equation
    cout << "\t---Monthly Compound---\n\n";
    for (double i = 0; i <= z; i++) {                                                           // loop for the calculation (loops through by number of month being compounded)
        b = 12*(i/12);                                                                          // calculate the exponent part of the equation (diffrent value for each month)
        newBalance = x*pow(a, b);                                                               // get the final value of the calculated balance
        balance = dollarFormatter(newBalance);                                                  // pass onto dollar formatter to get string value with the right commas in place
        cout << setw(10) << i << "   $" << balance << endl;                                         // output the calculated values with setw formatting
    }
    cout << "\n\nEnter filname to save: ";                                                      // ask for which file to save to
    cin >> outputFile;
    ofstream output(outputFile, ios::out);                                                      // open filename to write to or create

    if (output.is_open()) {
        for (double i = 0; i <= z; i++) {                                                       // do the steps above but stream the value into a file instead of the terminal
            int p = i;
            b = 12*(i/12);
            newBalance = x*pow(a, b);
            balance = dollarFormatter(newBalance);
            output.width(5);                                                                    // formatting functions
			output.setf(ios::fixed|ios::showpoint|ios::right);
            output << defaultfloat << p << "   $" << balance << endl;
        }
        cout << "\nSaved ===> " << outputFile << endl;
        output.close();
    } else {
        cout << "\nError! Save failed for " << outputFile << "!" << endl;
    }
}

string dollarFormatter(double newBalance) {
    ostringstream stream;                                                          // create the stringstream object stream
    stream << fixed << setprecision(2) << newBalance;                               // now we can use setprecision function on newBalance and store that into a separate string called stringBalance
    string stringBalance = stream.str();                                           // the newBalance gets converted into a string called stringBalance

    int position = stringBalance.length() - 6;                                     // the last 6 positions cannot have a comma so its disregarded, position stands for the position of the array in stringBalance
    for (int i = stringBalance.length() - 6; i > 0; i = i -3 ) {                   // starting at the position where the first comma is suppose to be, increment backwards by 3 because comma is needed every three digits
        stringBalance.insert(position, ",");                                      // insert the comma string inside stringBalance (format: insert(element-position, value-to-insert))
    }

    return stringBalance;                                                           // return the new string stringBalance;
}