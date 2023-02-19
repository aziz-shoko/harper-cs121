/*
 * Header file for ReadValue
*/

#include <iostream>
#include <climits>
#include <string>

template<typename inputType>
inputType ReadValue(std::string prompt)
{
	inputType returnValue=0;
	std::cout << prompt;
	std::cin >> returnValue;
	while (std::cin.fail()) {
		std::cout << "Error! Cannot read input.\n";
		std::cin.clear();
		std::cin.ignore(INT_MAX,'\n');
		std::cout << prompt;
		std::cin >> returnValue;
	}
	return returnValue;
}