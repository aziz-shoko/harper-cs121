/*
Azizbek Shokosimov
Week10 Q1
TTT track wins and losses in some file
10/29/2022
csc121
*/

#include <iostream>            // cout and cin library
#include <iomanip>             // setw library
#include <unistd.h>            // file header for usleep
#include <fstream>             // fstream file header
#include "q4-game.h"           // file header for the game mechanics of the TTT game 
using namespace std;           // avoid using std::

tttGame obj;                                                    // object create from q4-game.h file
                                          
int main() {
    myObj.recordFile();
    obj.title();                                                // call function title
    while (true) {
        obj.display('z');                                       // call function display and pass on var null (silences too few arguments error)
        obj.game();                                                 // call function game
    }
}


