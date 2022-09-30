/* 
Azizbek Shokosimov
lab4
We will build tic tac toe
09/17/2022
csc121
*/

#include <iostream>            // cout and cin library
#include <iomanip>             // setw library
#include <unistd.h>            // file header for usleep
using namespace std;           // avoid using std::

//the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
//visit this for more color codes: https://stackoverflow.com/questions/9158150/colored-output-in-c
#define RESET       "\033[0m"              /* End Color */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */

void title(void);                                               // Declare function title
void game(void);
void display(char);                                             // Declay function display

char num[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};   // Declare num and create array 1 - 9
char userNum{};                                                 // Declare userNum variable
int alpha{1};                                                   // Declare variable alpha
char beta{};                                                    // Declare variable beta
string userInput{};                                             // Declare variable userInput
char x{'a'}, y{'a'}; 

int main() {
    char null{};                                            // create emtpy char variable

    title();                                                // call function title
    display(null);                                          // call function display and pass on var null (silences too few arguments error)
    game();
}

void title(){
    cout << BOLDMAGENTA <<"\n\tName: Azizbek Shokosimov";                                           // Output Name in new line in magenta and tabbed format
    cout << "\n\tDate: 09/29/2022";                                                                 // Output Date in new line with tab
    cout << "\n\tLab: Week 5 Lab";                                                                  // Output Lab Number in new line with tab
    cout << "\n\tTitle: Tic Tac Toe Project";                                                       // Output Title in new line with tab
    cout << "\n\tObjective: Create a tic tac toe game" << RESET;                                   // Output Objective in new line with tab

    cout << BOLDGREEN <<"\n\n\n\n\t|---------|----------|---------|";                               // Chooses the green color for title and outputs a line 
    cout << "\n\t| Tic" << setw (10) << "| Tac" << setw(11) << "| Toe" << setw(6) << "|";   // Outputs Tic Tac Toe title 
    cout << "\n\t|---------|----------|---------|" << RESET;                                        // Outputs the last line
}

void game() {
    for (int i = 1; i > 0; i++ ) {                                          // Infinite loop
        if ( alpha%2 == 1) {                                                // checks if alpha modules 2 is equal to 1
            beta = 'X';                                                     // Sets beta value to char X
            cout << "Player " << beta <<" enter a number (1-9): ";                  // Ouput player x enter number
            cin >> userInput; 
        } else {
            beta = 'O';                                                     // Sets beta value to char O
            cout << "The Bot is thinking..." << endl;
            usleep(500000);                                                // sleeps for 1 second before increasing s by 1
            srand(time(0));
            userInput = to_string(rand() % 9 + 1);
        } 
        
        if (userInput.length() == 1 ) {                                         // Condition to see if user inputed 1 char 
            userNum = userInput[0];                                             // Set userNum to first char of userInput
        } else {
            userNum = '\0';                                                     // Set userNum value to null (learned from error message suggestion)
        }

        if ( userNum != '1' && userNum != '2' && userNum != '3' && userNum != '4' && userNum != '5' && userNum != '6' && userNum != '7' && userNum != '8' && userNum != '9' ) {
            cout << BOLDRED << "\nInvalid! Enter number 1 - 9: \n\n" << RESET;                          // Condition to see if user inputted number between 1 through 9
        } else {
            x=y;
            char X{ (userNum == num[0] && num[0] != 'O' && num[0] !='X') ?                              // Condition for player X choosing between 1 - 9
                num[0] = beta, x='b':                                                                          // Once the player chooses the square, the value cannot be changed if its O or X
                    (userNum == num[1] && num[1] != 'O' && num[1] !='X') ? 
                        num[1] = beta, x='b': 
                            (userNum == num[2] && num[2] != 'O' && num[2] !='X') ? 
                                num[2] = beta, x='b': 
                                    (userNum == num[3] && num[3] != 'O' && num[3] !='X') ? 
                                        num[3] = beta, x='b': 
                                            (userNum == num[4] && num[4] != 'O' && num[4] !='X') ? 
                                                num[4] = beta, x='b': 
                                                    (userNum == num[5] && num[5] != 'O' && num[5] !='X') ? 
                                                        num[5] = beta, x='b': 
                                                            (userNum == num[6] && num[6] != 'O' && num[6] !='X') ? 
                                                                num[6]= beta, x='b': 
                                                                    (userNum == num[7] && num[7] != 'O' && num[7] !='X') ? 
                                                                        num[7] = beta, x='b': 
                                                                            (userNum == num[8] && num[8] != 'O' && num[8] !='X') ? 
                                                                                num[8] = beta, x='b': '!'}; 
            if (x==y) {
                alpha--;                                                   // Decreases values of alpha by 1 so the program is forced to loop back to the current players turn 
                cout << BOLDRED << "\nCannot Override! Try again: ";       // and ask the player to Try again Try again: 
            }
            display(X);                                             // call function display and pass on var X    
            alpha++;                                                // Increase value of alpha by 1 
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
    } else if (num[0] != '1' && num[1] != '2' && num[2] != '3' && num[3] != '4' && num[4] != '5' && num[5] != '6' && num[6] != '7' && num[7] != '8' && num[8] != '9') {
        cout << BOLDYELLOW << "Its a Tie!" << endl;
        exit(0);
    }
}