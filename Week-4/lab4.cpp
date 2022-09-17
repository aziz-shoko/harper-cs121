/* 
Azizbek Shokosimov
lab4
We will build tic tac toe
09/16/2022
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
int angelpoop{1};
char nickpoop{};                                                  

int main() {
    char null{};                                            // create emtpy char variable

    title();                                                // call function title
    display(null);                                          // call function display and pass on var null

    while ( 1==1 ) {
        if ( angelpoop%2 == 1) {
            nickpoop = 'X';
        } else {
            nickpoop = 'O';
        }

        cout << "Player " << nickpoop <<" enter a number: ";                    // Ouput player x enter number
        cin >> userNum;                                         // Store user input in userNum

        char X{ (userNum == num[0] && num[0] != 'O' && num[0] !='X') ?                           // Condition for player X choosing between 1 - 9
            num[0] = nickpoop: 
                (userNum == num[1] && num[1] != 'O' && num[1] !='X') ? 
                    num[1] = nickpoop: 
                        (userNum == num[2] && num[2] != 'O' && num[2] !='X') ? 
                            num[2] = nickpoop: 
                                (userNum == num[3] && num[3] != 'O' && num[3] !='X') ? 
                                    num[3] = nickpoop: 
                                        (userNum == num[4] && num[4] != 'O' && num[4] !='X') ? 
                                            num[4] = nickpoop: 
                                                (userNum == num[5] && num[5] != 'O' && num[5] !='X') ? 
                                                    num[5] = nickpoop: 
                                                        (userNum == num[6] && num[6] != 'O' && num[6] !='X') ? 
                                                            num[6]= nickpoop: 
                                                                (userNum == num[7] && num[7] != 'O' && num[7] !='X') ? 
                                                                    num[7] = nickpoop: 
                                                                        (userNum == num[8] && num[8] != 'O' && num[8] !='X') ? 
                                                                            num[8] = nickpoop: '!'};
        
        if ( userNum == '1' ) {
            if ( num[0] != nickpoop ) {
                angelpoop--;
                cout << "This is invalid!";
            }
        } else if ( userNum == '2' ) {
            if ( num[1] != nickpoop ) {
                angelpoop--;
            }
        } else if ( userNum == '3' ) {
            if ( num[2] != nickpoop ) {
                angelpoop--;
            }
        } else if ( userNum == '4' ) {
            if ( num[3] != nickpoop ) {
                angelpoop--;
            }
        } else if ( userNum == '5' ) {
            if ( num[4] != nickpoop ) {
                angelpoop--;
            }
        } else if ( userNum == '6' ) {
            if ( num[5] != nickpoop ) {
                angelpoop--;
            }
        } else if ( userNum == '7' ) {
            if ( num[6] != nickpoop ) {
                angelpoop--;
            }
        } else if ( userNum == '8' ) {
            if ( num[7] != nickpoop ) {
                angelpoop--;
            }
        } else if ( userNum == '9' ) {
            if ( num[8] != nickpoop ) {
                angelpoop--;
            }
        }

        display(X);                                             // call function display and pass on var X    
        angelpoop++;                                      
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

    if (num[0] == 'X' && num[1] == 'X' && num[2] == 'X') {
        cout << "Congratulations! Player X wins!\n";
        exit(0);
    } else if (num[3] == 'X' && num[4] == 'X' && num[5] == 'X') {
        cout << "Congratulations! Player X wins!\n";
        exit(0);
    } else if (num[6] == 'X' && num[7] == 'X' && num[8] == 'X') {
        cout << "Congratulations! Player X wins!\n";
        exit(0);
    } else if (num[0] == 'X' && num[4] == 'X' && num[8] == 'X') {
        cout << "Congratulations! Player X wins!\n";
        exit(0);
    } else if (num[2] == 'X' && num[4] == 'X' && num[6] == 'X') {
        cout << "Congratulations! Player X wins!\n";
        exit(0);
    } 

    if (num[0] == 'O' && num[1] == 'O' && num[2] == 'O') {
        cout << "Congratulations! Player O wins!\n";
        exit(0);
    } else if (num[3] == 'O' && num[4] == 'O' && num[5] == 'O') {
        cout << "Congratulations! Player O wins!\n";
        exit(0);
    } else if (num[6] == 'O' && num[7] == 'O' && num[8] == 'O') {
        cout << "Congratulations! Player O wins!\n";
        exit(0);
    } else if (num[0] == 'O' && num[4] == 'O' && num[8] == 'O') {
        cout << "Congratulations! Player O wins!\n";
        exit(0);
    } else if (num[2] == 'O' && num[4] == 'O' && num[6] == 'O') {
        cout << "Congratulations! Player O wins!\n";
        exit(0);
    }
}