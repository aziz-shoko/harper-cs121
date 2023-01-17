/*
Azizbek Shokosimov
Week 5 Q5 
Spell name backwords and output vowels in name
09/26/2022
csc122
*/

#include <iostream>                             // cout and cin file header
using namespace std;                            // avoid using std::

string name{};                                  // declare string var name

int main() {
    cout << "Enter you name: ";                                                                         // output text in quotes
    cin >> name;                                                                                        // store user input in name
    transform(name.begin(), name.end(), name.begin(), ::tolower);                                       // make user input to lowercase

    cout << "Vowels: ";                                                                                 // output text in quotes
    for (int i = 0; i < name.length(); i++ ){                                                           // loops around based on the length of name
        if (name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u'){    // condition for vowels
            cout << name[i] << " ";                                                                     // output the vowels
        }
    }
    
    cout << "\nName backwards: ";                                                                       // output text in quotes
    for (int i = name.length()-1; i >= 0; i-- ){                                                        // loop through the name backwords
        cout << name[i];                                                                                // output the name in backwords
    }   
    cout << "\n";                                                                                       // newline because linux bad and output a percent sign for no reason
}

