#include <iostream>                                             // file headers
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "person.h"
#include "input.h"
using namespace std;

void Display(vector<Person*>& obj);                             // declare Display function with vector type for its parameter
void Search(vector<Person*>& obj, string);
void Fire(vector<Person*>& obj, string);
void Write(vector<Person*>& obj);
void ReadLaborer(vector<Person*>& obj);

int main() {
    vector<Person*> record;                                     // Create a vector to store class pointers (we will be storing instances of class inside this vector)
    int userInput = 0;

    ReadLaborer(record);


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
        } else if (userInput == 6) {
            string userInput;
            cout << "Enter persons's name to fire: ";
            cin >> userInput;
            Fire(record, userInput);
        } else if (userInput == 7) {
            cout << "\nWork In Progress\n";
        }
          else if (userInput == 8) {
            Write(record);
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

void Write(vector<Person*>& obj) {
    int len = obj.size();
    for (int i = 0; i < len; i++) {
        obj[i]->Write();
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

void Fire(vector<Person*>& obj, string name) {
    for (auto it = obj.begin(); it != obj.end();) {
        if ( (*it)->GetName() == name) {
            delete *it;
            obj.erase(it);
            cout << "\nFired: " << name << endl;
        } else {
            cout << "\nName not found" << endl;
            ++it;
        }
    }
}

void ReadLaborer(vector<Person*>& obj) {
    ifstream infile("Laborer.txt"); // Open the file "Laborer.txt" for reading
    if (infile.is_open()) {         // Check if the file is successfully opened
        string line;
        while (getline(infile, line)) {     // Read each line in the file
            Laborer* lab = new Laborer();   // Create a new Laborer object
            stringstream ss(line);          // Create a stringstream from the line
            string token;
            getline(ss, token, ':');        // Parse the "Name" field
            getline(ss, token);
            lab->SetName(token);
            getline(ss, token, ':');        // Parse the "SSN" field
            getline(ss, token);
            lab->SetSS(token);
            getline(ss, token, ':');        // Parse the "Birthdate" field
            getline(ss, token);
            lab->SetBirthdate(token);
            getline(ss, token, ':');        // Parse the "Job Type" field
            getline(ss, token);
            lab->SetType();
            getline(ss, token, ':');        // Parse the "Job Title" field
            getline(ss, token);
            lab->SetJob(token);
            getline(ss, token, ':');        // Parse the "ID" field
            getline(ss, token);
            lab->SetID(stoi(token));
            getline(ss, token, ':');        // Parse the "Hourly pay" field
            getline(ss, token, '$');
            lab->SetPay(stoi(token));
            getline(ss, token, ':');        // Parse the "Hours Worked" field
            getline(ss, token);
            lab->SetHours(stoi(token));
            obj.push_back(lab);             // Add the Laborer object to the record vector
        }
        infile.close();                 // Close the file
    } else {
        cout << "Unable to open file Laborer.txt" << endl;
    }
}


