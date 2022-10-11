/*
Azizbek Shokosimov
Week7 Lab6
Do lab6 for fortune wheel
10/9/2022
csc121
*/

#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std; 

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

char guess();
bool match(char);
void phrasePicker(void);
void display(vector<char>);

char userInput{};
int alpha{0}, p1{}, p2{};

int main() {
    phrasePicker();
    display(phraseX);

    while (true) {
        char userGuess = guess();
        char t = match(userGuess);
        if ( t == false ) {
            cout << "No letters revealed!" << endl;
        }
        display(phraseX);
        alpha++;

        bool full = true;
        for ( char i: phraseX) {
            if ( i == 'x' ) {
                full = false;
            }
        }
        if ( full && p1 > p2 ) {
            cout << "Player 1 wins! With a score of " << p1 << " to " << p2 << endl;
            break;
        } else if ( full && p1 < p2 ) {
            cout << "Player 2 wins! With a score of " << p2 << " to " << p1 << endl;
            break;
        } else if ( full && p1 == p2 ) {
            cout << "Tie! With a scores of " << p1 << " and " << p2 << endl;
            break;
        }
    }
} 

char guess() {
    cout << "Player " << alpha%2+1 << " choose a letter: ";
    char x{};
    cin >> x;

    return x;
}

bool match(char userGuess) {
    int j = 0;
    bool match = false;
    for ( char k : phrase) {
        if ( userGuess == k && phraseX[j] == 'x') {
            if ( alpha%2+1 == 1 ) {
                p1++;
            } else {
                p2++;
            }
            match = true;
            phraseX[j] = userGuess;
        }
        j++;
    }
    if ( match ) {
        cout << "Match Found! " << endl;
    }
    return match;
}

void display(vector<char> phrase){
    for ( char i: phrase) {
        cout << i;
    }
    cout << "\nPlayer 1 score: " << p1;
    cout << "\nPlayer 2 score: " << p2;
    cout << "\n";
}

void phrasePicker() {
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