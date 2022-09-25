/*
Azizbek Shokosimov
Week5 Q3
Use Bubble Sort 
09/24/2022
csc121
*/

#include <iostream>
using namespace std;

void validator(string);                                                 // declare function validator
string getLetterGrade(double);                                          // declare function getLetterGrade
void bubbleSort(double[5]);                  

double scores[5]{};

int i{0};                                                               // declare int var i
double total{0}, avg{0};                                      // Declare the needed variables
string valid{};

int main() {                                                                        // maint function start
    for (i=0; i<5; i++) {                                                          // Runs code 5 times   
        cout << "Enter score " << i+1 << ": ";                                        // Output Enter score value of i
        cin >> scores[i];                                                               // Store user input
        valid = ( scores[i] < 0 || scores[i] > 100 || cin.fail()) ? "Invalid" : "Valid";    // condition for checking the validity of scores[i]
        cin.clear();                                                                // clear error state from bad input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');                        // prevent infinite loop
        validator(valid);                                                           // call validator function
        if ( valid == "Valid") {                                                    // Get total only if valid is Valid
            total += scores[i];                                                         // calculate total
        }
    }
    avg = total/5;                                                                  // Calculate average
    cout << "Your average is score: " << avg << endl;                               // Output in quotes
    cout << "Your letter grade is " << getLetterGrade(avg) << endl;                 // Output in quotes and call function getLetterGrade
    bubbleSort(scores);
}

void validator(string) {              
    if ( valid == "Invalid") {                                      // Check to see if score is between 0 and 100
        cout <<"\nScore outta range (1-100!)\n\n";                  // Output text in quotes
        i--;                                                        // force loop to rerun
    }
}

void bubbleSort(double scores[5]) {
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 4 ; j++){
            if (scores[j] < scores[j + 1]){
                swap(scores[j], scores[j + 1]);
            }
        }
    } 
    for (int i = 0; i < 5; i++){
        cout << scores[i] << endl;
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