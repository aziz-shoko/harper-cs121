/*
Azizbek Shokosimov
Week 5 Q2
Use for looops to calculate grade
09/21/2022
csc121
*/

#include <iostream>
using namespace std;

void grade(double, double, double, double, double);
double score1{}, score2{}, score3{}, score4{},score5{}, total{}, avg{};
string getLetterGrade(double);

int main() {

    grade(score1, score2, score3, score4, score5);
}

void grade(double, double, double, double, double) {
    for (int i = 0; i < 5; i++){
        cout << "Enter score number " << i+1 << ": "; 

        if ( i == 0 ) {
            cin >> score1;
            total +=score1;
        } else if ( i == 1 ) {
            cin >> score2;
            total +=score2;
        } else if ( i == 2) {
            cin >> score3;
            total +=score3;
        } else if ( i == 3 ) {
            cin >> score4;
            total +=score4;
        } else {
            cin >> score5;
            total +=score5;
        }
    }
    avg = total/5;
    cout << "Your average is: " << avg << endl;
    cout << "Your letter grade is: " << getLetterGrade(avg);
}

string getLetterGrade(double){
  if (avg >= 90) {
    return "A";
  } else if (avg >= 80) {
    return "B";
  } else if (avg >= 70) {
    return "C";
  } else if (avg >= 60) {
    return "D";
  } else {
    return "F";
  }
}