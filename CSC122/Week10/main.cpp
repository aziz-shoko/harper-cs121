#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;

void BubbleSort(vector<int>, int);
void InsertSort(vector<int>);
void Generator(int, vector<int>&);
void Display(vector<int>);

vector<int> hundred;
vector<int> thousand;
vector<int> fiveThousand;
vector<int> tenThousand;
vector<int> fiftyThousand;

int main() {
    int size = 0;
    Generator(100, hundred);
    Generator(1000, thousand);
    Generator(5000, fiveThousand);
    Generator(10000, tenThousand);
    Generator(50000, fiftyThousand);

    cout << "       Hundred Elements Size: " << hundred.size() << endl;
    cout << "      Thousand Elements Size: " << thousand.size() << endl;
    cout << " Five Thousand Elements Size: " << fiveThousand.size() << endl;
    cout << "  Ten Thousand Elements Size: " << tenThousand.size() << endl;
    cout << "Fifty Thousand Elements Size: " << fiftyThousand.size() << endl;

    // Sorting methods for hundred
    // Non-Recursive method sorting
    cout << "\nHundred";
    time_t start1 = time(0);
    InsertSort(hundred);
    time_t end1 = time(0);
    double elapsed1 = difftime(end1, start1);
    cout << "\nTime taken for Insert Method: " << elapsed1 << " seconds" << endl;

    // Recursive bubble sort
    size = hundred.size();
    time_t start2 = time(0);
    BubbleSort(hundred, size);
    time_t end2 = time(0);
    double elapsed2 = difftime(end2, start2);
    cout << "Time taken for Recursion Bubble Sort: " << elapsed2 << " seconds" << endl;

    // Non-Recursive method sorting
    cout << "\nThousand";
    time_t start3 = time(0);
    InsertSort(thousand);
    time_t end3 = time(0);
    double elapsed3 = difftime(end3, start3);
    cout << "\nTime taken for Insert Method: " << elapsed3 << " seconds" << endl;

    // Recursive bubble sort
    size = thousand.size();
    time_t start4 = time(0);
    BubbleSort(thousand, size);
    time_t end4 = time(0);
    double elapsed4 = difftime(end4, start4);
    cout << "Time taken for Recursion Bubble Sort: " << elapsed4 << " seconds" << endl;

    // Non-Recursive method sorting
    cout << "\nFive Thousand";
    time_t start5 = time(0);
    InsertSort(fiveThousand);
    time_t end5 = time(0);
    double elapsed5 = difftime(end5, start5);
    cout << "\nTime taken for Insert Method: " << elapsed5 << " seconds" << endl;

    // Recursive bubble sort
    size = fiveThousand.size();
    time_t start6 = time(0);
    BubbleSort(fiveThousand, size);
    time_t end6 = time(0);
    double elapsed6 = difftime(end6, start6);
    cout << "Time taken for Recursion Bubble Sort: " << elapsed6 << " seconds" << endl;

    // Non-Recursive method sorting
    cout << "\nTen Thousand";
    time_t start7 = time(0);
    InsertSort(tenThousand);
    time_t end7 = time(0);
    double elapsed7 = difftime(end7, start7);
    cout << "\nTime taken for Insert Method: " << elapsed7 << " seconds" << endl;

    // Recursive bubble sort
    size = tenThousand.size();
    time_t start8 = time(0);
    BubbleSort(tenThousand, size);
    time_t end8 = time(0);
    double elapsed8 = difftime(end8, start8);
    cout << "Time taken for Recursion Bubble Sort: " << elapsed8 << " seconds" << endl;

    // Non-Recursive method sorting
    cout << "\nFifty Thousand";
    time_t start9 = time(0);
    InsertSort(fiftyThousand);
    time_t end9 = time(0);
    double elapsed9 = difftime(end9, start9);
    cout << "\nTime taken for Insert Method: " << elapsed9 << " seconds" << endl;

    // Recursive bubble sort
    size = fiftyThousand.size();
    time_t start10 = time(0);
    BubbleSort(fiftyThousand, size);
    time_t end10 = time(0);
    double elapsed10 = difftime(end10, start10);
    cout << "Time taken for Recursion Bubble Sort: " << elapsed10 << " seconds" << endl;
}

void Generator(int num, vector<int>& alpha) {
    srand(time(NULL));

    for (int i = 0; i < num; i++) {
        int randNum = rand()% num + 1;
        alpha.push_back(randNum);
    }
}


void BubbleSort(vector<int> theta, int size) {
    if (size == 1) {
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        if (theta[i] > theta[i+1]) {
            swap(theta[i], theta[i+1]);
        }
    }
    BubbleSort(theta, size - 1);
}


void InsertSort(vector<int> delta) {
    int size = delta.size();
    int a, b;

    for (int i = 0; i < size; i++) {
        a = delta[i];
        b = i - 1;
        while (b >= 0 && delta[b] > a) {
            delta[b+1] = delta[b];
            b = b - 1;
        }
        delta[b+1] = a;
    }
}

void Display(vector<int> beta) {
    for (int i = 0; i < beta.size(); i++) {
        cout << beta[i] << " ";
    }
}