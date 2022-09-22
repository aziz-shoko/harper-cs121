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

int main() {                                                            // maint function start
    for (i=1; i<=5; i++) {
        cout << "Enter score " << i << ": ";
        cin >> score;
        valid = ( score < 0 || score > 100 || cin.fail()) ? "Invalid" : "Valid";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        validator(valid);
        if ( valid == "Valid") {
            total += score;
        }
    }
    avg = total/5;
    cout << "Your average is score: " << avg << endl;
    cout << "Your letter grade is " << getLetterGrade(avg) << endl;
}

void validator(string) {              
    if ( valid == "Invalid") {                                     // Check to see if score is between 0 and 100
        cout <<"\nScore outta range (1-100!)\n\n";                  // Output text in quotes
        i--;
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