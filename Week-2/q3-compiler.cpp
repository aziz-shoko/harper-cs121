/*
Azizbek Shokosimov
q3-compiler
Calculate base, height, hypotenuse, and theta
08/31/2022
csc121
*/

#include <iostream>         // Library for cout and cit
#include <cmath>            // Library for more math operations
using namespace std;        // Prevents us from using std::


//the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes
#define RESET   "\033[0m"                  // Stops the color
#define BOLDRED     "\033[1m\033[31m"      // Bold Red 


int main() {                                                
    double base{1};                                                 // Declare base
    double height{2};                                               // Declare Height
    double hypotenuse{3};                                           // Declare hypotenuse
    double theta{4};                                                // Declare theta
    double thetaDeg{5};                                             // Declare thetaDeg, means theta in degrees

    cout << "\n\n\nPlease enter base followed by height: ";         // Outputs the text in quote
    cin >> base >> height;                                          // Stores user values in base and height variable

    hypotenuse = sqrt(pow(base, 2) + pow(height, 2));               // Calculates the hypotenuse 
    cout << BOLDRED << "\nHypotenuse: " << hypotenuse << "\n\n";    // Outputs the hypotenuse answer in color Red

    theta = atan(height / base);                                    // Calculates theta in radians
    thetaDeg = theta * (180 / M_PI );                               // Converts theta to degrees
    cout << "Theta: " << thetaDeg << " degrees\n" << RESET;         // Outputs theta answer



    double Hypotenous{1};                                           // declare a new hypotenuse variable
    double Theta{2};                                                // declare a new theta variable
    double Base{4};                                                 // declare a new base variable
    double Height{5};                                               // declare a new height variable
    double thetaRad{6};                                             // declare a theta in radians variable

    cout << "\n\n\nPlease enter the hypotenous: ";                  // Outputs the text in quotes
    cin >> Hypotenous;                                              // Stores the user input in Hypotenous variable
    cout << "\nPlease enter theta in degrees"                       // Outputs the text in quotes in a single line
    "(where theta is the angle between hypotenous and base): ";     
    cin >> Theta;                                                   // Stores user input for Theta

    thetaRad = Theta * (M_PI/180);                                  // Converts Theta into Radians
    Base = Hypotenous * (cos(thetaRad));                            // Calculates Base
    Height = Hypotenous * (sin(thetaRad));                          // Calculates Height

    cout << BOLDRED << "\nBase: " << Base << "\n";                  // Outputs the Base answer in red
    cout <<"\nHeight: " << Height << "\n\n\n" << RESET;             // Outputs the Height answer in red
}