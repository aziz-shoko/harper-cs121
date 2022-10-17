/*
Azizbek Shokosimov
Week8 Q3
Rock, Paper, and Scissors game
10/15/2022
csc121
*/

// file headers
#include <iostream>
#include <vector>
using namespace std;

// necessary variables
int userInput{}, alpha{1}, randNum{}, userScore{0}, compScore{0};
string userChoice{}, compChoice{};
bool var{true};

// Declaring functions
void win(string, string);
void validator(int);
void userRecord();

// Declaring a variable
vector<int> userData{0, 0, 0};

int main() {
    while (userScore < 5 && compScore < 5) {
        cout << "Choose one of the three: \n\t1. Rock\n\t2. Paper \n\t3: Scissors\nEnter a number: ";                               // Output text in quotes
        cin >> userInput;                                                                                                           // Store user input in the var
        validator(userInput);                                                                                                       // call function validator
        string userChoice {(userInput == 1) ? "rock" : (userInput == 2) ? "paper" : (userInput == 3) ? "scissors" : "NULL"};        // set userChoice based on the ternary operator
        srand(time(0));                                                                                                             // clear mem for rand
        randNum = rand()%3+1;                                                                                                       // get rand from 1 to 3
        string compChoice {(randNum == 1) ? "rock" : (randNum == 2) ? "paper" : (randNum == 3) ? "scissors" : "NULL"};              // ternary condition for compChoice

        win(userChoice, compChoice);                                                                                                // call function win and pass on two var
    }

    if ( userScore == 5) {                                                                                                          // User win game condition
        cout << "\nYou won the game!";
        cout << "\nYour score: " << userScore;
        cout << "\nComputer Score: " << compScore << endl;
        userRecord();
    } else if ( compScore == 5 ) {                                                                                                  // Comp win game condition
        cout << "Computer won the game!";
        cout << "\nYour score: " << userScore;
        cout << "\nComputer Score: " << compScore << endl;
        userRecord();
    }
}

void win(string userChoice, string compChoice) {                                            // Condition for winning rounds
    if ( userChoice == compChoice) {                                                        // Condition for tie
        cout << "Its a tie!";                                                               
        userData[2]++;
    } else if ( userChoice == "rock" && compChoice == "paper") {                            // Condition for user rock and comp paper
        cout << "Computer wins this one!";  
        compScore++;                                                                        // raises score based on winner
        userData[1]++;                                                                      // stores the record in vector
    } else if ( userChoice == "rock" && compChoice == "scissors") {                         // the rest are the same but for different conditions
        cout << "You win this one!"; 
        userScore++;
        userData[0]++;
    } else if ( userChoice == "paper" && compChoice == "rock") {
        cout << "You win this one!"; 
        userScore++;
        userData[0]++;
    } else if ( userChoice == "paper" && compChoice == "scissors") {
        cout << "Computer wins this one!"; 
        compScore++;
        userData[1]++;
    } else if ( userChoice == "scissors" && compChoice == "rock") {
        cout << "Computer wins this one!"; 
        compScore++;
        userData[1]++;
    } else if ( userChoice == "scissors" && compChoice == "paper") {
        cout << "You win this one!"; 
        userScore++;
        userData[0]++;
    }
    cout << "\n";
}

void userRecord(){                                                          // vector for storing record
    cout << "\nYour Final Record: " << endl;
    cout << "Wins: " << userData[0] << endl;                                // the 0 index is for wins
    cout << "Losses: " << userData[1] << endl;                              // the 1 index is for losses
    cout << "Ties: " << userData[2] << endl;                                // the 2 index is for ties
    
}

void validator(int) {                           
    if ( userInput < 1 || userInput > 3 || cin.fail()) {                    // condition for making sure user Input is between 1 to 3
        cout << "Invalid!";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}