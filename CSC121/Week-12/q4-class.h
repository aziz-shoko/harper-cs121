#include <iostream>                             // file headers
using namespace std;

class bmwData {                                 // class name publicData
    public:   
        string bmw;                             // declared datas
        string release; 

        bmwData(string x, string y) {           // declare constructor, constructor must have the same name as class
            bmw = x;
            release = y;
        }
};