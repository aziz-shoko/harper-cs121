#include <iostream>
#include <string>
#include "person.h"
using namespace std;

Person::Person() {;}

void Person::SetName(string x) {
    name = x;
}

void Person::SetSS(int x) {
    socialSecurity = x;
}

void Person::SetBirthdate(string x) {
    birthDate = x;
}

string Person::GetName() {
    return name;
}

int Person::GetSS() {
    return socialSecurity;
}

string Person::GetBirthdate() {
    return birthDate;
}

void Person::Display(ostream& out) {
    out << "   \nName: " << GetName() << endl;
    out << "      SSN: " << GetSS() << endl;
    out << "Birthdate: " << GetBirthdate() << endl;
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

void Laborer::Display(ostream& out) {
    out << "    Job Type: " << GetType() << endl;
    out << "   Job Title: " << GetJob() << endl;
    out << "          ID: " << GetID() << endl;
    out << "  Hourly pay: " << GetPay() << endl;
    out << "Hours Worked: " << GetHours() << endl;
}

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

void Laborer::Input() {
    char x = 'e';
    string input1, input2, input3, input4;
    int a, b, c, d, e, f;
    
        SetType();
        cout << "\nEnter Name: ";
        cin >> input1;
        SetName(input1);
        cout << "Enter SSN: ";
        cin  >> a;
        SetSS(a);
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

void Manager::Display(ostream& out) {
    out << "  Job Type: " << GetType() << endl;
    out << "Department: " << GetDepartment() << endl;
    out << "        ID: " << GetID() << endl;
    out << "    Salary: " << GetSalary() << endl;
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

void Owner::Display(ostream& out) {
    out << "         Job Type: " << GetType() << endl;
    out << "    Percent Owned: " << GetOwned() << endl;
    out << "Date of Ownership: " << GetDateOwned() << endl;
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
