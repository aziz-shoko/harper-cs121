/*
Azizbek Shokosimov
Week7 Lab6
Do lab6 for fortune wheel
10/11/2022
csc121
*/

// Below are the file headers and which namespace being used
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std; 

//the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
#define RESET   "\033[0m"
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */

// Below is the phrases for the wheel of fortune
vector<char> phrase_1{ 'c','o','r','e',' ','h', 'y','d','r','a','t','i','o','n',' ','p','e','r','f','e','c','t','i','o','n' };
vector<char> phrase_1x{ 'x','x','x','x',' ','x','x','x','x','x','x','x','x','x',' ','x','x','x','x','x','x','x','x','x','x' };

vector<char> phrase_2{ 'k','i','r','k','l','a','n','d',' ','p','u','r','i','f','i','e','d',' ','w','a','t','e','r' };
vector<char> phrase_2x{ 'x','x','x','x','x','x','x','x',' ','x','x','x','x','x','x','x','x',' ','x','x','x','x','x' };

vector<char> phrase_3{ 'n','a','t','u','r','a','l',' ','a','r','t','i','s','a','n',' ','w','a','t','e','r' };
vector<char> phrase_3x{ 'x','x','x','x','x','x','x',' ','x','x','x','x','x','x','x',' ','x','x','x','x','x' };

vector<char> phrase_4{ 'n','a','t','u','r','a','l',' ','s','p','r','i','n','g',' ','w','a','t','e','r' };
vector<char> phrase_4x{ 'x','x','x','x','x','x','x',' ','x','x','x','x','x','x',' ','x','x','x','x','x' };

vector<char> phrase_5{ 'n','e','s','t','l','e',' ','p','u','r','e',' ','l','i','f','e' };
vector<char> phrase_5x{ 'x','x','x','x','x','x',' ','x','x','x','x',' ','x','x','x','x' };

vector<char> phrase{};
vector<char> phraseX{};

// Below are the declared functions
char guess();
bool match(char);
void phrasePicker(void);
void display(vector<char>);

// Bewlow are the declared variables
char userInput{};
int alpha{0}, p1{}, p2{};

int main() {                                                
    phrasePicker();                                                             // calls the functions phrasePicker and picks a random phrase
    display(phraseX);                                                           // Displays the Xs for the picjed phrase

    while (true) {                                                              // infinite loop
        char userGuess = guess();                                               // Gets the user input from the guess functions
        bool t = match(userGuess);                                              // passes the value of userGuess to the match function and returns true or false based on match function 
        if ( t == false ) {                                                     // if bool t is false
            cout << BOLDRED << "No letters revealed!" << RESET << endl;         // then output the text in quotes
        }
        display(phraseX);                                                       // display the new phrase with letters revealed
        alpha++;                                                                // increment alpha by 1 so that it switches to the other player

        bool full = true;                                                       // declare bool full to true
        for ( char i: phraseX) {                                                // go through all elements inside phraseX
            if ( i == 'x' ) {                                                   // if any equal to x
                full = false;                                                   // then set full false, this just means that wheel of fortune still has x left to be uncovered
            }
        }
        if ( full && p1 > p2 ) {                                                                     // win conditions for the wheel of fortune
            cout << BOLDGREEN << "Player 1 wins! With a score of " << p1 << " to " << p2 << endl;    // p1 is the score of player 1 and p2 is the score of player 2
            break;
        } else if ( full && p1 < p2 ) {
            cout << "Player 2 wins! With a score of " << p2 << " to " << p1 << endl;
            break;
        } else if ( full && p1 == p2 ) {
            cout << "Tie! With a scores of " << p1 << " and " << p2 << RESET << endl;
            break;
        }
    }
} 

char guess() {
    cout << "Player " << alpha%2+1 << " choose a letter: ";                         // Ask player to enter a letter, the alpha alternates between two players
    char x{};                                                                       // declare variable char
    string y{};                                                                     // declare string y
    cin >> y;                                                                       // store user input in string var y
    while ( y.length() != 1 ) {                                                     // if the string is greater than 1
        cout << BOLDRED << "\nInvalid! Enter one letter!: " << RESET << endl;       // then output Invalid
        cout << "Player " << alpha%2+1 << " choose a letter: ";                     // loop back  to the player
        cin >> y;                                                                   // store new user input
    } 
    x = y[0];                                                                       // Set first element of string to char x
    
    return x;                                                                       // return value of x
}

bool match(char userGuess) {
    int j = 0;                                                      // declare variable j
    bool match = false;                                             // declare bool match
    for ( char k : phrase) {                                        // for every element k in vector phrase
        if ( userGuess == k && phraseX[j] == 'x') {                 // condition for if userGuess matches the k values in phrase and the matched is still x
            if ( alpha%2+1 == 1 ) {                                 // if its player 1 guess
                p1++;                                               // then add the points to player 1
            } else {
                p2++;                                               // if player 2 then add player two scores
            }
            match = true;                                           // set match to true
            phraseX[j] = userGuess;                                 // replace the x with the value of userGuess
        }
        j++;                                                        // increment j by 1
    }
    if ( match ) {                                                  // if match == true
        cout << BOLDGREEN << "Match Found! " << RESET << endl;      // output match found
    }
    return match;                                                   // return value of match
}

void display(vector<char> phrase){                                  // display function
    for ( char i: phrase) {
        cout << BOLDCYAN << i << RESET;                             // for loop to display the elements of phrase
    }
    cout << "\nPlayer 1 score: " << p1;                             // output player 1 score
    cout << "\nPlayer 2 score: " << p2;                             // output player 2 score
    cout << "\n";
}

void phrasePicker() {                                               // function for randomly picking a phrase
    srand(time(0));
    int randNum = rand() % 5 + 1;
    if ( randNum == 1 ) {
        phrase = phrase_1;
        phraseX = phrase_1x;
    } else if ( randNum == 2 ) {
        phrase = phrase_2;
        phraseX = phrase_2x;
    } else if ( randNum == 3 ) {
        phrase = phrase_3;
        phraseX = phrase_3x;
    } else if ( randNum == 4 ) {
        phrase = phrase_4;
        phraseX = phrase_4x;
    } else if ( randNum == 5 ) {
        phrase = phrase_5;
        phraseX = phrase_5x;
    }
}