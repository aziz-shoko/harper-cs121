#include <iostream>
#include <string>
#include <fstream>
#include "person.h"
using namespace std;

Person::Person() {;}                                            // Person class accessor and mutator methods

void Person::SetName(string x) {
    name = x;
}

void Person::SetSS(string x) {
    socialSecurity = x;
}

void Person::SetBirthdate(string x) {
    birthDate = x;
}

string Person::GetName() {
    return name;
}

string Person::GetSS() {
    return socialSecurity;
}

string Person::GetBirthdate() {
    return birthDate;
}

Laborer::Laborer() {;}

void Laborer::SetJob(string x) {
    job = x;
}

void Laborer::SetID(int x) {
    ID = x;
}

void Laborer::SetPay(int x) {
    payPerHour = x;
}

void Laborer::SetHours(int x) {
    hours = x;
}

void Laborer::SetType() {
    type = "Laborer";
}

void Laborer::Display(ostream& out) {                           // display function
    out << "\n        Name: " << GetName() << endl;
    out << "         SSN: " << GetSS() << endl;
    out << "   Birthdate: " << GetBirthdate() << endl;
    out << "    Job Type: " << GetType() << endl;
    out << "   Job Title: " << GetJob() << endl;
    out << "          ID: " << GetID() << endl;
    out << "  Hourly pay: " << GetPay() << endl;
    out << "Hours Worked: " << GetHours() << endl;
}

void Laborer::Write() {
    ofstream file;
    file.open("Laborer.txt", ios_base::app);
    this->Display(file);
    file.close();
}

// void Laborer::Read() {
//     ifstream file("Laborer.txt"); // Open the file for reading
//     if (!file) {
//         cerr << "Error: could not open file." << endl;
//         return;
//     }

//     string line;
//     while (getline(file, line)) { // Read each line in the file
//         if (line.find("Name: ") == 0) {
//             SetName(line.substr(6)); // Set the name using the substring after "Name: "
//         } else if (line.find("SSN: ") == 0) {
//             SetSS(line.substr(5)); // Set the social security number using the substring after "SSN: "
//         } else if (line.find("Birthdate: ") == 0) {
//             SetBirthdate(line.substr(11)); // Set the birthdate using the substring after "Birthdate: "
//         } else if (line.find("Job Type: ") == 0) {
//             // Do nothing - this is a fixed value for the Laborer class
//         } else if (line.find("Job Title: ") == 0) {
//             SetJob(line.substr(11)); // Set the job title using the substring after "Job Title: "
//         } else if (line.find("ID: ") == 0) {
//             SetID(stoi(line.substr(4))); // Set the ID using the integer value after "ID: "
//         } else if (line.find("Hourly pay: $") == 0) {
//             SetPay(stoi(line.substr(13))); // Set the hourly pay using the integer value after "Hourly pay: $"
//         } else if (line.find("Hours Worked: ") == 0) {
//             SetHours(stoi(line.substr(14))); // Set the hours worked using the integer value after "Hours Worked: "
//         }
//     }

//     file.close(); // Close the file
// }

string Laborer::GetJob() {
    return job;
}

int Laborer::GetID() {
    return ID;
}

int Laborer::GetPay() {
    return payPerHour;
}

int Laborer::GetHours() {
    return hours;
}

string Laborer::GetType() {
    return type;
}

void Laborer::Input() {                                         // Input function to ask for user input and set the variables for laborer
    string input1, input2, input3, input4;
    int a, b, c, d;

        SetType();
        cout << "\nEnter Name: ";
        cin >> input1;
        SetName(input1);
        cout << "Enter SSN: ";
        cin  >> input4;
        SetSS(input4);
        cout << "Enter Birthdate: ";
        cin >> input2;
        SetBirthdate(input2);
        
        cout << "Assign Title: ";
        cin >> input3;
        SetJob(input3);
        cout << "Assign ID: ";
        cin >> b;
        SetID(b);
        cout << "Assign Hourly Pay: ";
        cin >> c;
        SetPay(c);
        cout << "Hours Worked: ";
        cin >> d;
        SetHours(d);
}


Manager::Manager() {;}

void Manager::SetDepartment(string x) {
    department = x;
}

void Manager::SetID(int x) {
    ID = x;
}

void Manager::SetPay(int x) {
    salary = x;
}

void Manager::SetType() {
    type = "Manager";
}

void Manager::Display(ostream& out) {                               // display method for Manager
    out << "\n      Name: " << GetName() << endl;
    out << "       SSN: " << GetSS() << endl;
    out << " Birthdate: " << GetBirthdate() << endl;
    out << "  Job Type: " << GetType() << endl;
    out << "Department: " << GetDepartment() << endl;
    out << "        ID: " << GetID() << endl;
    out << "    Salary: " << GetSalary() << endl;
}

void Manager::Write() {
    ofstream file;
    file.open("Manager.txt", ios_base::app);
    this->Display(file);
    file.close();
}

string Manager::GetDepartment() {
    return department;
}

string Manager::GetType() {
    return type;
}

int Manager::GetID() {
    return ID;
}

int Manager::GetSalary() {
    return salary;
}

void Manager::Input() {                                             // Input method for Manager
    string input1, input2, input3, input4;
    int a, b, c, d;

    SetType();
    cout << "\nEnter Name: ";
    cin >> input1;
    SetName(input1);
    cout << "Enter SSN: ";
    cin  >> input4;
    SetSS(input4);
    cout << "Enter Birthdate: ";
    cin >> input2;
    SetBirthdate(input2);

    cout << "Assign Department: ";
    cin >> input3;
    SetDepartment(input3);
    cout << "Assign ID: ";
    cin >> b;
    SetID(b);
    cout << "Assign Salary: ";
    cin >> c;
    SetPay(c);
}


Owner::Owner() {;}

void Owner::SetOwned(double x) {
    percentOwned = x;
}

void Owner::SetDate(string x) {
    ownershipDate = x;
}

void Owner::SetType() {
    type = "Owner";
}

void Owner::Display(ostream& out) {                             // Display method for owner
    out << "\n             Name: " << GetName() << endl;
    out << "              SSN: " << GetSS() << endl;
    out << "        Birthdate: " << GetBirthdate() << endl;
    out << "         Job Type: " << GetType() << endl;
    out << "    Percent Owned: " << GetOwned() << endl;
    out << "Date of Ownership: " << GetDateOwned() << endl;
}

void Owner::Write() {
    ofstream file;
    file.open("Owner.txt", ios_base::app);
    this->Display(file);
    file.close();
}

string Owner::GetType() {
    return type;
}

string Owner::GetDateOwned(){
    return ownershipDate;
}

double Owner::GetOwned() {
    return percentOwned;
}

void Owner::Input() {                                           // Input method for Owner
    string input1, input2, input3, input4;
    double c;

    SetType();
    cout << "\nEnter Name: ";
    cin >> input1;
    SetName(input1);
    cout << "Enter SSN: ";
    cin  >> input4;
    SetSS(input4);
    cout << "Enter Birthdate: ";
    cin >> input2;
    SetBirthdate(input2);

    cout << "Assign Percent of Ownership: ";
    cin >> c;
    SetOwned(c);
    cout << "Date of Ownership: ";
    cin >> input3;
    SetDate(input3);
}
