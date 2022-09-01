/*
Azizbek Shokosimov
q3-compiler
Calculate base, height, hypotenuse, and theta
08/31/2022
csc121
*/

#include <iostream>         // Library for cout and cin
#include <cmath>            // Library for more math operations
using namespace std;        // Prevents us from using std::


//the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes
#define RESET   "\033[0m"                  // Stops the color
#define BOLDRED     "\033[1m\033[31m"      // Bold Red 


int main() {                                                
    double base{1};                                                 // Declares base
    double height{2};                                               // Declares Height
    double hypotenuse{3};                                           // Declares hypotenuse
    double beta{4};                                                 // Declares beta, angle between base and hypotenuse
    double betaDeg{5};                                              // Declares betaDeg, means theta in degrees
    double theta{6};                                                // Declares theta, angle around the unit circle

    cout << "\n\n\nPlease enter base followed by height: ";         // Outputs the text in quote
    cin >> base >> height;                                          // Stores user values in base and height variable
    
    if ( base >= 0 && height >= 0 ) {                                           // Checks the condition for quadrant 1

        hypotenuse = sqrt(pow(base, 2) + pow(height, 2));                       // Calculates the hypotenuse 
        cout << BOLDRED << "\nHypotenuse: " << hypotenuse << "\n\n";            // Outputs the hypotenuse answer in color Red
    
        beta = fabs(atan(height / base));                                       // Calculates beta in radians
        betaDeg = beta * (180 / M_PI );                                         // Converts beta to degrees
        cout << "Beta: " << betaDeg << " degrees\n";                            // Outputs beta answer

        theta = betaDeg;                                                        // Calculates theta, the angle around the unit circle staring at 0
        cout << "\ntheta: " << theta << " degrees" << RESET;                     // Outputs theta answer
        
    } else if (base < 0 && height >= 0) {                                       // Checks the condition for quadrant 2

        hypotenuse = sqrt(pow(base, 2) + pow(height, 2));                       // Calculates the hypotenuse 
        cout << BOLDRED << "\nHypotenuse: " << hypotenuse << "\n\n";            // Outputs the hypotenuse answer in color Red
    
        beta = fabs(atan(height / base));                                       // Calculates beta in radians
        betaDeg = beta * (180 / M_PI );                                         // Converts beta to degrees
        cout << "Beta: " << betaDeg << " degrees\n";                            // Outputs beta answer

        theta = 180 - betaDeg;                                                  // Calculates theta, the angle around the unit circle staring at 0
        cout << "\nTheta: " << theta << " degrees" << RESET;                    // Outputs theta answer

    } else if (base <= 0 && height <= 0) {                                      // Checks conditions for quadrant 3

        hypotenuse = sqrt(pow(base, 2) + pow(height, 2));                       // Calculates the hypotenuse 
        cout << BOLDRED << "\nHypotenuse: " << hypotenuse << "\n\n";            // Outputs the hypotenuse answer in color Red
    
        beta = fabs(atan(height / base));                                       // Calculates beta in radians
        betaDeg = beta * (180 / M_PI );                                         // Converts beta to degrees
        cout << "Beta: " << betaDeg << " degrees\n";                            // Outputs beta answer

        theta = 180 + betaDeg;                                                  // Calculates theta
        cout << "\nTheta: " << theta << " degrees" << RESET;                    // Outputs theta answer

    } else if (base > 0 && height < 0) {                                        // Condition for quadrant 4
        hypotenuse = sqrt(pow(base, 2) + pow(height, 2));                       // Calculates the hypotenuse 
        cout << BOLDRED << "\nHypotenuse: " << hypotenuse << "\n\n";            // Outputs the hypotenuse answer in color Red
    
        beta = fabs(atan(height / base));                                       // Calculates beta in radians
        betaDeg = beta * (180 / M_PI );                                         // Converts beta to degrees
        cout << "Beta: " << betaDeg << " degrees\n";                            // Outputs beta answer

        theta = 270 + betaDeg;                                                  // Calculates theta
        cout << "\nTheta: " << theta << " degrees" << RESET;                     // Outputs theta
    } 


    double Hypotenous{1};                                           // declare a new hypotenuse variable
    double Beta{2};                                                 // declare a new beta variable (angle between base and hypotenuse)
    double Base{4};                                                 // declare a new base variable
    double Height{5};                                               // declare a new height variable
    double betaRad{6};                                              // declare a theta in radians variable

    cout << "\n\n\nPlease enter the hypotenous: ";                  // Outputs the text in quotes
    cin >> Hypotenous;                                              // Stores the user input in Hypotenous variable
    cout << "\nPlease enter beta in degrees"                        // Outputs the text in quotes in a single line
    "(where theta is the angle between hypotenous and base): ";     
    cin >> Beta;                                                    // Stores user input for Theta

    betaRad = Beta * (M_PI/180);                                    // Converts Theta into Radians
    Base = Hypotenous * (cos(betaRad));                             // Calculates Base
    Height = Hypotenous * (sin(betaRad));                           // Calculates Height

    cout << BOLDRED << "\nBase: " << Base << "\n";                  // Outputs the Base answer in red
    cout <<"\nHeight: " << Height << "\n\n\n" << RESET;             // Outputs the Height answer in red
}