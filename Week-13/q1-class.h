#include <iostream>
using namespace std;

class student {
    private:
        string name{"a"};
        double gpa{0.1};

    public:
        bool approval() {
            if (gpa >  3.0) {
                return true;
            } 
            return false;
        }
        void display() {
            string status = (approval()) ? "Pass" : "Fail";
            cout << "\nName: " << getName();
            cout << "\nGPA: " << getGpa(); 
            cout << "\nStatus: " << status;
        }
        double getGpa() {
            return gpa;
        }
        void setGpa() {
            gpa = 4.0;
        }

        string getName() {
            return name;
        }

        void setName() {
            name = "Azizbek";
        }
};

