#include <iostream> 
#include <vector>
#include "planet.h"
#include "input.h"
using namespace std;

int main() {
    Planets obj;
    vector<string> somePlanets = {"Jupiter", "Mercury", "Uranus"};
    int userInput{0};
    string userPlanet;

    obj.SetPlanets(somePlanets);
    
    while (userInput != 5) {
        userInput = ReadValue<int>("Choose a number: \n\n\t1. Add Planet\n\t2. Remove Planet\n\t3. Sort Planets\n\t4. Display Planets\n\t5. Quit\n\nChoose a number: ");

        if (userInput == 1) {
            cout << "\nEnter Planet Name to Add: ";
            cin >> userPlanet;
            obj.AddPlanets(userPlanet);
        } else if (userInput == 2) {
            cout << "\nEnter Planet Name to Remove: ";
            cin >> userPlanet;
            obj.RemovePlanets(userPlanet);
        } else if (userInput == 3) {
            obj.SortPlanets();
            cout << "\nSorted!! Go to Display to see it!\n\n";
        } else if (userInput == 4) {
            cout << endl;
            obj.Display();
            cout << endl << endl;
        } else if (userInput == 5) {
            break;
        }
    }
}