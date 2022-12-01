#include <iostream>
using namespace std;

template <class temp>
temp adderFunction(temp x, temp y) {return x+y;};

int main() {
    cout << adderFunction<int>(4, 6) << endl;
    cout << adderFunction<double>(1.4, 5.9) << endl;
    cout << adderFunction<string>("Hello ", "World") << endl;
}