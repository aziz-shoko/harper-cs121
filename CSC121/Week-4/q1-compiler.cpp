/*
Azizbek Shokosimov
Week 4 Q1
Using if and else statements
09/013/2022
csc121
*/

#include <iostream>                         // Library for cout and cin
using namespace std;                        // avoid using std:: 


#define RESET   "\033[0m"                  /* End Color */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define GREEN   "\033[32m"                 /* Green */
#define YELLOW  "\033[33m"                 /* Yellow */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define RED     "\033[31m"                 /* Red */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */


void validator(double);                                             // Declare function validator
void grade(double);                                                 // Declare function grade

int main() {
    double score{};                                                 // Declare variable score

    cout << "\t\nPlease enter your score between 0 and 100: ";      // Output text in quotes
    cin >> score;                                                   // Store user input in score
    
    validator(score);                                               // Call function validator
    grade(score);                                                   // call function grade

}

void validator(double score) {              
    if ( score < 0 ) {                                                                  // Check to see if score is less than 100
        cout << BOLDRED << "\t\nPlease enter a valid score next time!\n\n" << RESET;    // Output text in quotes
        exit(0);                                                                        // Exit 
    } else if (score > 100 ) {                                                          // Check to see if score is more than 100
        cout << BOLDRED << "\t\nPlease enter a valid score next time!\n\n" << RESET;    // Output text in quotes
        exit(0);                                                                        // Exit
    }
}

void grade(double score) {                                                              
    if ( score >= 90 ) {                                                                // Check score for range 90 to 100
        cout << BOLDGREEN << "\t\nYour score is A! Congratulations!\n\n" << RESET;      // Output text in bold green
    } else if ( score >= 80 ) {                                                         // Check score for range 80 to 90
        cout << GREEN << "\t\nYour score is B!\n\n" << RESET;                           // Output text in green
    } else if ( score >= 70 ) {                                                         // Check score for range 70 to 80
        cout << YELLOW << "\t\nYour score is C!\n\n" << RESET;                          // Output text in yellow
    } else if ( score >= 60 ) {                                                         // Check score for range 60 to 70
        cout << BOLDYELLOW << "\t\nYour score is D!\n\n" << RESET;                      // Output text in bold tellow
    } else if ( score >= 0 ) {                                                          // Check score for range 0 to 60
        cout << BOLDRED << "\t\nYour score is F!\n\n" << RESET;                         // Output text in bold red
    }   
}