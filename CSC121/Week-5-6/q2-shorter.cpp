/*
Azizbek Shokosimov
Week 5 Q2
Use for looops to calculate grade
09/21/2022
csc121
*/

#include <iostream>                                                     // cin and cout file header
using namespace std;                                                    // avoid using std::

void validator(string);                                                 // declare function validator
string getLetterGrade(double);                                          // declare function getLetterGrade

int i{0};                                                               // declare int var i
double score{0}, total{0}, avg{0}; // Declare the needed variables
string valid{};

int main() {                                                                        // maint function start
    for (i=1; i<=5; i++) {                                                          // Runs code 5 times   
        cout << "Enter score " << i << ": ";                                        // Output Enter score value of i
        cin >> score;                                                               // Store user input
        valid = ( score < 0 || score > 100 || cin.fail()) ? "Invalid" : "Valid";    // condition for checking the validity of score
        cin.clear();                                                                // clear error state from bad input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');                        // prevent infinite loop
        validator(valid);                                                           // call validator function
        if ( valid == "Valid") {                                                    // Get total only if valid is Valid
            total += score;                                                         // calculate total
        }
    }
    avg = total/5;                                                                  // Calculate average
    cout << "Your average is score: " << avg << endl;                               // Output in quotes
    cout << "Your letter grade is " << getLetterGrade(avg) << endl;                 // Output in quotes and call function getLetterGrade
}

void validator(string) {              
    if ( valid == "Invalid") {                                      // Check to see if score is between 0 and 100
        cout <<"\nScore outta range (1-100!)\n\n";                  // Output text in quotes
        i--;                                                        // force loop to rerun
    }
}
string getLetterGrade(double){
  if (avg >= 90) {                                                      // Condition for letter grade A
    return "A";                                                         // Returns A
  } else if (avg >= 80) {                                               // Condition for letter grade B
    return "B";                                                         // Returns B
  } else if (avg >= 70) {                                               // Condition for letter grade C
    return "C";                                                         // Returns C
  } else if (avg >= 60) {                                               // Condition for letter grade D
    return "D";                                                         // Returns D
  } else {
    return "F";                                                         // returns F is all else fails
  }
}