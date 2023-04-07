#include <iostream>
#include "queue.h"

using namespace std;


int main()
{
	Queue l;
	l.Enqueue(10);
	l.Enqueue(20);
	l.Enqueue(30);
	l.Enqueue(40);
	cout << l;
	cout << endl;

	cout << "Dequeue: " << l.Dequeue() << endl;
	cout << "Dequeue: " << l.Dequeue() << endl;
	cout << l;
	cout << endl;

	return 0;
}
