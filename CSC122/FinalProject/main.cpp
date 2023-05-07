#include <iostream>                                             // file headers
#include <vector>
#include <string>
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
void ReadManager(vector<Person*>& obj);
void ReadOwner(vector<Person*>& obj);

int main() {
    vector<Person*> record;                                     // Create a vector to store class pointers (we will be storing instances of class inside this vector)
    int userInput = 0;

    ReadLaborer(record);
    ReadManager(record);
    ReadOwner(record);

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

void Write(vector<Person*>& obj) {                              // this write function is for iterating through the whole record vector and calling the Write() function for each instance
    int len = obj.size();
    for (int i = 0; i < len; i++) {
        obj[i]->Write();
    }
}
void Search(vector<Person*>& obj, string name) {                // this one also iterates throughout the whole vector and calls the display function if the GetName() matches the searched name
    int len = obj.size();
    for (int i = 0; i < len; i++) {
        if (obj[i]->GetName() == name) {
            obj[i]->Display(cout);
        }
    }
}

void Fire(vector<Person*>& obj, string name) {                  // works similarly to the search function (same idea) but I just use iterators to remove the instance from inside the vector
    for (auto it = obj.begin(); it != obj.end();) {
        if ( (*it)->GetName() == name) {
            delete *it;
            obj.erase(it);
            cout << "\nFired: " << name << endl;
        } else {
            ++it;
        }
    }
}

void ReadLaborer(vector<Person*>& obj) {                        // Have three read functions that read off of a file that is either a laborer, manager, or owner. There is one for each
    ifstream infile("Laborer.txt");                             // Opens the laborer.txt file
    if (infile.is_open()) {                                     // condition for making sure the file exists
        string line;                                            // create a placeholder string vale
        Laborer* lab = new Laborer();                           // create a temp instance to store the read info to and push it back to record vector
        while (getline(infile, line)) {                         // while loop for reading the lines from the file
            stringstream ss(line);                              // string stream for parsing purposes
            string field, value;                                // placeholder strings for the keys and values
            getline(ss, field, ':');                            // separate the key based on the : delimeter and store it in key
            getline(ss, value);                                 // store the rest in value                                     

            if (field == "Name") {                              // below are the conditions for setting the read values to the values of the laborer class instance
                lab->SetName(value);
            } else if (field == "SSN") {
                lab->SetSS(value);
            } else if (field == "Birthdate") {
                lab->SetBirthdate(value);
            } else if (field == "Job Type") {
                lab->SetType();
            } else if (field == "Job Title") {
                lab->SetJob(value);
            } else if (field == "ID") {
                lab->SetID(value);
            } else if (field == "Hourly pay") {
                lab->SetPay(value);
            } else if (field == "Hours Worked") {
                lab->SetHours(value);
            }
        }
        obj.push_back(lab);                                     // once the values are set, it is pushed back into the record vector
        infile.close();                                             // the other functions below are the same exact thing but for the other job specific types
    } else {
        cout << "Unable to open file Laborer.txt" << endl;
    }

    infile.close();
}

void ReadManager(vector<Person*>& obj) {        
    ifstream infile("Manager.txt"); 
    if (infile.is_open()) {
        string line;
        Manager* lab = new Manager();
        while (getline(infile, line)) {
            stringstream ss(line);
            string field, value;
            getline(ss, field, ':');
            getline(ss, value);

            if (field == "Name") {
                lab->SetName(value);
            } else if (field == "SSN") {
                lab->SetSS(value);
            } else if (field == "Birthdate") {
                lab->SetBirthdate(value);
            } else if (field == "Job Type") {
                lab->SetType();
            } else if (field == "Department") {
                lab->SetDepartment(value);
            } else if (field == "ID") {
                lab->SetID(value);
            } else if (field == "Salary") {
                lab->SetPay(value);
            }
        }
        obj.push_back(lab);
        infile.close();
    } else {
        cout << "Unable to open file Manager.txt" << endl;
    }

    infile.close();
}

void ReadOwner(vector<Person*>& obj) {
    ifstream infile("Owner.txt"); 
    if (infile.is_open()) {
        string line;
        Owner* lab = new Owner();
        while (getline(infile, line)) {
            stringstream ss(line);
            string field, value;
            getline(ss, field, ':');
            getline(ss, value);

            if (field == "Name") {
                lab->SetName(value);
            } else if (field == "SSN") {
                lab->SetSS(value);
            } else if (field == "Birthdate") {
                lab->SetBirthdate(value);
            } else if (field == "Job Type") {
                lab->SetType();
            } else if (field == "Percent Owned") {
                lab->SetOwned(value);
            } else if (field == "Date of Ownership") {
                lab->SetDate(value);
            } 
        }
        obj.push_back(lab);
        infile.close(); 
    } else {
        cout << "Unable to open file Owner.txt" << endl;
    }

    infile.close();
}

