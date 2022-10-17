/*
Azizbek Shokosimov
Week8 Q4
Tower of Hanoi
10/16/2022
csc121
*/

// file headers
#include <iostream>
#include <vector>
using namespace std;

// necessary variables
int userInput{}, userInput2{};

// necessary vectors
vector<char> T1{' ', 'a', 'b', 'c' };
vector<char> T2{' '};
vector<char> T3{' '};

// declaring functions
void board();
void sourceDestination(int *, int);
void mover(int, int);
void win();

int main() {
    cout << "\nTower of Hanoi\n";                       // output the text in quotes
    board();

    while (true) {                                      // infinite loop
        sourceDestination(&userInput, 1);               // Call sourceDestination function (this one for source)
        sourceDestination(&userInput2, 2);              // call sourceDestination function (this one for destination)
        mover(userInput, userInput2);                   // call mover function and pass on the userInput and userInput2
        board();                                        // call the board function
        win();                                          // call the win function
    }

}

void sourceDestination(int *input, int i) {             // input reference to userInput vars
    if ( i == 1 ) {                                     // if i == 1, then ask for source
        cout << "\nEnter a source: ";
    } else {
        cout << "\nEnter a destination: ";              // else if i == 2, then ask for destination
    }
    cin >> *input;                                      // store the user input in input
    if ( *input < 1 || *input > 3 || cin.fail() ) {     // check for garbage data
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nInvalid!";
        sourceDestination(input, i);                    // recall function if garbage data is entered
    }
}

void mover(int userInput, int userInput2) {                                             // pass on the values of userInputs
    if ( userInput == 1 && userInput2 == 2 && T1[T1.size()-1] > T2[T2.size()-1]) {      // condition for source 1 and destination 2 and making sure last for T1 is bigger that T2
        T2.push_back(T1[T1.size()-1]);                                                  // add the last element from T1 to T2
        T1.pop_back();                                                                  // remove the last element from T1
    } else if ( userInput == 1 && userInput2 == 2 ) {                                   // condition for if the order is out of place
        cout << "Invalid! Must be alphabetical order!";                                 // Output invalid
    }                                                                                   // the rest are the same but conditions for all other choices
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

void board() {                  // function for displaying all elements of each vector
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

void win() {                                                                    // win function
    if ( T3.size() == 4 && T3[1] == 'a' && T3[2] == 'b' && T3[3] == 'c') {      // if T3 == a b c
        cout << "\nCongratulations! You won!";                                  // then you win
        exit(0);                                                                // exit program
    }
}