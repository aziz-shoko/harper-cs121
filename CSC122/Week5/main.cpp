#include <iostream>
#include <string> 
#include "input.h"
using namespace std;

class bookList {
    private:
        string* library;
        string* copyLibrary;
        size_t arrSize;

    public: 
        bookList(); 
        bookList(const bookList&);
        ~bookList();
        void Resize(size_t);
        void Setter(string*, size_t);
        void Adder(string);
        void Remover(string);
        string Getter();
        void Clear();

};

bookList::bookList() {}

bookList::bookList(const bookList& x) {}

bookList::~bookList() {
    Clear();
}

void bookList::Resize(size_t size) {
    Clear();
    library = new string[size];
    size_t num = sizeof(*library)/sizeof(library[0]);
}

void bookList::Setter(string* x, size_t size) {
    arrSize = size;
    for (int i = 0; i < size; i++) {
        library[i] = x[i];
    }
}

string bookList::Getter() {
    string holder = "\n\nList of Books: \n\n";
    for (int i = 0; i < arrSize; i++) {
        holder += library[i] + "\n";
    }
   
   return holder;
}

void bookList::Clear() {
    delete[] library;
    library = nullptr;
}

void bookList::Adder(string userBook) {
    int newSize = arrSize + 1;
    arrSize = arrSize + 1;
    copyLibrary = new string[newSize];
    for (int i = 0; i < newSize; i++) {
        copyLibrary[i] = library[i];
    }
    copyLibrary[newSize-1] = userBook;
    Resize(newSize);
    for (int i = 0; i < newSize; i++) {
        library[i] = copyLibrary[i];
        cout << library[i] << endl;
    }
    delete[] copyLibrary;
    copyLibrary = nullptr;
}

void bookList::Remover(string bookTitle) {}


ostream& operator<< (ostream& out, bookList& y) {
    out << y.Getter() << endl;
    return out;
}

int main() {
    int userInput = 0;
    string data[] = {"algebra", "geometry", "chemistry", "physics"};
    string userBook;
    size_t size = sizeof(data)/sizeof(data[0]);
    bookList obj;

    obj.Resize(size);
    obj.Setter(data, size);

    while(userInput != 4) {
        cout << "\nHello, choose the following options: ";
        userInput = ReadValue<int>("\n\n\t1. Display Books List\n\t2. Add Book to List\n\t3. Remove Book from List \n\t4. Quit\n\nChoose Option: ");

        if (userInput == 1) {
            cout << obj;
        } else if (userInput == 2) {
            cout << "\nEnter a book name to add: ";
            cin >> userBook;
            obj.Adder(userBook);
            
        }
    }

    obj.Clear();
}