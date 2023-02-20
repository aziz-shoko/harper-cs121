#include <iostream>
#include <string>
using namespace std;

class bookList {
    private:                                            // declare string arrays to hold the string elements, need copy to for resizing purposes and persisting data
        string* library;
        string* copyLibrary;
        size_t arrSize;

    public:                                             // class methods
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

bookList::bookList() {}                                 // default constructor

bookList::bookList(const bookList& copy) {              // copy constructor
    arrSize = copy.arrSize;
    library = new string[arrSize];
    for (int i = 0; i < arrSize; i++) {
        library[i] = copy.library[i];
    }

}

bookList::~bookList() {                                 // destructor
    Clear();
}

void bookList::Resize(size_t size) {                    // function for determining the size of the array, accepts the size as the parameter
    Clear();                                            // clear the library memory first
    library = new string[size];                         // allocate new memory for library and set its size to size
}

void bookList::Setter(string* x, size_t size) {         // setter function to set the values for the string library array
    arrSize = size;                                     // get the copy of size so we don't have to pass it in all the time
    for (int i = 0; i < size; i++) {
        library[i] = x[i];                              // for loop for copying the values of passed in string array into library variable
    }
}

string bookList::Getter() {                             // function for returning the string value of the elements inside the library array
    string holder = "\n\nList of Books: \n\n";          // holder holds the strings 
    for (int i = 0; i < arrSize; i++) {                 // then we simply concatenate all the string elements inside the library into one big string and return it
        holder += library[i] + "\n";
    }
   
   return holder;
}

void bookList::Clear() {                                // function for deallocating the library memory
    delete[] library;
    library = nullptr;
}

void bookList::Adder(string userBook) {                 // function for adding a one extra book to the list, accepts the book title parameter to add
    int newSize = arrSize + 1;                          // new size will be 1 bigger than the original one
    arrSize = arrSize + 1;                              // to also the change the value of the original arrSize 
    copyLibrary = new string[newSize];                  // allocate memory to the other array
    for (int i = 0; i < newSize; i++) {                 // copy the values of the library into the copyLibrary
        copyLibrary[i] = library[i];
    }
    copyLibrary[newSize-1] = userBook;                  // set the last element into the new book being added
    Resize(newSize);                                    // call resize function to resize library
    for (int i = 0; i < newSize; i++) {
        library[i] = copyLibrary[i];                    // copy the contents back to the original array of library from copyLibrary
    }
    delete[] copyLibrary;                               // deallocate the copy memory 
    copyLibrary = nullptr;
}

void bookList::Remover(string delBook) {                // function for removing the searched book by title, accepts book title as parameter
    int x{0}, y{0};                                     // declare two counters
    while (x < arrSize) {                               // loop over the entire elements inside the array
        if (library[x] == delBook) {                    // if a matching title is found, increase the x counter
            x++;
        } else {                                        // copy the values into different positions of x and y (
            library[y] = library[x];                    // this shifts the elements left when a matching string is found, meaning the matching string is replaces by the element to the right of it
            x++;
            y++;
        }
    }
    arrSize = y;                                        // set the new size to y so it doesn't count the last one (this prevents the element to the right from being showed twice)
}


ostream& operator<< (ostream& out, bookList& y) {       // operator overlaod for outputting the library contents, accepts the cout stream extractor parameter and the object for bookList
    out << y.Getter() << endl;                          // output the value of the getter function
    return out;                                         // return the string value
}   