/*
Azizbek Shokosimov
Week8 Q4
Tower of Hanoi
10/16/2022
csc121
*/

#include <iostream>
#include <vector>
using namespace std;

int userInput{};

vector<char> T1{ ' ', 'a', 'b', 'c' };
vector<char> T2{' '};
vector<char> T3{' '};

void board();
void source();
void destination();
bool win();

int main() {
    cout << "\nTower of Hanoi\n";
    board();

    while (true) {
        source();
        destination();
        board();        
    }

}

void source() {
    cout << "Enter a source: ";
    cin >> userInput;

    if ()

}

void board() {
    cout << "\n\tT1: ";
    for (char i : T1) {
        cout << i << " ";
    }
    cout << "\n\tT2: ";
    for (char i : T2) {
        cout << i << " ";
    }
    cout << "\n\tT3: ";
    for (char i : T3) {
        cout << i << " ";
    }
}