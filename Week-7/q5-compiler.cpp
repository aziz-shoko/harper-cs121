/*
Azizbek Shokosimov
Week7 Q5
Create 4 while loops for random number
10/9/2022
csc121
*/

#include <iostream> 
#include <random> 
#include<ctime>
using namespace std;

int i{0}, num{};

int main() {
    default_random_engine engine{ static_cast<unsigned int>(time(0)) };
    uniform_int_distribution<unsigned int> randNum{ 1, 1000 };
    cout << "\n\t" << randNum(engine) << endl;

    cout << "Random 1 to 100: ";
    while ( i < 20 ) {
        num = randNum(engine);
        if ( num > 0 && num <= 100) {
            cout << num << " ";
            i++;
        }
    }

    i = 0;
    cout << "\nRandom 1 to 12: ";
    while ( i < 20 ) {
        num = randNum(engine);
        if ( num > 0 && num <= 12) {
            cout << num << " ";
            i++;
        }
    }

    i = 0;
    cout << "\nRandom 1 to 6: ";
    while ( i < 20 ) {
        num = randNum(engine);
        if ( num > 0 && num <= 6) {
            cout << num << " ";
            i++;
        }
    }

    i = 0;
    cout << "\nRandom 1 to 4: ";
    while ( i < 20 ) {
        num = randNum(engine);
        if ( num > 0 && num <= 4) {
            cout << num << " ";
            i++;
        }
    }
    cout << "\n";
}
