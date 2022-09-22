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
void validator(string);                                                 // declare function validator
string getLetterGrade(double);                                          // declare function getLetterGrade

int i{0};                                                               // declare int var i
double score1{}, score2{}, score3{}, score4{},score5{}, total{}, avg{}; // Declare the needed variables
string valid1{}, valid2{}, valid3{}, valid4{}, valid5{};                // declare string var valid 1 to 5

int main() {                                                            // maint function start

    grade(score1, score2, score3, score4, score5);                      // call grade function and pass on 5 variable parameters
}

void grade(double, double, double, double, double) {                    
    for (i = 0; i < 5; i++){                                            // For loop condition for checking 5 times
        cout << "Enter score number " << i+1 << ": ";                   // Ask user to enter score number i+1, with each loop i is increased by 1
        

        if ( i == 0 ) {                                                                     // condition for i == 0
            cin >> score1;                                                                  // store first user input in score1                                                        // String
            valid1 = ( score1 < 0 || score1 > 100 || cin.fail()) ? "Invalid" : "Valid";     // validator, if score is Invalid, will return string Invalid 
            cin.clear();                                                                    // Gets rid of the error state messages
            cin.ignore(numeric_limits<streamsize>::max(), '\n');                     // Discard not needed chars
            validator(valid1);                                                              // call function validator and pass on var valid1
            total +=score1;                                                                 // calculate total
        } else if ( i == 1 ) {                                                              // The rest is the same thing but for the next 4 loops
            cin >> score2;                                              
            valid2 = ( score2 < 0 || score2 > 100 || cin.fail() ) ? "Invalid" : "Valid" ;     
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validator(valid2);
            total +=score2;                                             
        } else if ( i == 2) {                                           
            cin >> score3;                                            
            valid3 = ( score3 < 0 || score3 > 100 || cin.fail()) ? "Invalid" : "Valid";    
            validator(valid3);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            total +=score3;                                             
        } else if ( i == 3 ) {                                        
            cin >> score4;                                           
            string valid4 = ( score4 < 0 || score4 > 100 || cin.fail()) ? "Invalid" : "Valid";   
            validator(valid4);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            total +=score4;                                            
        } else {
            cin >> score5;                                              
            valid5 = ( score5 < 0 || score5 > 100 || cin.fail()) ? "Invalid" : "Valid";     
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validator(valid5);
            total +=score5;                                             
        }
    }
    avg = total/5;                                                      // calculate average
    cout << "Your average is: " << avg << endl;                         // Output average score
    cout << "Your letter grade is: " << getLetterGrade(avg) << endl;    // Output the letter grade
}

void validator(string) {              
        if ( valid1 == "Invalid") {                                     // Check to see if score is between 0 and 100
            cout <<"\nScore outta range (1-100!)\n\n";                  // Output text in quotes
            i--;
        } else if ( valid2 == "Invalid") {                              // Check to see if score is between 0 and 100
            cout <<"\nScore outta range (1-100!)\n\n";                  // Output text in quotes
            i--;
        } else if ( valid3 == "Invalid") {                              // Check to see if score is between 0 and 100
            cout <<"\nScore outta range (1-100!)\n\n";                  // Output text in quotes
            i--;
        } else if ( valid4 == "Invalid") {                              // Check to see if score is between 0 and 100
            cout <<"\nScore outta range (1-100!)\n\n";                  // Output text in quotes
            i--;
        } else if ( valid5 == "Invalid") {                              // Check to see if score is between 0 and 100
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