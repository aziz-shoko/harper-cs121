/*
Azizbek Shokosimov
Week 5 Q2
Use for looops to calculate grade
09/21/2022
csc121
*/

#include <iostream>                                                     // cin and cout file header
using namespace std;                                                    // avoid using std::

void grade(double, double, double, double, double);                     // declare function grade
string getLetterGrade(double);                                          // declare function getLetterGrade

double score1{}, score2{}, score3{}, score4{},score5{}, total{}, avg{}; // Declare the needed variables 

int main() {                                                            // maint function start

    grade(score1, score2, score3, score4, score5);                      // call grade function and pass on 5 variable parameters
}

void grade(double, double, double, double, double) {                    
    for (int i = 0; i < 5; i++){                                        // For loop condition for checking 5 times
        cout << "Enter score number " << i+1 << ": ";                   // Ask user to enter score number i+1, with each loop i is increased by 1

        

        if ( i == 0 ) {                                                 // condition for i == 0
            cin >> score1;                                              // store first user input in score1
            total +=score1;                                             // calculate total
        } else if ( i == 1 ) {                                          // condition for i == 1
            cin >> score2;                                              // store second user input in score2
            total +=score2;                                             // calculate total
        } else if ( i == 2) {                                           // condition for i == 2
            cin >> score3;                                              // store second user input in score3
            total +=score3;                                             // calculate total
        } else if ( i == 3 ) {                                          // condition for i == 3
            cin >> score4;                                              // store second user input in score4
            total +=score4;                                             // calculate total
        } else {
            cin >> score5;                                              // store second user input in score5
            total +=score5;                                             // calculate total
        }
    }
    avg = total/5;                                                      // calculate average
    cout << "Your average is: " << avg << endl;                         // Output average score
    cout << "Your letter grade is: " << getLetterGrade(avg) << endl;    // Output the letter grade
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