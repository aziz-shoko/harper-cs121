/*
Azizbek Shokosimov
Week7 Q5
Create 4 while loops for random number
10/9/2022
csc121
*/

#include <iostream> 
#include <random> 
#include<ctime>
using namespace std;

void randGen(void);
 
int main()
{
 randGen();
}

void randGen(void) {
    default_random_engine engine{ static_cast<unsigned int>(time(0)) };
    uniform_int_distribution<unsigned int> randNum{ 1, 1000 };
    cout << "\n\t" << randNum(engine) << endl;
}