#include <iostream>                                             // file headers
#include <vector>
#include "person.h"
#include "input.h"
using namespace std;

void Display(vector<Person*>& obj);                             // declare Display function with vector type for its parameter
void Remove(vector<Person*>& person, string name);


int main() {
    vector<Person*> record;                                     // Create a vector to store class pointers (we will be storing instances of class inside this vector)
    int userInput{0}, userInput2{0};

    while (userInput != 5) {
        // While loop to display the user option menus
        userInput = ReadValue<int>("\nRegister user menu: \n\n\t1. Add Person\n\t2. Display List \n\t3. Sort List\n\t4. Remove User \n\t5. Quit\n\nChoose number option to register: ");
        
        if (userInput == 1) {
            userInput2 = ReadValue<int>("Choose Type of Person to Add: \n\n\t1. Owner \n\t2. Manager \n\t3. Laborer\n\nChoose number option to register: ");
            if (userInput2 == 1) {                                   // choice one Laborer option
                record.push_back(new Laborer);                      // allocate Laborer class and store in vector person
                record[record.size()-1] -> Input();                 // address the last element class inside the vector person and call function Input()
            } else if (userInput2 == 2) {                            // the rest is the same thing but different options
                record.push_back(new Manager);
                record[record.size()-1] -> Input();
            } else if (userInput2 == 3) {
                record.push_back(new Owner);
                record[record.size()-1] -> Input();
            }     
        } else if (userInput == 2) {
            cout << endl;
            Display(record);
        } else if (userInput == 3) {
            cout << "N/A";
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

void Display(vector<Person*>& obj) {
    if (obj.empty()) {                                         // check to see if the list is not empty
        cout << "Warning! Empty List!" << endl;
    } else {
        int len = obj.size();                                  // get the length of the vector
        for (int i = 0; i < len; i++) {                        // for loop to display the elements of vector person
            obj[i]->Display(cout);                              // the -> symbol is simply calling the Display function (calling the function for pointers)
            cout << endl;
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