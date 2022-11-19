#include <iostream>                                             // file headers
using namespace std;                                            // namespace to avoid std:: 

class student {                                                 // declare class std
    private:                                                    // private specifier
        string name{"a"};                                       // private datas
        double gpa{0.1};

    public:                                                     // public specifier
        bool approval() {                                       // boolean method for gpa
            if (gpa >  3.0) {
                return true;
            } 
            return false;
        }
        void display() {                                        // display method for displaying the datas
            string status = (approval()) ? "Pass" : "Fail";     // ternary condition for pass of fail string
            cout << "\nName: " << getName();                    // output the private and public datas
            cout << "\nGPA: " << getGpa(); 
            cout << "\nStatus: " << status;
        }
        double getGpa() {                                       // getter getGpa
            return gpa;
        }
        void setGpa() {                                         // gpa setter
            gpa = 4.0;
        }

        string getName() {                                      // name getter
            return name;
        }

        void setName() {                                        // name setter
            name = "Azizbek";
        }
};

