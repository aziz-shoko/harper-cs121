#include <iostream>
#include <vector>
#include "person.h"
#include "input.h"
using namespace std;

void Display(vector<Person*>& obj);


int main() {
    vector<Person*> record;
    int userInput = 0;

    while (userInput != 5) {
        userInput = ReadValue<int>("\nRegister user menu: \n\n\t1. Laborer\n\t2. Manager \n\t3. Owner\n\t4. Display\n\t5. Quit\n\nChoose number option to register: ");
        switch(userInput) {
            case 1: 
                record.push_back(new Laborer);
                record[record.size()-1] -> Input();
                break;
            case 2: 
                break;
            case 3: 
                break;
            case 4: 
                Display(record);
                break;
        }
    } 
}

void Display(vector<Person*>& obj) {
    if (obj.empty()) {
        cout << "Warning! Empty List!" << endl;
    } else {
        int len = obj.size();
        for (int i = 0; i < len; i++) {
            obj[i]->Display(cout);                      // the -> symbol is simply calling the Display function (calling the function for pointers)
            cout << endl;
        }
    }
}