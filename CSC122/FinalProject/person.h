#include <string>
using namespace std;

#ifndef PERSON
#define PERSON

class Person {                                      // base class Person and its methods
    protected:
        string name;
        string socialSecurity;
        string birthDate;
        string pay;
    
    public:
        string type = "Person";
        Person();
        virtual ~Person() {};
        virtual void SetType()=0;
        virtual void Input()=0;
        virtual void Display(ostream& out)=0;
        virtual void Write()=0;
        virtual void SetName(string);
        virtual void SetSS(string);
        virtual void SetBirthdate(string);

        virtual string GetName();
        virtual string GetSS();
        virtual string GetBirthdate();
        virtual string GetType();
        virtual string GetPay();
};

class Laborer : public Person {                     // derived class Laborer and its methods
    private:
        string job;
        string ID;
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
    
    public: 
        Manager();
        void Input();
        void SetType();
        void SetDepartment(string);
        void SetID(string);
        void SetPay(string);
        void Display(ostream& out);
        void Write();
        
        string GetDepartment();
        string GetType();
        string GetID();
        string GetPay();

};

class Owner : public Person {                       // derived class Owner and its methods
    private: 
        string percentOwned;
        string ownershipDate;

    public: 
        Owner();
        void Input();
        void SetType();
        void SetOwned(string);
        void SetDate(string);
        void SetPay(string);
        void Display(ostream& out);
        void Write();

        string GetType();
        string GetOwned();
        string GetDateOwned();
};
#endif