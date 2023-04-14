#include <iostream>
#include <deque>
#include "input.h"

using namespace std;

int main()
{
	deque<string> movement;
string menu="1. Forward\n2. Backward\n3. Right\n4. Left\n5. Repeat\n6. Undo\n7. List\n8. Quit\n";

	int choice=0;
	do {
		choice=ReadValue<int>(menu,1,8);
		switch (choice) {
			case 1:
				cout << "\t\tForward\n";
				movement.push_back("Forward");
				break;
			case 2:
				cout << "\t\tBackward\n";
				movement.push_back("Backward");
				break;
			case 3:
				cout << "\t\tRight\n";
				movement.push_back("Right");
				break;
			case 4:
				cout << "\t\tLeft\n";
				movement.push_back("Left");
				break;
			case 5:
				{
					int len=movement.size();
					for (int i=0;i<len;i++) 
						movement.push_back(movement[i]);
				}
				break;
			case 6:
				if (!movement.empty()){
					string value=movement.back();
					if (value=="Right") 
						cout << "\t\tLeft\n";
					else if (value=="Left") 
						cout << "\t\tRight\n";
					else if (value=="Forward") 
						cout << "\t\tBackward\n";
					else if (value=="Backward") 
						cout << "\t\tForward\n";
					else 
						cout << "Unknown command\n";

					movement.pop_back();
				}
				break;
			case 7:
				{
					for (auto itr=movement.begin();itr!=movement.end();itr++)
						cout << "\t\t" << *itr << endl;
				}
				break;
			default:
				break;
		}
	} while (choice != 8);

	return 0;
}
