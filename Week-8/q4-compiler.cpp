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

int userInput{}, userInput2{};

vector<char> T1{' ', 'a', 'b', 'c' };
vector<char> T2{' '};
vector<char> T3{' '};

void board();
void sourceDestination(int *, int);
void mover(int, int);
void win();

int main() {
    cout << "\nTower of Hanoi\n";
    board();

    while (true) {
        sourceDestination(&userInput, 1);
        sourceDestination(&userInput2, 2);
        mover(userInput, userInput2);
        board();     
        win();   
    }

}

void sourceDestination(int *input, int i) {
    if ( i == 1 ) {
        cout << "\nEnter a source: ";
    } else {
        cout << "\nEnter a destination: ";
    }
    cin >> *input;
    if ( *input < 1 || *input > 3 || cin.fail() ) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nInvalid!";
        sourceDestination(input, i);
    }
}

void mover(int userInput, int userInput2) {
    if ( userInput == 1 && userInput2 == 2 && T1[T1.size()-1] > T2[T2.size()-1]) {
        T2.push_back(T1[T1.size()-1]);
        T1.pop_back();
    } else if ( userInput == 1 && userInput2 == 2 ) {
        cout << "Invalid! Must be alphabetical order!";
    }
    if ( userInput == 1 && userInput2 == 3 && T1[T1.size()-1] > T3[T3.size()-1]) {
        T3.push_back(T1[T1.size()-1]);
        T1.pop_back();
    } else if ( userInput == 1 && userInput2 == 3 ) {
        cout << "Invalid! Must be alphabetical order!";
    }
    if ( userInput == 2 && userInput2 == 1 && T2[T2.size()-1] > T1[T1.size()-1]) {
        T1.push_back(T2[T2.size()-1]);
        T2.pop_back();
    } else if ( userInput == 2 && userInput2 == 1 ) {
        cout << "Invalid! Must be alphabetical order!";
    }
    if ( userInput == 2 && userInput2 == 3 && T2[T2.size()-1] > T3[T3.size()-1]) {
        T3.push_back(T2[T2.size()-1]);
        T2.pop_back();
    } else if ( userInput == 2 && userInput2 == 3 ) {
        cout << "Invalid! Must be alphabetical order!";
    }
    if ( userInput == 3 && userInput2 == 1 && T3[T3.size()-1] > T1[T1.size()-1]) {
        T1.push_back(T3[T3.size()-1]);
        T3.pop_back();
    } else if ( userInput == 3 && userInput2 == 1 ) {
        cout << "Invalid! Must be alphabetical order!";
    }
    if ( userInput == 3 && userInput2 == 2 && T3[T3.size()-1] > T2[T2.size()-1]) {
        T2.push_back(T3[T3.size()-1]);
        T3.pop_back();
    } else if ( userInput == 3 && userInput2 == 2 ) {
        cout << "Invalid! Must be alphabetical order!";
    }
        
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

void win() {
    if ( T3.size() == 4 && T3[1] == 'a' && T3[2] == 'b' && T3[3] == 'c') {
        cout << "\nCongratulations!";
        exit(0);
    }
}