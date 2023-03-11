#include <iostream>                                             // file headers
#include <vector>
#include <algorithm>
#include "person.h"
#include "input.h"
using namespace std;

void Display(vector<Person*>&, int);                             // declare Display function with vector type for its parameter
void Remove(vector<Person*>&, string);
void Sort(vector<Person*>&);


int main() {
    vector<Person*> record;                                     // Create a vector to store class pointers (we will be storing instances of class inside this vector)
    int userInput{0}, userInput2{0}, userInput3{0};

    while (userInput != 5) {
        // While loop to display the user option menus
        userInput = ReadValue<int>("\nRegister user menu: \n\n\t1. Add Person\n\t2. Display List \n\t3. Sort List\n\t4. Remove User \n\t5. Quit\n\nChoose number option: ");
        
        if (userInput == 1) {
            userInput2 = ReadValue<int>("Choose Type of Person to Add: \n\n\t1. Owner \n\t2. Manager \n\t3. Laborer\n\nChoose number option to register: ");
            if (userInput2 == 1) {
                record.push_back(new Owner);
                record[record.size()-1] -> Input();
            } else if (userInput2 == 2) {
                record.push_back(new Manager);
                record[record.size()-1] -> Input();
            } else if (userInput2 == 3) {
                record.push_back(new Laborer);
                record[record.size()-1] -> Input();
            }     
        } else if (userInput == 2) {
            userInput3 = ReadValue<int>("Display Types: \n\n\t1. Display Owners \n\t2. Display Manager \n\t3. Display Laborers \n\t4. Display All\n\nChoose number option to display: ");
            cout << endl;
            Display(record, userInput3);
        } else if (userInput == 3) {
            Sort(record);
        } else if (userInput == 4) {
            string name;
            cout << "\nEnter Username to remove: ";
            cin >> name;
            Remove(record, name);
        } else if (userInput == 5) {
            cout << "\nExiting..." << endl; 
            break;
        }
    } 
}

void Display(vector<Person*>& obj, int userInput3) {
    for (auto it = obj.begin(); it != obj.end(); it++) {
        if (obj.empty()) {                                         // check to see if the list is not empty
            cout << "Warning! Empty List!" << endl;
        } else if (userInput3 == 1) {
            if ((*it)->GetType() == "Owner") {
                (*it)->Display(cout);
            }
        } else if (userInput3 == 2) {
            if ((*it)->GetType() == "Manager") {
                (*it)->Display(cout);
            }
        } else if (userInput3 == 3) {
            if ((*it)->GetType() == "Laborer") {
                (*it)->Display(cout);
            }
        } else if(userInput3 == 4) {
            (*it)->Display(cout);
        }
    }
}

void Remove(vector<Person*>& person, string name) {
    for (auto it = person.begin(); it != person.end();) {
        if ((*it)->GetName() == name) {
            it = person.erase(it);
            cout << "\nUser " << name << " is fired! " << endl;
        } else {
            it++;
        }
    }
}

void Sort(vector<Person*>& sortName) {
    vector<string> listNames;
    for (auto it = sortName.begin(); it != sortName.end();it++) {
        listNames.push_back((*it)->GetName());
    }
    sort(listNames.begin(), listNames.end());
    cout << "\nList of company names in alphabetical order: \n\n";
    for (auto it = listNames.begin(); it != listNames.end();it++) {
        cout << (*it) << endl;
    }
    cout << endl;
}