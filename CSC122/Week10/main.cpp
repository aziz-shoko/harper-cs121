#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;

// declare functions
void BubbleSort(vector<int>&, int);
void InsertSort(vector<int>&);
void Generator(int, vector<int>&);
void Display(vector<int>);

// declare empty functions
vector<int> hundred;
vector<int> thousand;
vector<int> fiveThousand;
vector<int> tenThousand;
vector<int> fiftyThousand;

int main() {
    int size = 0;
    // Call Generator function to populate the vector is the specified number of elements
    Generator(100, hundred);
    Generator(1000, thousand);
    Generator(5000, fiveThousand);
    Generator(10000, tenThousand);
    Generator(50000, fiftyThousand);

    // Confirm the number of elements inside the vector
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

// Function for generating random int and addint into a vector
void Generator(int num, vector<int>& alpha) {
    srand(time(NULL));

    for (int i = 0; i < num; i++) {                     // loops around based on how many elements should be added
        int randNum = rand()% num + 1;                  // generates random number based on the given num range
        alpha.push_back(randNum);                       // add it into vector alpha
    }
}

// Recursion bubble sort function
void BubbleSort(vector<int>& theta, int size) {       
    if (size == 1) {                                    // condition for preventing the call of function indefinitely
        return;                                         // returns nothing
    }
    for (int i = 0; i < size - 1; i++) {                // for loop for iterating through the elements and swapping if previous is bigger than the next
        if (theta[i] > theta[i+1]) {
            swap(theta[i], theta[i+1]);
        }
    }
    BubbleSort(theta, size - 1);                       // call function again recursively with size - 1, this eventually reaches 1 and stops the recursion
}

// Sort with Insert Method
void InsertSort(vector<int>& delta) {                    // accepts a vector (pass by reference so the original is also manipulated)
    int size = delta.size();                             // figure out the size of the passed vector
    int a, b;                                            // declare some needed int vars

    for (int i = 0; i < size; i++) {                     // loop through the size of the vector
        a = delta[i];                                    // set placeholder a to the value of delta[i]
        b = i - 1;                                       // previous element position (left of the element)
        while (b >= 0 && delta[b] > a) {                 // condition for checking if value delta[b] is greater than a
            delta[b+1] = delta[b];                       // move the delta[b] to the next position
            b = b - 1;                                   // decrease b by 1 to check the previous element
        }
        delta[b+1] = a;                                  // set the next element to a
    }
}

// Simple display function for testing purposes
void Display(vector<int> beta) {
    for (int i = 0; i < beta.size(); i++) {
        cout << beta[i] << " ";
    }
}