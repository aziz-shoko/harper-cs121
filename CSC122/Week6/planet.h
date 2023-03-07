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
#endif