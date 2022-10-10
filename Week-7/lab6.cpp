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
vector<char> phrase_2x{ 'x','x','x','x','x','x','x','x',' ','x','x','x','x','x','x','x','x',' ','x','x','x','x' };

vector<char> phrase_3{ 'n','a','t','u','r','a','l',' ','a','r','t','i','s','a','n',' ','w','a','t','e','r' };
vector<char> phrase_3x{ 'x','x','x','x','x','x','x',' ','x','x','x','x','x','x','x',' ','x','x','x','x','x' };

vector<char> phrase_4{ 'n','a','t','u','r','a','l',' ','s','p','r','i','n','g',' ','w','a','t','e','r' };
vector<char> phrase_4x{ 'x','x','x','x','x','x','x',' ','x','x','x','x','x','x',' ','x','x','x','x','x' };

vector<char> phrase_5{ 'n','e','s','t','l','e',' ','p','u','r','e',' ','l','i','f','e' };
vector<char> phrase_5x{ 'x','x','x','x','x','x',' ','x','x','x','x',' ','x','x','x','x' };

vector<char> phrase{};
vector<char> phraseX{};

void phrasePicker(void);
void print(vector<char>);

int main() {
    phrasePicker();
    print(phrase);
    print(phraseX);
} 

void print(vector<char> p){
    for ( char i: p) {
        cout << i;
    }
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