/*
Azizbek Shokosimov
Week 5 Q5 
Spell name backwords and output vowels in name
09/26/2022
csc122
*/

#include <iostream>
using namespace std;

string name{};

int main() {
    cout << "Enter you name: ";
    cin >> name;
    transform(name.begin(), name.end(), name.begin(), ::tolower);

    cout << "Vowels: ";
    for (int i = 0; i < name.length(); i++ ){
        if (name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u'){
            cout << name[i] << " ";
        }
    }
    
    cout << "\nName backwards: ";
    for (int i = name.length()-1; i >= 0; i-- ){
        cout << name[i];
    }
    cout << "\n";
}

