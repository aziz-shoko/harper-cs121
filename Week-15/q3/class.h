#include <iostream>                         // file headers
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>             // setw library
#include <unistd.h>            // file header for usleep
#include <fstream>             // fstream file header
using namespace std;

//the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
//visit this for more color codes: https://stackoverflow.com/questions/9158150/colored-output-in-c
#define RESET       "\033[0m"              /* End Color */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */

class TTT {                                 // Class named TTT
    private:                                // Declare private datas
        string fileName;
        int totalWins;
        int totalLosses;
        int totalTies;

    public:                                                         // section for public datas and methods
        string playerName;                                          // public data name
        vector<int> recordHolder{0, 0, 0};                          // declare vector recordHolder

        TTT (string a, int b, int c, int d) {                       // Constructor to initialize values
            fileName = a;
            totalWins = b;
            totalLosses = c;
            totalTies = d;
        }

        void recordFile();                                              // declare all methods here (the setters and getters too)
        void writeResults(char);
        void getResults();
};

void TTT::recordFile() {
    cout << BOLDGREEN <<"\n\n\n\n\t|---------|----------|---------|";                               // Chooses the green color for title and outputs a line 
    cout << "\n\t| Tic" << setw (10) << "| Tac" << setw(11) << "| Toe" << setw(6) << "|";           // Outputs Tic Tac Toe title 
    cout << "\n\t|---------|----------|---------|";                                                 // Outputs the last line

    cout << "\n\n\n\tWelcome to TTT! Please Enter Username: " << RESET;                             // output message in quotes
    cin >> playerName;                                                                              // store user name in playerName variable

    fileName = playerName + ".txt";                                                                 // filename will be users name with .txt extension
    fstream file (fileName, ios::app);                                                              // open and create file playerName.txt
    file.close();                                                                                   // close file
}

void TTT::writeResults(char var) {                              // method for writing results
    if ( var == 'X' ) {                                         // if player x wins
        recordHolder[0]++;                                      // then vector wins record increases by 1
    } else if (var == 'O' ) {                                   // if player O wins, then player's record of losses increase by one
        recordHolder[1]++;                                      
    } else {
        recordHolder[2]++;                                      // if none happen, then it is a tie and players tie increases by 1
    }

    fstream file (fileName, ios::app);                          // opens the player file and records the wins/losses/ties
    for (int i : recordHolder) {
        file << i << " ";
    }
    file << "\n";
    file.close();
}

void TTT::getResults() {                                         // method for reading the data from file
    cout << BOLDGREEN << "\nWins: " << recordHolder[0];          // output the results
    cout << "\nLosses: " << recordHolder[1];
    cout << "\nTies: " << recordHolder[2] << "\n\n" << RESET;
}