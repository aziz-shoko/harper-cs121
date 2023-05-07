#include <iostream>                                             // file headers
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "person.h"
#include "input.h"
using namespace std;

void Display(vector<Person*>&);                                 // declare Display function with vector type for its parameter
void Search(vector<Person*>&, string);
void Fire(vector<Person*>&, string);
void Write(vector<Person*>&);
void Average(vector<Person*>&);
void ReadLaborer(vector<Person*>&);
void ReadManager(vector<Person*>&);
void ReadOwner(vector<Person*>&);

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
            cout << "\nAverages\n";
            Average(record);
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

void Average(vector<Person*>& obj) {

}

void ReadLaborer(vector<Person*>& obj) {                        // Function for reading the values from the laborer.txt
    ifstream reader("Laborer.txt");                             // opens file Laborer.txt
    if (reader.is_open()) {                                     // condition for opening the file
        string data;                                            // string data for putting the read lines into the variable data  
        Laborer* worker = new Laborer();                        // allocating new instances for any loaded in worker

        while (getline(reader, data)) {                         // while statement for reading all the lines Laborer.txt
            if (data.empty()) {                                 // condition for checking to see if the line is empty (if the line is empty, it means that the data for one person might be complete)
                if (worker->GetName() != "") {                  // this checks to see if the previous created instance is populated with some name
                    obj.push_back(worker);                      // if it is populated, then it is pushed into the vector record (obj in this function)
                    worker = new Laborer();                     // once it is pushed, a new instance is created for the next person's data
                }
            } else {                                            // if the data is not an empty line, then the parsing the data starts
                stringstream ss(data);                          // use stringstreams to help with parsing data
                string key, value;                              // the data is stored in key - value pairs, so I decided to go use key value variable names here too
                getline(ss, key, ':');                          // anything before the : gets stored as a key in key
                getline(ss, value);                             // the rest is stored as a value in value
                
                if (key == "Name") {                            // conditions for checking to see if key matches Name
                    worker->SetName(value);                     // if it does match it, then call the methods for the temporary worker class and set the values for it (here it sets the Name)
                } else if (key == "SSN") {                      // the rest of the if conditions is doing the same thing but for other parameters
                    worker->SetSS(value);
                } else if (key == "Birthdate") {
                    worker->SetBirthdate(value);
                } else if (key == "Job Type") {
                    worker->SetType();
                } else if (key == "Job Title") {
                    worker->SetJob(value);
                } else if (key == "ID") {
                    worker->SetID(value);
                } else if (key == "Hourly pay") {
                    worker->SetPay(value);
                } else if (key == "Hours Worked") {
                    worker->SetHours(value);
                }
            }
        }
        
        if (worker->GetName() != "") {                          // condition to make sure the data populated worker gets pushed into the record vector (in this case its obj but passed in by reference under different name)
            obj.push_back(worker);
        } else {
            delete worker;                                      // cleanup the worker 
        }

        reader.close();
    } else {
        cout << "Unable to open file Laborer.txt" << endl;
    }
}                                                               // the rest of the functions below is the same thing as the one above except it is for the job type specific classes


void ReadManager(vector<Person*>& obj) {
    ifstream reader("Manager.txt");
    if (reader.is_open()) {
        string data;
        Manager* worker = new Manager();

        while (getline(reader, data)) {
            if (data.empty()) {
                if (worker->GetName() != "") {
                    obj.push_back(worker);
                    worker = new Manager();
                }
            } else {
                stringstream ss(data);
                string key, value;
                getline(ss, key, ':');
                getline(ss, value);
                
                if (key == "Name") {
                    worker->SetName(value);
                } else if (key == "SSN") {
                    worker->SetSS(value);
                } else if (key == "Birthdate") {
                    worker->SetBirthdate(value);
                } else if (key == "Job Type") {
                    worker->SetType();
                } else if (key == "Department") {
                    worker->SetDepartment(value);
                } else if (key == "ID") {
                    worker->SetID(value);
                } else if (key == "Salary") {
                    worker->SetPay(value);
                }
            }
        }
        
        if (worker->GetName() != "") {
            obj.push_back(worker);
        } else {
            delete worker;
        }

        reader.close();
    } else {
        cout << "Unable to open file Manager.txt" << endl;
    }
}

void ReadOwner(vector<Person*>& obj) {
    ifstream reader("Owner.txt");
    if (reader.is_open()) {
        string data;
        Owner* worker = new Owner();

        while (getline(reader, data)) {
            if (data.empty()) {
                if (worker->GetName() != "") {
                    obj.push_back(worker);
                    worker = new Owner();
                }
            } else {
                stringstream ss(data);
                string key, value;
                getline(ss, key, ':');
                getline(ss, value);
                
                if (key == "Name") {
                    worker->SetName(value);
                } else if (key == "SSN") {
                    worker->SetSS(value);
                } else if (key == "Birthdate") {
                    worker->SetBirthdate(value);
                } else if (key == "Job Type") {
                    worker->SetType();
                } else if (key == "Percent Owned") {
                    worker->SetOwned(value);
                } else if (key == "Date of Ownership") {
                    worker->SetDate(value);
                } 
            }
        }
        
        if (worker->GetName() != "") {
            obj.push_back(worker);
        } else {
            delete worker;
        }

        reader.close();
    } else {
        cout << "Unable to open file Owner.txt" << endl;
    }
}

