#include <iostream>                         // file headers
using namespace std;

class publicData {                          // class name publicData
    private:   
        string bmw{"BMW-2023"};             // public data var carRelease

    public:
        string display() {                  // function display, returns the value of bmw
            return bmw;
        }
};