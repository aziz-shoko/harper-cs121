#include <iostream> 
#include <cstdlib> 
#include <ctime>
#include <fstream>
using namespace std;

// https://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm
int main() {
    srand(time(0));
    ofstream output("fileou1.txt", ios::out);
    
    if (output.is_open()) {
        for (int i=0; i<10; i++) {
            output << rand()%100+1 << endl;
        }
        output.close();
    } else {
        cout << "Error! Cannot open file\n";
    }
}