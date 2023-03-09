#include <iostream>
#include <vector>

#ifndef LIST_H
#define LIST_H

class List
{
	protected:
		std::vector<double> data;
		
	public:
		List();
		void Clear();
		void Sort();
		double Min();
		double Max();
		double Median();
		double Average();
		long Count();
		bool Exists(double val);
		void Display(std::ostream& out);
		void Random(long count,long min, long max);
		void Unique();

		double& operator[] (long index);
};

#endif