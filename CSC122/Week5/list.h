#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class bookList {
    private: 
        string* library;

    public: 
        // https://www.geeksforgeeks.org/using-sizof-operator-with-array-paratmeters-in-c/
        bookList(string*, size_t);
        void getBookList(size_t);
        void Clear();
        ~bookList();

};

bookList::bookList(string* x, size_t arrSize) {
    library = new string[arrSize];
    for (int i = 0; i < arrSize; i++){
        library[i] = x[i];
    }
}

void bookList::getBookList(size_t arrSize){
    for (int i = 0; i < arrSize; i++) {
        cout << library[i] << endl;
    } 
}

void bookList::Clear() {
    delete[] library;
    library = NULL;
}

bookList::~bookList() {
    Clear();
}