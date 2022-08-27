/*
Azizbek Shokosimov
Lab 1
Create a title and a tic tac toe of a number board
08/27/2022
csc121
*/

//the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
#define RESET       "\033[0m"              /* End Color */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */

#include <iostream>            // cout library
#include <iomanip>             // setw library
using namespace std;           // sets namespace to std to avoid std::

int main() {                                                                                        // Start Program
    cout << BOLDMAGENTA <<"\n\tName: Azizbek Shokosimov";                                           // Output Name in new line in magenta and tabbed format
    cout << "\n\tDate: 08/27/2022";                                                                 // Output Date in new line with tab
    cout << "\n\tLab: Week 1 Lab";                                                                  // Output Lab Number in new line with tab
    cout << "\n\tTitle: Tic Tac Toe Project";                                                       // Output Title in new line with tab
    cout << "\n\tObjective: Create a tic tac toe board compromised of 1 through 9 digits" << RESET; // Output Objective in new line with tab
    
    cout << BOLDGREEN <<"\n\n\n\n\t|---------|----------|---------|";                               // Chooses the green color for title and outputs a line 
    cout << "\n\t| Tic" << setw (10) << "| Tac" << setw(11) << "| Toe" << setw(6) << "|";           // Outputs Tic Tac Toe title 
    cout << "\n\t|---------|----------|---------|" << RESET;                                        // Outputs the last line

    cout << BOLDRED << "\n\n\n\n\t 1" << setw(10) << "2" << setw(10) << "3";                        // Outputs evenly spaced 1, 2, 3
    cout << "\n\n\n\n\t 4" << setw(10) << "5" << setw(10) << "6";                                   // Outputs evenly spaced 4, 5, 6
    cout << "\n\n\n\n\t 7" << setw(10) << "8" << setw(12) << "9\n\n" << RESET << endl;              // Outputs evenly spaced 7, 8, 9
    
    return 0;                                                                                       // End program
}
