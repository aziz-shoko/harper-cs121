/*
Azizbek Shokosimov
Week14
TTT track wins and losses in some file
11/20/2022
csc121
*/

#include <iostream>            // cout and cin library
#include <iomanip>             // setw library
#include <unistd.h>            // file header for usleep
#include <fstream>             // fstream file header
#include "game.h"           // file header for the game mechanics of the TTT game 
using namespace std;           // avoid using std::

tttGame obj;                                                    // object create from q4-game.h file
                                          
int main() {
    myObj.recordFile();                                         // call record file method to create the player file
    obj.title();                                                // call method title
    while (true) {                                              // infinite loop
        obj.display('z');                                       // call method display and pass on meaningless letter z
        obj.game();                                             // call call method game
    }
}


