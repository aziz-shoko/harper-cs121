#include <iostream>                                             // file headers
#include <vector>
#include "person.h"
#include "input.h"
using namespace std;

void Display(vector<Person*>& obj);                             // declare Display function with vector type for its parameter
void Search(vector<Person*>& obj, string);


int main() {
    vector<Person*> record;                                     // Create a vector to store class pointers (we will be storing instances of class inside this vector)
    int userInput = 0;

    while (userInput != 8) {
        // While loop to display the user option menus
        userInput = ReadValue<int>("\nRegister user menu: \n\n\t1. Laborer\n\t2. Manager \n\t3. Owner\n\t4. Display All\n\t5. Search for Person\n\t6. Remove Person"
        "\n\t7. Average Earned\n\t8. Quit\n\nChoose number option to register: ");
        
        if (userInput == 1) {                                   // choice one Laborer option
            record.push_back(new Laborer);                      // allocate Laborer class and store in vector person
            record[record.size()-1] -> Input();                 // address the last element class inside the vector person and call function Input()
        } else if (userInput == 2) {                            // the rest is the same thing but different options
            record.push_back(new Manager);
            record[record.size()-1] -> Input();
        } else if (userInput == 3) {
            record.push_back(new Owner);
            record[record.size()-1] -> Input();
        } else if (userInput == 4) {
            cout << endl;
            Display(record);                                    // call function display to display the elements of stored classes inside the vector person
        } else if (userInput == 5) {
            string userInput;
            cout << "Enter person's name for info: ";
            cin >> userInput;
            Search(record, userInput);
        }
          else if (userInput == 8) {
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

void Search(vector<Person*>& obj, string name) {
    int len = obj.size();
    for (int i = 0; i < len; i++) {
        if (obj[i]->GetName() == name) {
            obj[i]->Display(cout);
        } else {
            cout << "Name doesn't exist!";
        }
    }
}