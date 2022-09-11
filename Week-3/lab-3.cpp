/* 
Azizbek Shokosimov
lab3 
We will build tic tac toe
09/09/2022
csc121
*/

#include <iostream>            // cout and cin library
#include <iomanip>             // setw library
using namespace std;           // avoid using std::

//the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
//visit this for more color codes: https://stackoverflow.com/questions/9158150/colored-output-in-c
#define RESET       "\033[0m"              /* End Color */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */

void title(void);                                               // Declare function title
void display(char);                                             // Declay function display

char num[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};   // Declare num and create array 1 - 9
char userNum{};                                                 // Declare userNum variable                                                  

int main() {
    while ( 1==1 ) {                                            // infinite loop
        char null{};                                            // create emtpy char variable

        title();                                                // call function title
        display(null);                                          // call function display and pass on var null

        cout << "Player X enter a number: ";                    // Ouput player x enter number
        cin >> userNum;                                         // Store user input in userNum

        char X{ (userNum == num[0]) ? num[0] = 'X' : (userNum == num[1]) ? num[1] = 'X' : (userNum == num[2]) ? num[2] = 'X' : (userNum == num[3]) ? num[3] = 'X' : (userNum == num[4]) ? num[4] = 'X' : (userNum == num[5]) ? num[5] = 'X' : (userNum == num[6]) ? num[6]= 'X' : (userNum == num[7]) ? num[7] = 'X' : (userNum == num[8]) ? num[8] = 'X' : '!'};
        // Condition for player X choosing between 1 - 9
        display(X);                                             // call function display and pass on var X                                          

        cout << "Player O enter a number: ";                    // Ask player O to enter a number
        cin >> userNum;                                         // store user input in userNum

        char O{ (userNum == num[0]) ? num[0] = 'O' : (userNum == num[1]) ? num[1] = 'O' : (userNum == num[2]) ? num[2] = 'O' : (userNum == num[3]) ? num[3] = 'O' : (userNum == num[4]) ? num[4] = 'O' : (userNum == num[5]) ? num[5] = 'O' : (userNum == num[6]) ? num[6]= 'O' : (userNum == num[7]) ? num[7] = 'O' : (userNum == num[8]) ? num[8] = 'O' : '!'};
        // Condition for play O choosing between 1 - 9
        display(O);                                             // Call function display and pass on var O
    }
}

void title(){
    cout << BOLDMAGENTA <<"\n\tName: Azizbek Shokosimov";                                           // Output Name in new line in magenta and tabbed format
    cout << "\n\tDate: 08/27/2022";                                                                 // Output Date in new line with tab
    cout << "\n\tLab: Week 3 Lab";                                                                  // Output Lab Number in new line with tab
    cout << "\n\tTitle: Tic Tac Toe Project";                                                       // Output Title in new line with tab
    cout << "\n\tObjective: Create a tic tac toe board compromised of 1 through 9 digits" << RESET; // Output Objective in new line with tab

    cout << BOLDGREEN <<"\n\n\n\n\t|---------|----------|---------|";                               // Chooses the green color for title and outputs a line 
    cout << "\n\t| Tic" << setw (10) << "| Tac" << setw(11) << "| Toe" << setw(6) << "|";   // Outputs Tic Tac Toe title 
    cout << "\n\t|---------|----------|---------|" << RESET;                                        // Outputs the last line
}

void display(char) {
    cout << BOLDRED << "\n\n\n\n\t" << num[0] << setw(10) << num[1] << setw(10) << num[2];                   // Outputs evenly spaced 1, 2, 3 in red
    cout << "\n\n\n\n\t" << num[3] << setw(10) << num[4] << setw(10) << num[5];                              // Outputs evenly spaced 4, 5, 6 in red
    cout << "\n\n\n\n\t" << num[6] << setw(10) << num[7] << setw(10) << num[8] << "\n\n" << RESET << endl;   // Outputs evenly spaced 7, 8, 9 in red
}