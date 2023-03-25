#include<vector>
using namespace std;
#ifndef PLANET
#define PLANET

class Planets {
    private: 
        vector<string> listPlanets;

    public: 
        void SetPlanets(vector<string>);
        void SortPlanets();
        void Display();
        void AddPlanets(string);
        void RemovePlanets(string);

};

#endif