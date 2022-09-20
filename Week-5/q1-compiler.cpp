/*
Azizbek Shokosimov
Week5 Q1
We will use counters
09/19/2022
csc121
*/

#include <iostream> 
#include <string>
using namespace std;

void up(string);
void down(string);

int i{}, n{};
string userInput{};

int main() {
    cout << "Enter up or down: ";
    cin >> userInput;

    if ( userInput == "up") {
        up(userInput);
    } else if ( userInput == "down" ) {
        down(userInput);
    }

}

void down(string) {
    for ( i = 1; i <= 100; i++) {
        for ( n = 10; n%2 != 0 && n%3 != 0 && n%5 != 0 && n%7 != 0 && n%9 !=0; n++ ){
            continue
        }
        if ( i%2 != 0 && i%3 != 0 && i%5 != 0 && i%7 != 0 && i%9 !=0) {
            continue;
        }
        cout << i << endl;
    }
}

void up(string) {
    for ( i = 100; i >= 1; i-- ) {
        cout << i << endl;
    }

}