#include <vector>
using namespace std;

#ifndef LIST
#define LIST

class List {
    private: 
        vector<string> listNames;
        string first, last;
    
    public: 
        void SetName(vector<string>);
        void SortName();
        void Display();

        string First();
        string Last();

};

#endif