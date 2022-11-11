#include <iostream>                             // file headers
using namespace std;

class bmwData {                                 // class name publicData
    private:   
        string bmw{"BMW-2023"};                 // private datas
        string release{"February 1st, 2023"}; 

    public:
        void display() {                        // function display, shows values of private data
            cout << "Cars 2023: " << bmw;
            cout << "\nRelease data: " << release << endl;
        } 
};