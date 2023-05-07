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

void Laborer::SetID(string x) {
    ID = x;
}

void Laborer::SetPay(string x) {
    payPerHour = x;
}

void Laborer::SetHours(string x) {
    hours = x;
}

void Laborer::SetType() {
    type = "Laborer";
}

void Laborer::Display(ostream& out) {                           // display function
    out << "\nName:" << GetName() << endl;
    out << "SSN:" << GetSS() << endl;
    out << "Birthdate:" << GetBirthdate() << endl;
    out << "Job Type:" << GetType() << endl;
    out << "Job Title:" << GetJob() << endl;
    out << "ID:" << GetID() << endl;
    out << "Hourly pay:" << GetPay() << endl;
    out << "Hours Worked:" << GetHours() << endl;
}

void Laborer::Write() {                                         // simple write function for outputting the Display output into a file
    ofstream file;
    file.open("Laborer.txt", ios_base::app);
    this->Display(file);
    file.close();
}

string Laborer::GetJob() {
    return job;
}

string Laborer::GetID() {
    return ID;
}

string Laborer::GetPay() {
    return payPerHour;
}

string Laborer::GetHours() {
    return hours;
}

string Laborer::GetType() {
    return type;
}

void Laborer::Input() {                                         // Input function to ask for user input and set the variables for laborer
    string input1, input2, input3, input4;
    string a, b, c, d;

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

void Manager::SetID(string x) {
    ID = x;
}

void Manager::SetPay(string x) {
    salary = x;
}

void Manager::SetType() {
    type = "Manager";
}

void Manager::Display(ostream& out) {                               // display method for Manager
    out << "\nName:" << GetName() << endl;
    out << "SSN:" << GetSS() << endl;
    out << "Birthdate:" << GetBirthdate() << endl;
    out << "Job Type:" << GetType() << endl;
    out << "Department:" << GetDepartment() << endl;
    out << "ID:" << GetID() << endl;
    out << "Salary:" << GetSalary() << endl;
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

string Manager::GetID() {
    return ID;
}

string Manager::GetSalary() {
    return salary;
}

void Manager::Input() {                                             // Input method for Manager
    string input1, input2, input3, input4;
    string a, b, c, d;

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

void Owner::SetOwned(string x) {
    percentOwned = x;
}

void Owner::SetDate(string x) {
    ownershipDate = x;
}

void Owner::SetType() {
    type = "Owner";
}

void Owner::Display(ostream& out) {                             // Display method for owner
    out << "\nName:" << GetName() << endl;
    out << "SSN:" << GetSS() << endl;
    out << "Birthdate:" << GetBirthdate() << endl;
    out << "Job Type:" << GetType() << endl;
    out << "Percent Owned:" << GetOwned() << endl;
    out << "Date of Ownership:" << GetDateOwned() << endl;
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

string Owner::GetOwned() {
    return percentOwned;
}

void Owner::Input() {                                           // Input method for Owner
    string input1, input2, input3, input4;
    string c;

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
