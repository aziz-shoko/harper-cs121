/*
Azizbek Shokosimov
q3-compiler
Using setw and escape seq to manipulate WYSIWYG
08/26/2022
csc121
*/

#include <iostream>                        // Global Library                             
#include <iomanip>                         // Library for setw
using namespace std;                       // Setting namespace to avoid std::

int main() {                                                                                        // Starting Function 
    cout << "\n\tName: Azizbek Shokosimov";                                                         // Output Name in new line and tabbed format
    cout << "\n\tDate: 08/26/2022";                                                                 // Output Date in new line with tab
    cout << "\n\tLab: Lab 1";                                                                       // Output Lab Number in new line with tab
    cout << "\n\tTitle: Discussion Board Q4";                                                       // Output Title in new line with tab
    cout << "\n\tObjective: Use setw(n) and escape sequences in our code";                          // Output Objective in new line with tab

    cout << "\n\n\n\tList of Commands" << setw(28) << "What they do\n";                             // Output List of Commands and What they do 16 characters apart and 3 spaces down
    cout << setw(15) << "\n\tEscape Sequences" << setw(102)                                         // Output Escape sequence and descrioption within the width set
    << "A character followed by forward slash. Allows you to have special meanings in your text" ;  
    cout << setw(20) << "\n\tsetw(n)" << setw(100)                                                  // Output setw(n) and description within the set width
    << "Stands for set width and it sets the character width for your outputed text\n";
    return 0;                                                                                       // Exit Function
}