/*
Azizbek Shokosimov
Week5 Q3
Use Bubble Sort 
09/24/2022
csc121
*/

#include <iostream>                                                     // file header for cin and cout
#include <string>                                                       // file header for string
using namespace std;                                                    // avoid using std::

void validator(string);                                                 // declare function validator
string getLetterGrade(double);                                          // declare function getLetterGrade
void bubbleSortScore(double[5]);                                        // declare function bubbleSortScore
void bubbleSortName(string);                                            // declare function bubbleSortName

int x{0};
double scores[5]{}, total{0}, avg{0};                                   // Declare variable scores with size 5 int elements and other vars
string name{}, valid{};                                                 // Declare string name with size 15 elements and other vars

int main() {                                                                                // maint function start
    for (x=0; x<5; x++) {                                                                   // Runs code 5 times   
        cout << "Enter score " << x+1 << ": ";                                              // Output Enter score value of i
        cin >> scores[x];                                                                   // Store user input
        valid = ( scores[x] < 0 || scores[x] > 100 || cin.fail()) ? "Invalid" : "Valid";    // condition for checking the validity of scores[i]
        cin.clear();                                                                        // clear error state from bad input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');                                // prevent infinite loop
        validator(valid);                                                                   // call validator function
        if ( valid == "Valid") {                                                            // Get total only if valid is Valid
            total += scores[x];                                                             // calculate total
        }
    }
    avg = total/5;                                                                  // Calculate average
    cout << "Your average is score: " << avg << endl;                               // Output in quotes
    cout << "Your letter grade is " << getLetterGrade(avg) << endl;                 // Output in quotes and call function getLetterGrade
    bubbleSortScore(scores);

    cout << "\nPlease enter you name: ";                                            // Ask user to enter name
    cin >> name;                                                                    // Store user input in name
    bubbleSortName(name);                                                           // Call function bubbleSortName
}

void validator(string) {              
    if ( valid == "Invalid") {                                      // Check to see if score is between 0 and 100
        cout <<"\nScore outta range (1-100!)\n\n";                  // Output text in quotes
        x--;                                                        // force loop to rerun
    }
}

void bubbleSortScore(double scores[5]) {                            // function bubbleSortScore
    for (int i = 0; i < 5; i++){                                    // Loops through five times
        for (int j = 0; j < 4 ; j++){                               // loops through four times
            if (scores[j] < scores[j + 1]){                         // if score in previous element in less than the next
                swap(scores[j], scores[j + 1]);              // then swap places using the swap function
            }
        }
    } 
    for (int i = 0; i < 5; i++){                                    // loops through five times
        cout << scores[i] << endl;                                  // output scores in order
    }
}

void bubbleSortName(string name) {                                  // function bubbleSortName
    int nameLength = name.length();                                 // finds name length
    for (int i = 0; i < 5; i++) {                                   // loops through five times
        for (int j = 0; j < nameLength; j++){                       // condition for the number of times to loop for j
            if (name[j] > name[j+1]) {                              // if char in element j is less than j+1,
                swap(name[j], name[j+1]);                    // then swap places using the swap function
            }
        }
    }
    for (int i = 0; i <= nameLength; i++){                          // Loop through number of name length
        cout << name[i] << " ";                                     // Output letters in order
    }
    cout << "\n";
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