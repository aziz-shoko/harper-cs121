#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int main() 
{
	srand(time(0));
	ofstream output;
	output.open("fileout3.dat",ios::out);

	if (output.is_open()) {
		for (int i=0; i<10; i++) {
			double num=static_cast<double>(rand()) / 10000.0;
			output.width(10);
			output.precision(3);
			output.setf(ios::fixed|ios::showpoint|ios::right);
			output << num << endl;
			if (output.fail()) {
				cerr << "Error! Cannot write to file!\n";
			}
		}
		output.close();
	}
	else {
		cerr << "Error! Cannot open file!\n";
	}


	return 0;
}