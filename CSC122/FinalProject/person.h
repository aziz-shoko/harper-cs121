#include <string>
using namespace std;

#ifndef PERSON
#define PERSON

class Person {                                      // base class Person and its methods
    protected:
        string name;
        string socialSecurity;
        string birthDate;
    
    public:
        string type = "Person";
        Person();
        virtual ~Person() {};
        virtual void SetType()=0;
        virtual void Input()=0;
        virtual void Display(ostream& out)=0;
        virtual void Write()=0;
        // virtual void Read()=0;
        virtual void SetName(string);
        virtual void SetSS(string);
        virtual void SetBirthdate(string);

        virtual string GetName();
        virtual string GetSS();
        virtual string GetBirthdate();
};

class Laborer : public Person {                     // derived class Laborer and its methods
    private:
        string job;
        string ID;
        string payPerHour;
        string hours;

    public:
        Laborer();
        void Input();
        void SetType();
        void SetJob (string);
        void SetID(string);
        void SetPay(string);
        void SetHours(string);
        void Display(ostream& out);
        void Write();
        void Read();

        string GetJob();
        string GetType(); 
        string GetID();
        string GetPay();
        string GetHours(); 
};

class Manager : public Person {                     // derived class Manager and its methods
    private: 
        string department;
        string ID;
        string salary;
    
    public: 
        Manager();
        void Input();
        void SetType();
        void SetDepartment(string);
        void SetID(string);
        void SetPay(string);
        void Display(ostream& out);
        void Write();
        void Read();
        
        string GetDepartment();
        string GetType();
        string GetID();
        string GetSalary();

};

class Owner : public Person {                       // derived class Owner and its methods
    private: 
        double percentOwned;
        string ownershipDate;

    public: 
        Owner();
        void Input();
        void SetType();
        void SetOwned(double);
        void SetDate(string);
        void Display(ostream& out);
        void Write();
        void Read();

        string GetType();
        double GetOwned();
        string GetDateOwned();
};
#endif