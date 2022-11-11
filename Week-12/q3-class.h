#include <iostream>                             // file headers
using namespace std;

class bmwData {                                 // class name publicData
    private:   
        string bmw{"xxxxxxx"};                  // private datas
        string release{"xxxxxxxxxxxxx"}; 

    public:
        void setter() {                         // function for setting values
            bmw = "BMW-2023";
            release = "February 1st, 2023";
        }
        void getter() {                        // function display, shows values of private data
            cout << "Cars 2023: " << bmw;
            cout << "\nRelease data: " << release << endl;
        } 
};