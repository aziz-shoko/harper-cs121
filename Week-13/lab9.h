#include <iostream>                         // file headers
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define RESET       "\033[0m"              /* End Color */
class TTT {                                 // Class named TTT
    private:                                // Declare private datas
        string fileName;
        int totalWins;
        int totalLosses;
        int totalTies;

    public:                                                         // section for public datas and methods
        string playerName;                                          // public data name
        vector<int> recordHolder{0, 0, 0}, readVector{0, 0, 0};     // declare vector recordHolder

        TTT (string a, int b, int c, int d) {                       // Constructor to initialize values
            fileName = a;
            totalWins = b;
            totalLosses = c;
            totalTies = d;
        }

    void recordFile();                                              // declare all methods here (the setters and getters too)
    void writeResults(char);
    void getResults();
    void setTotalWins(int);
    int getTotalWins();
    void setTotalLosses(int);
    int getTotalLosses();
    void setTotalTies(int);
    int getTotalTies();
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

void TTT::getResults() {                                        // method for reading the data from file
    string temp;                                                // declare string temp
    fstream file (fileName, ios::in);                           // open player file
    string token;                                               // declare a string var token
    while (getline(file, temp)) {                               // condition for looping through lines
        if (temp != " ") {                                      // loops until last line
            stringstream ss(temp);                              // breakup the last obtained string into separate strings separated by spaces
            int i = 0;                                          // declare i for looping purposes
            string token;                                       // declare string to store the new split string
            while (ss >> token) {                               // while streaming into token
                readVector[i] = stoi(token);               // replace the readVector with new value (stoi converts string into int)
                i++;                                            // increment i by 1 for loopings purposes
            }
            
        }
    }
    setTotalWins(readVector[0]);                                // change the wins value based on the readVector token
    setTotalLosses(readVector[1]);                              // change the losses value
    setTotalTies(readVector[2]);                                // change the ties value

    cout << "\nWins: " << getTotalWins();                       // output the results
    cout << "\nLosses: " << getTotalLosses();
    cout << "\nTies: " << getTotalTies() << "\n\n";


    file .close();                                              // close file
}

void TTT::setTotalWins(int a) {                                 // method for setting totalWins private value 
    totalWins = a;
}

void TTT::setTotalLosses(int a) {                               // method for setting totalLosses private value
    totalLosses = a;
}

void TTT::setTotalTies(int a) {                                 // method for setting totalTies private value
    totalTies = a;
}

int TTT::getTotalWins() {                                       // getter method for seeing the totalWins
    return totalWins;
}

int TTT::getTotalLosses() {                                     // getter method for seeing the totalLosses
    return totalLosses;
}

int TTT::getTotalTies() {                                       // getter method for getting the totalTies
    return totalTies;
}