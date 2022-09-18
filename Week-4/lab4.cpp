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
void validator(char);                                           // Declare function validator
void display(char);                                             // Declay function display

char num[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};   // Declare num and create array 1 - 9
char userNum{};                                                 // Declare userNum variable
int alpha{1};                                                   // Declare variable alpha
char beta{};                                                    // Declare variable beta
string theta{};                                                 // Declare variable theta

int main() {
    char null{};                                            // create emtpy char variable

    title();                                                // call function title
    display(null);                                          // call function display and pass on var null (silences too few arguments error)

    while ( 1==1 ) {                                                        // Infinite loop
        if ( alpha%2 == 1) {                                                // checks if alpha modules 2 is equal to 1
            beta = 'X';                                                     // Sets beta value to char X
        } else {
            beta = 'O';                                                     // Sets beta value to char O
        }


        cout << "Player " << beta <<" enter a number (1-9): ";              // Ouput player x enter number
        cin >> theta;                                                       // Store user input in theta
        
        if (theta.length() == 1 ) {                                         // Condition to see if user inputed 1 char 
            userNum = theta[0];                                             // Set userNum to first char of theta
        }

        if ( userNum != num[0] && userNum != num[1] && userNum != num[2] && userNum != num[3] && userNum != num[4] && userNum != num[5] && userNum != num[6] && userNum != num[7] && userNum != num[8] ) {
            cout << BOLDRED << "\nInvalid! Enter number 1 - 9: \n\n" << RESET;                          // Condition to see if user inputted number between 1 through 9
            continue;
        } else {

            char X{ (userNum == num[0] && num[0] != 'O' && num[0] !='X') ?                              // Condition for player X choosing between 1 - 9
                num[0] = beta:                                                                          // Once the player chooses the sqaure, the value cannot be changed if its O or X
                    (userNum == num[1] && num[1] != 'O' && num[1] !='X') ? 
                        num[1] = beta: 
                            (userNum == num[2] && num[2] != 'O' && num[2] !='X') ? 
                                num[2] = beta: 
                                    (userNum == num[3] && num[3] != 'O' && num[3] !='X') ? 
                                        num[3] = beta: 
                                            (userNum == num[4] && num[4] != 'O' && num[4] !='X') ? 
                                                num[4] = beta: 
                                                    (userNum == num[5] && num[5] != 'O' && num[5] !='X') ? 
                                                        num[5] = beta: 
                                                            (userNum == num[6] && num[6] != 'O' && num[6] !='X') ? 
                                                                num[6]= beta: 
                                                                    (userNum == num[7] && num[7] != 'O' && num[7] !='X') ? 
                                                                        num[7] = beta: 
                                                                            (userNum == num[8] && num[8] != 'O' && num[8] !='X') ? 
                                                                                num[8] = beta: '!'}; 


            validator(X);                                           // calls validator function so values can't be overrided 
            display(X);                                             // call function display and pass on var X    
            alpha++;                                                // Increase value of alpha by 1 
        }
    }
}

void title(){
    cout << BOLDMAGENTA <<"\n\tName: Azizbek Shokosimov";                                           // Output Name in new line in magenta and tabbed format
    cout << "\n\tDate: 09/17/2022";                                                                 // Output Date in new line with tab
    cout << "\n\tLab: Week 4 Lab";                                                                  // Output Lab Number in new line with tab
    cout << "\n\tTitle: Tic Tac Toe Project";                                                       // Output Title in new line with tab
    cout << "\n\tObjective: Create a tic tac toe board" << RESET;                                   // Output Objective in new line with tab

    cout << BOLDGREEN <<"\n\n\n\n\t|---------|----------|---------|";                               // Chooses the green color for title and outputs a line 
    cout << "\n\t| Tic" << setw (10) << "| Tac" << setw(11) << "| Toe" << setw(6) << "|";   // Outputs Tic Tac Toe title 
    cout << "\n\t|---------|----------|---------|" << RESET;                                        // Outputs the last line
}

