#include<iostream>
using namespace std;

void Resize(int*&, int);
void EvenCopier(int*&, int*, int);
void Display(int*, int*, int);

int main() {
    int userInput1;
    int* numList = nullptr;
    int* evenList = nullptr;

    cout << "Enter list size: ";
    cin >> userInput1;
    Resize(numList, userInput1);
    EvenCopier(evenList, numList, userInput1);
    Display(numList, evenList, userInput1);
    
    delete[] numList;
    numList = nullptr;

    delete[] evenList;
    evenList = nullptr;
}

void Resize(int*& x, int y) {
    int values{0};
    x = new int[y];

    for (int i = 0; i < y; i++) {
        cout << "Int Value to Add: ";
        cin >> values;
        x[i] = values;
    }

}

void EvenCopier(int*& i, int* j, int k) {
    int countEvens{0};

    // I dont understand why this countEvens part doesn't prevent the trailing 0s from being outputted in the array
    for (int t = 0; t < k; t++) {
        if (j[t]%2 == 0) {
            countEvens++;
        }
    }

    i = new int[countEvens];

    int b{0};
    for (int t = 0; t < k; t++) {
        if (j[t]%2 == 0) {
            i[b] = j[t];
            b++;
        }
    }
}

void Display (int* x, int* y, int z) {
    cout << "Original List: ";
    for (int i = 0; i < z; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
    cout << "Even List: ";
    for (int i = 0; i < z; i++) {
        if (y[i] != 0) {
            cout << y[i] << " ";
        }
    }
    cout << endl;
}