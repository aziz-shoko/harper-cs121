/*
Azizbek Shokosimov
Week7 Q4
Number Palindrome
10/8/2022
csc121 
*/

#include <iostream>                                             // cin and cout file header
#include <unistd.h>                                             // file header for usleep
using namespace std;                                            // avoid using std::

int s{50};                                                      // Declare var s
int m{59};                                                      // Declare var m
int h{11};                                                      // Declare var h

int main() {
    while (true) {                                              // infinite loop
        cout << h << ":" << m << ":" << s << endl;              // output time
        usleep(1000000);                                        // sleeps for 1 second before increasing s by 1
        s++;                                                    // s = s+1
        if ( s==60) {                                           // if seconds reaches 60
            s = 0;                                              // go back to 0
            m++;                                                // and increase minute by 1
        }
        if ( m==60 ) {                                          // if minute reaches 60
            m = 0;                                              // go back to 0
            h++;                                                // and increase hour by 1
        } 
        if ( h==13) {                                           // if hours reaches 13
            h = 1;                                              // then hours goes back to 0
        }
    }
}
