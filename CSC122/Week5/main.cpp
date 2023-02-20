#include <iostream>
#include <string> 
#include "input.h"
#include "list.h"
using namespace std;

int main() {                        
    int userInput = 0;                                                          // declared variables
    string data[] = {"algebra", "geometry", "chemistry", "physics"};
    string userBook{};
    size_t size = sizeof(data)/sizeof(data[0]);                                 // https://www.geeksforgeeks.org/using-sizof-operator-with-array-paratmeters-in-c/
    bookList obj;

    obj.Resize(size);                                                           // resize the library array to the data array contents
    obj.Setter(data, size);                                                     // copy over the data values into library

    while(userInput != 4) {                                                     // while loop t display the menu and options
        cout << "\nHello, choose the following options: ";
        userInput = ReadValue<int>("\n\n\t1. Display Books List\n\t2. Add Book to List\n\t3. Remove Book from List \n\t4. Quit\n\nChoose Option: ");

        if (userInput == 1) {                                                   // first option is to display the contens of library
            cout << obj;                                                        // operator overlaod cout of an object
        } else if (userInput == 2) {                                            // second option adds a book the list
            cout << "\nEnter a book name to add: ";
            cin >> userBook;
            obj.Adder(userBook);
            cout << obj;
        } else if (userInput == 3) {                                            // third option removes the book from the list
            string delBook;
            cout << obj;
            cout << "\nEnter the exact book title to delete from list: ";
            cin >> delBook;
            obj.Remover(delBook);
            cout << obj;
        }
    }

    obj.Clear();                                                                // deallocate library memory
}