void validator(char) {                                                     // function for making sure player doesn't override already set values
    if ( userNum == '1' ) {                                                // Checks to see if userNum == 1 
            if ( num[0] != beta ) {                                        // Checks to see if num[0] doesn't eqaul beta
                alpha--;                                                   // Decreases values of alpha by 1 so the program is forced to loop back to the current players turn 
                cout << BOLDRED << "\nCannot Override! Try again: ";       // and ask the player to Try again Try again: 
            }                                                              // This is for square one, the following under it is the same thing but for all other squares
        } else if ( userNum == '2' ) {
            if ( num[1] != beta ) {
                alpha--;
                cout << BOLDRED << "\nCannot Override! Try again: ";
            }
        } else if ( userNum == '3' ) {
            if ( num[2] != beta ) {
                alpha--;
                cout << BOLDRED << "\nCannot Override! Try again: ";
            }
        } else if ( userNum == '4' ) {
            if ( num[3] != beta ) {
                alpha--;
                cout << BOLDRED << "\nCannot Override! Try again: ";
            }
        } else if ( userNum == '5' ) {
            if ( num[4] != beta ) {
                alpha--;
                cout << BOLDRED << "\nCannot Override! Try again: ";
            }
        } else if ( userNum == '6' ) {
            if ( num[5] != beta ) {
                alpha--;
                cout << BOLDRED << "\nCannot Override! Try again: ";
            }
        } else if ( userNum == '7' ) {
            if ( num[6] != beta ) {
                alpha--;
                cout << BOLDRED << "\nCannot Override! Try again: ";
            }
        } else if ( userNum == '8' ) {
            if ( num[7] != beta ) {
                alpha--;
                cout << BOLDRED <<  "\nCannot Override! Try again: ";
            }
        } else if ( userNum == '9' ) {
            if ( num[8] != beta ) {
                alpha--;
                cout << BOLDRED << "\nCannot Override! Try again: ";
            }
        }
}

void display(char) {
    cout << BOLDRED << "\n\n\n\n\t" << num[0] << setw(10) << num[1] << setw(10) << num[2];                   // Outputs evenly spaced 1, 2, 3 in red
    cout << "\n\n\n\n\t" << num[3] << setw(10) << num[4] << setw(10) << num[5];                              // Outputs evenly spaced 4, 5, 6 in red
    cout << "\n\n\n\n\t" << num[6] << setw(10) << num[7] << setw(10) << num[8] << "\n\n" << RESET << endl;   // Outputs evenly spaced 7, 8, 9 in red

    if (num[0] == beta && num[1] == beta && num[2] == beta) {                       // Win condition for squares 1, 2, 3
        cout << BOLDGREEN << "Congratulations! Player " << beta << " wins!\n\n";
        exit(0);                                                        
    } else if (num[3] == beta && num[4] == beta && num[5] == beta) {                // Win condition for sqaures 2, 4, 6
        cout << BOLDGREEN << "Congratulations! Player " << beta << " wins!\n\n";;
        exit(0);
    } else if (num[6] == beta && num[7] == beta && num[8] == beta) {                // Win condition for squares 7, 8, 9
        cout << BOLDGREEN << "Congratulations! Player " << beta << " wins!\n\n";;
        exit(0);
    } else if (num[0] == beta && num[4] == beta && num[8] == beta) {                // Win condition for squares 1, 5, 9
        cout << BOLDGREEN << "Congratulations! Player " << beta << " wins!\n\n";;
        exit(0);
    } else if (num[2] == beta && num[4] == beta && num[6] == beta) {                // Win condition for squares 3, 5, 7
        cout << BOLDGREEN << "Congratulations! Player " << beta << " wins!\n\n";;
        exit(0);
    } else if (num[0] == beta && num[3] == beta && num[6] == beta) {                // Win condition for squares 1, 2, 7
        cout << BOLDGREEN << "Congratulations! Player " << beta << " wins!\n\n";;
        exit(0);
    } else if (num[1] == beta && num[4] == beta && num[7] == beta) {                // Win condition for squares 2, 4, 8
        cout << BOLDGREEN << "Congratulations! Player " << beta << " wins!\n\n";;
        exit(0);
    } else if (num[2] == beta && num[5] == beta && num[8] == beta) {                // Win condition for squares 3, 6, 9
        cout << BOLDGREEN << "Congratulations! Player " << beta << " wins!\n\n";;
        exit(0);
    }
}