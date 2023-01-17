#include <iostream>                                                     // file header for cout and stream
#include <vector>                                                       // file header for using vectors
using namespace std;                                                    // setting namespace to std to avoid using std::

class fruit {                                                           // create class fruit
    private:                                                            // private specifier
        int numberOf{0};                                                // declare private value numberOf
        double price{};                                                 // declare private value of price

    public:
        string name {"a"};                                              // declare public values
        string color{"z"};
        vector<string> listFruits{"apple", "banana", "orange"};         // declare vector to hold the list of fruits
    
    fruit () {};                                                        // default constructor

    fruit(int a, double b, string c, string d) {                        // full set of constructors
        numberOf = a;
        price = b;
        name = c;
        color = d;
    }

    void display(int x) {                                               // display method
        cout << "Number of fruit; " << numberOf;                        // output the value of numberOf variable
        cout << "\nPrice: " << price;                                   // output the value of price variable
        cout << "\nName: " << name;                                     // output the value of name variable
        cout << "\nColor: " << color;                                   // output the value of color variable
        if (x == 1) {                                                   // condition for printing the values of vector listFruits
            cout << "\nList of Fruits: ";
            for (string i : listFruits) {
                cout << i << " ";
            }
        }
    } 

    void setFruitColor() {                                              // set method for setting the fruit color and name
        name = "apple";
        color = "red";
    }

    string getFruitName() {                                             // getter method for getting the name variable
        return name;    
    }

    string getFruitColor() {                                            // getter methjod for geting the color variable
        return color;
    }

    void setNumberPrice() {                                             // setter method for setting the numberOf and price of Fruit
        numberOf = listFruits.size();
        price = 20;
    }

    int getNumber() {                                                   // getter method getting the value of numberOf
        return numberOf;
    }

    double getPrice() {                                                 // getter method for getting the vlaues of price
        return price;
    }
};