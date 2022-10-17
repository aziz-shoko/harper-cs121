/*
Azizbek Shokosimov
Week8 Q3
Rock, Paper, and Scissors game
10/15/2022
csc121
*/

#include <iostream>
#include <vector>
using namespace std;

int userInput{}, alpha{1}, randNum{}, userScore{0}, compScore{0};
string userChoice{}, compChoice{};
bool var{true};

void win(string, string);
void validator(int);
void userRecord();

vector<int> userData{0, 0, 0};

int main() {
    while (userScore < 5 && compScore < 5) {
        cout << "Choose one of the three: \n\t1. Rock\n\t2. Paper \n\t3: Scissors\nEnter a number: ";
        cin >> userInput;
        validator(userInput);
        string userChoice {(userInput == 1) ? "rock" : (userInput == 2) ? "paper" : (userInput == 3) ? "scissors" : "NULL"};
        srand(time(0));
        randNum = rand()%3+1;
        string compChoice {(randNum == 1) ? "rock" : (randNum == 2) ? "paper" : (randNum == 3) ? "scissors" : "NULL"};

        win(userChoice, compChoice);
    }

    if ( userScore == 5) {
        cout << "\nYou won the game!";
        cout << "\nYour score: " << userScore;
        cout << "\nComputer Score: " << compScore << endl;
        userRecord();
    } else if ( compScore == 5 ) {
        cout << "Computer won the game!";
        cout << "\nYour score: " << userScore;
        cout << "\nComputer Score: " << compScore << endl;
        userRecord();
    }
}

void win(string userChoice, string compChoice) {
    if ( userChoice == compChoice) {
        cout << "Its a tie!";
        userData[2]++;
    } else if ( userChoice == "rock" && compChoice == "paper") {
        cout << "Computer wins this one!"; 
        compScore++;
        userData[1]++;
    } else if ( userChoice == "rock" && compChoice == "scissors") {
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

void userRecord(){  
    cout << "\nYour Final Record: " << endl;
    cout << "Wins: " << userData[0] << endl;
    cout << "Losses: " << userData[1] << endl;
    cout << "Ties: " << userData[2] << endl;
    
}

void validator(int) {
    if ( userInput < 1 || userInput > 3 || cin.fail()) {
        cout << "Invalid!";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}