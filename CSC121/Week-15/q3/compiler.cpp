/*
Azizbek Shokosimov
Week15 Q3
Add some new function to TTT (Added lambda function)
12/03/2022
csc121
*/

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


