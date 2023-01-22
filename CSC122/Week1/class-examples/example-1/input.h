/*
 * Header file for ReadValue
*/

#include <iostream>
#include <climits>
#include <string>
using namespace std;

template<typename inputType>
inputType ReadValue(string prompt)
{
	inputType returnValue=0;
	cout << prompt;
	cin >> returnValue;
	while (cin.fail()) {
		cout << "Error! Cannot read input.\n";
		cin.clear();
		cin.ignore(INT_MAX,'\n');
		cout << prompt;
		cin >> returnValue;
	}
	return returnValue;
}


template<typename inputType>
inputType ReadValue(string prompt, inputType minValue)
{
	inputType returnValue=0;
	returnValue=ReadValue<inputType>(prompt);
	while (returnValue < minValue) {
		cout << "Error!  Value must be >= " << minValue << endl;
		returnValue=ReadValue<inputType>(prompt);
	}
	return returnValue;
}


template<typename inputType>
inputType ReadValue(string prompt, inputType minValue, inputType maxValue)
{
	inputType returnValue=0;
	returnValue=ReadValue<inputType>(prompt,minValue);
	while (returnValue > maxValue) {
		cout << "Error!  Value must be <= " << maxValue << endl;
		returnValue=ReadValue<inputType>(prompt,minValue);
	}
	return returnValue;
}