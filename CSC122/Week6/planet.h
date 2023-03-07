#include <iostream>
#include <iomanip>
#include <cmath> 
using namespace std;


#ifndef PLANET
#define PLANET
class Sphere {                                                      // first class Sphere
    private: 
        double radius;                                              // set radius as a private variable
    
    public: 
        Sphere();                                                   // Sphere methods
        void SetRadius(double);
        double SurfaceArea();
        double PlanetVolume();

    friend class Planet;                                            // Declare Planet class as a friend of Sphere (to access radius)
};

Sphere::Sphere() {
    radius = 0.0;
}

void Sphere::SetRadius(double r) {
    radius = r;
}

double Sphere::SurfaceArea() {
    return 4.0 * M_PI * pow(radius, 2);
}

double Sphere::PlanetVolume() {
    return (4.0/3.0) * M_PI * pow(radius, 3);
}


class Planet: public Sphere {                                       // Second class Planet which inherits the methods and variables of Sphere
    private: 
        double mass;                                                // Private variable mass

    public:                                                         // methods for Planet
        Planet();
        void SetMass(double);
        double Density();
        double Accelaration();
    
    friend ostream& operator<< (ostream&, Planet&);                 // declare the operator overload for cout << 
};  

Planet::Planet() {
    mass = 0.0;
}

void Planet::SetMass(double m) {
    mass = m;
}

double Planet::Density() {
    return mass / PlanetVolume();
}

double Planet::Accelaration() {
    const float G = 6.67 * pow(10, -11);
    return (G * mass) / pow(radius, 2);
}

ostream& operator<< (ostream& out, Planet& ball) {                                                  // output the calculated values and setw to format the output
    out << setw(37) << "Volume of Planet (m^3): " << ball.PlanetVolume() << endl;
    out << setw(37) << "Surface Area of Planet (m^2): " << ball.SurfaceArea() << endl;
    out << setw(37) << "Density of the Planet (kg/m^3): " << ball.Density() << endl;
    out << setw(37) << "Accelaration due to Gravity (m/s^2): " << ball.Accelaration() << endl;
    return out;
}
#endif