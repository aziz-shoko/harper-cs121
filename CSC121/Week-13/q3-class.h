#include <iostream>                                     // display method
using namespace std;

class employee {                                        // create a class called employee
    private:                                            // private specifiar and declare private values
        double salary{100.00};
        int id{111};

    public:                                             // public specifier
        string name{"Dom"};

        void display() {                                // display method for displaying all the datas
            cout << "Name: " << getName();
            cout << "\nSalary: " << getSalary();
            cout << "\nID: " << getId();
        }

        void setSalaryNameID() {                        // setter method for setting the values of datas
            salary = 200.00;
            name = "Jeff";
            id = 123;
        }

        double getSalary() {                            // getter method for getting the salary
            return salary;
        }

        int getId() {                                   // getter method for getting the id
            return id;
        }

        string getName() {                              // getter method for getting the name variable
            return name;
        }
    
};