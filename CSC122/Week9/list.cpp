#include<iostream>
#include<algorithm>
#include<vector>
#include "list.h"
using namespace std;

void List::SetName(vector<string> names) {
    listNames = names;
}

void List::SortName() {
    sort(listNames.begin(), listNames.end());
}

void List::Display() {
    for (int i = 0; i < listNames.size(); i++) {
        cout << listNames[i] << " ";
    }
}

string List::First() {
    sort(listNames.begin(), listNames.end());

    for (int i = 0; i < listNames.size(); i++) {
        first = listNames[0];
    }
    return first;
}

string List::Last() {
    sort(listNames.begin(), listNames.end());

    for (int i = 0; i < listNames.size(); i++) {
        last = listNames[listNames.size() - 1];
    }
    return last;
}