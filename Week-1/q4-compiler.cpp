/*
Azizbek Shokosimov
q3-compiler
Using setw and escape seq to manipulate WYSIWYG
08/26/2022
csc121
*/

//the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#include <iostream>                        // Global Library                             
#include <iomanip>                         // Library for setw
using namespace std;                       // Setting namespace to avoid std::

int main() {             
    cout << RED << "\n\tName: Azizbek Shokosimov" << RESET;                                         // Output Name in new line in red and tabbed format
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