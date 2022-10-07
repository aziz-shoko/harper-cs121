/*
Azizbek Shokosimov
Week 7 Q2
Protect Data
10/06/2022
csc121
*/

#include <iostream>                                 // cin and cout fileheader
#include <vector>                                   // vector file header
using namespace std;                                // avoid using namespace std::

vector<char> list;                                  // declare char vector named list

int i{0}, j{0};                                     // declare int vars
string name1{}, name2{}, order{};                   // declare string vars
bool init{true};                                    // declare a bool named init

int main() {
    cout << "Enter first name: ";                   // output text in quotes
    cin >> name1;                                   // store user input in name1

    cout << "Enter second name: ";                  // output text in quotes
    cin >> name2;                                   // store user input name2

    cout << "Common Letters: ";                     // Output text in quotes
    while ( i < name1.length()) {                   // while loop runs as loon as its less than the length of name1
        init = true;                                // set init back to true
        j = 0;                                      // after looping, j is no longer 0 so we have to set it to 0
        for (int k=0; k < list.size(); k++) {       // for loop that runs based on how many elements in vector
            if (list[k] == name1[i]) {              // condition for if elements in list equals to letters in name1
                init = false;                       // set init to false
            }
        }
        if ( init ) {                               // condition for init bool
            while ( j < name2.length()) {           // while loop runs based on name2 length
                if (name1[i] == name2[j]) {         // if the elemens in name1 and name2 match, then run the following commands
                    list.push_back(name1[i]);       // adds the elements of name1[i] to the list vector
                    order += name1[i];              // combines the strings together 
                    cout << name1[i] << " ";        // outputs name1 letters with spaces in between
                    break;                          // exit loop
                }
                j++;                                // increment j by 1
            }
        }
        i++;                                        // increment i by 1
    }

    sort(order.begin(), order.end());               // sorts the chars in the string in order

    cout << endl << "Letters in order: " << order << endl;      // output text in quotes and the ordered string

}