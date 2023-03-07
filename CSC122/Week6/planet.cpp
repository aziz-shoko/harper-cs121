#include "planet.h"

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