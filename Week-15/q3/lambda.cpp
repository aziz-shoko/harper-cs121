#include <iostream>
#include <vector>
using namespace std;

void forEach (const vector<int>& values, void(*func)(int)) {
    for (int value : values) {
        func(value);
    }
}

int main() {
    vector<int> values = {1, 2, 3, 4, 5};
    forEach(values, [](int value) {cout << "Values: " << value << endl;});
}