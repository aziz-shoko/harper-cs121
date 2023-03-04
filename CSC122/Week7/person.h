#include <string>
using namespace std;

#ifndef PERSON
#define PERSON

class Person {
    protected:
        string name;
        int socialSecurity;
        string birthDate;
    
    public:
        string type = "Person";
        Person();
        virtual void SetType()=0;
        virtual void Input()=0;
        virtual void SetName(string);
        virtual void SetSS(int);
        virtual void SetBirthdate(string);
        virtual void Display(ostream& out);

        virtual string GetName();
        virtual int GetSS();
        virtual string GetBirthdate();
};

class Laborer : public Person {
    private:
        string job;
        int ID;
        int payPerHour;
        int hours;

    public:
        Laborer();
        void Input();
        void SetType();
        void SetJob (string);
        void SetID(int);
        void SetPay(int);
        void SetHours(int);
        void Display(ostream& out);

        string GetJob();
        string GetType(); 
        int GetID();
        int GetPay();
        int GetHours(); 
};

class Manager : public Person {
    private: 
        string department;
        int ID;
        int salary;
    
    public: 
        Manager();
        void SetType();
        void SetDepartment(string);
        void SetID(int);
        void SetPay(int);
        void Display(ostream& out);

        string GetDepartment();
        string GetType();
        int GetID();
        int GetSalary();

};

class Owner : public Person {
    private: 
        double percentOwned;
        string ownershipDate;

    public: 
        Owner();
        void SetType();
        void SetOwned(double);
        void SetDate(string);
        void Display(ostream& out);

        string GetType();
        double GetOwned();
        string GetDateOwned();
};
#endif