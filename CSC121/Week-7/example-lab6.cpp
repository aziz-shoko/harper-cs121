#include <iostream>
#include<string>
#include<vector>

using namespace std;

char guess(string);
bool match(char);
void display(vector<char>);

vector<char> phrase{ 'l','a','n','d',' ','o','f',' ','l','i','n','c','o','l','n' };
vector<char> phrase2{ 'x','x','x','x',' ','x','x',' ','x','x','x','x','x','x','x' };

int main()
{
	std::cout << "Wheel of Fortune ";

	while (1)												// end Loop when puzzle is solved
	{
		display(phrase2);
		char g = guess("\nWhat is your guess?");				// Loop as long as the guess have a match
		bool t = match(g);
		if (t == false)
			cout << "\n no letter match ";

		display(phrase2);
		char gc = guess(" guess comp ");
		bool tc = match(gc);
	}

	return 0;
}
void display(vector<char> m)
{
	for (char e : phrase2)
	{
		cout << " " << e;
	}
}

char guess(string prompt)
{
	cout << prompt;
	char x;
	cin >> x;

	return x;

}

bool match(char cg)
{
	int i = 0;
	bool match = 0;
	for (char e : phrase)
	{
		if (cg == e)
		{
			cout << "\nmatch found ";
			match = 1;
			phrase2[i] = cg;
		}
		i++;
	}
	return match;
}
