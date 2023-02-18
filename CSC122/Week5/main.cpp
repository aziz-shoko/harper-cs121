#include <iostream>
#include <string>
#include "list.h"
using namespace std;


int main() {
    string data[] = {"algebra", "geometry", "chemistry", "physics"};
    size_t arrSize = sizeof(data)/sizeof(data[0]);
    bookList obj(data, arrSize);

    obj.getBookList(arrSize);
    obj.~bookList();
}