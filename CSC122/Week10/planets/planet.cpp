#include<iostream>
#include<string>
#include<algorithm>
#include "planet.h"
using namespace std;

void Planets::SetPlanets(vector<string> alpha) {
    listPlanets = alpha;
}

void Planets::SortPlanets() {
    int size = listPlanets.size();
    int b;
    string a;

    for (int i = 0; i < size; i++) {
        a = listPlanets[i];
        b = i - 1;
        while (b >= 0 && listPlanets[b] > a) {
            listPlanets[b+1] = listPlanets[b];
            b = b - 1;
        }
        listPlanets[b+1] = a;
    }
}

void Planets::Display() {
    for (int i = 0; i < listPlanets.size(); i++) {
        cout << listPlanets[i] << " ";
    }
}

void Planets::AddPlanets(string planet) {
    listPlanets.push_back(planet);
}

void Planets::RemovePlanets(string planet) {
    for (int i = 0; i < listPlanets.size(); i++) {
        if (listPlanets[i] == planet) {
            listPlanets.erase(remove(listPlanets.begin(), listPlanets.end(), planet));
        }
    }
}