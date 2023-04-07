#include <iostream>
#include "queue.h"
#include "input.h"

using namespace std;

bool PopulateFibonacci(Queue& q, long count);

bool PopulateFibonacci(Queue& q, long count)
{
	bool rv=false;
	long first=0,second=1;
	if (q.Enqueue(first) && q.Enqueue(second)) {
		rv=true;
	}
	count-=2;
	while (count>0 && rv==true) {
		long tmp=first+second;
		first=second;
		second=tmp;
		rv=q.Enqueue(tmp);
		count--;
	}
	return rv;
}

int main()
{
	Queue q;
	long count=ReadValue<long>("How many values? ",2);
	if (PopulateFibonacci(q,count)) {

		while (q.Size()>0) {
			cout << q.Dequeue() << " ";
		}
		cout << endl;
	}

	return 0;
}