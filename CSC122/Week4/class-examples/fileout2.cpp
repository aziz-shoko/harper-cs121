#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

int main() 
{
	srand(time(0));
	std::ofstream output("fileout2.dat", std::ios::out);

	if (output.is_open()) {
		for (int i=0; i<10; i++) {
			output << rand()%100+1 << std::endl;
			if (output.fail()) {
				std::cerr << "Error! Cannot write to file!\n";
			}
		}
		output.close();
	}
	else {
		std::cerr << "Error! Cannot open file!\n";
	}


	return 0;
}