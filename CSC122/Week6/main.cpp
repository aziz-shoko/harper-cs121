#include <iostream>
#include <cmath>
#include "planet.h"
using namespace std;

int main() {                                                    
    Planet instance1;                                                   // create object from the Planet class
    double userRadius, userMass;

    cout << "Enter the radius of the planet (Unit: Meters): ";          // get the radius from the user
    cin >> userRadius;
    instance1.SetRadius(userRadius);                                    // set the radius

    cout << "Enter the mass of the planet (Units: Kg): ";               // get the mass
    cin >> userMass;
    instance1.SetMass(userMass);                                        // set the mass

    cout << "\n\n";
    cout << instance1;                                                  // output the surface area, density and accelaration
}