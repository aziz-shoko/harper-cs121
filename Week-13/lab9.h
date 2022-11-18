#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define RESET       "\033[0m"              /* End Color */
class TTT {
    private: 
        string fileName;
        int totalWins;
        int totalLosses;
        int totalTies;

    public:
        string playerName;
        vector<int> recordHolder{0, 0, 0}, readVector{0, 0, 0};

        TTT (string a, int b, int c, int d) {
            fileName = a;
            totalWins = b;
            totalLosses = c;
            totalTies = d;
        }

    void recordFile();
    void display();
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

    cout << "\n\n\n\tWelcome to TTT! Please Enter Username: " << RESET;
    cin >> playerName;

    fileName = playerName + ".txt";
    fstream file (fileName, ios::app);
    for (int i : recordHolder) {
        file << i << " ";
    }
    file << "\n";
    file.close();
}

void TTT::display() {
    cout << "\nFinal Record of: " << playerName;
    cout << "\nWins: " << recordHolder[0];
    cout << "\nLosses: " << recordHolder[1];
    cout << "\nTies: " << recordHolder[2] << "\n\n";
}

void TTT::writeResults(char var) {
    if ( var == 'X' ) {
        recordHolder[0]++;
    } else if (var == 'O' ) {
        recordHolder[1]++;
    } else {
        recordHolder[2]++;
    }

    fstream file (fileName, ios::app);
    for (int i : recordHolder) {
        file << i << " ";
    }
    file << "\n";
    file.close();
}

void TTT::getResults() {
    string temp;
    fstream file (fileName, ios::in);
    string token;
    while (getline(file, temp)) {
        if (temp != " ") {
            stringstream ss(temp);
            int i = 0;
            string token;
            while (ss >> token) {
                readVector[i] = stoi(token);
                i++;
            }
            
        }
    }
    setTotalWins(readVector[0]);
    setTotalLosses(readVector[1]);
    setTotalTies(readVector[2]);

    cout << "\nWins: " << getTotalWins();
    cout << "\nLosses: " << getTotalLosses();
    cout << "\nTies: " << getTotalTies() << "\n\n";


    file .close();
}

void TTT::setTotalWins(int a) {
    totalWins = a;
}

void TTT::setTotalLosses(int a) {
    totalLosses = a;
}

void TTT::setTotalTies(int a) {
    totalTies = a;
}

int TTT::getTotalWins() {
    return totalWins;
}

int TTT::getTotalLosses() {
    return totalLosses;
}

int TTT::getTotalTies() {
    return totalTies;
}