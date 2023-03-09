#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdlib>

#ifndef LIST_H
#define LIST_H

template <class DataType>
class List
{
	protected:
		std::vector<DataType> data;
		
	public:
		List();
		void Clear();
		void Sort();
		DataType Min();
		DataType Max();
		double Median();
		double Average();
		long Count();
		bool Exists(DataType val);
		void Display(std::ostream& out);
		void Random(long count,long min, long max);
		void Unique();

		DataType& operator[] (long index);
};


template <class DataType>
List<DataType>::List()
{
	;
}

template <class DataType>
void List<DataType>::Clear()
{
	data.clear();
}

template <class DataType>
void List<DataType>::Sort()
{
	std::sort(data.begin(),data.end());
}

template <class DataType>
DataType List<DataType>::Min()
{
	return *(std::min_element(data.begin(),data.end()));
}

template <class DataType>
DataType List<DataType>::Max()
{
	return *(std::max_element(data.begin(),data.end()));
}

template <class DataType>
double List<DataType>::Median()
{
	long mid=data.size()/2;
	if (mid==0) {
		throw "Median: List size is 0!";
	}

	std::vector<DataType> temp=data;
	sort(temp.begin(),temp.end());
	
	return (temp.size() % 2)?temp[mid]:(temp[mid]+temp[mid-1])/2.0;
}

template <class DataType>
double List<DataType>::Average()
{
	double sum=0.0;
	long count=data.size();
	if (count == 0) {
		throw "Average: List size is 0!";
	}
	for(auto itr=data.begin();itr!=data.end();itr++) {
		sum += *itr;
	}
	return sum/count;
}

template <class DataType>
bool List<DataType>::Exists(DataType val) 
{
	return (std::is_sorted(data.begin(),data.end()))
		?find(data.begin(),data.end(),val) != data.end()
		:binary_search(data.begin(),data.end(),val);
}

template <class DataType>
void List<DataType>::Unique()
{
	auto newEnd=unique(data.begin(),data.end());
        data.erase(newEnd,data.end());
}

template <class DataType>
long List<DataType>::Count()
{
	return data.size();
}

template <class DataType>
void List<DataType>::Random(long count,long min, long max)
{
	for (long i=0;i<count;i++){
		data.push_back(rand()%(max-min-1)+min);
	}
}

template <typename DataType>
void List<DataType>::Display(std::ostream& out)
{
	
	for(auto itr=data.begin();itr!=data.end();itr++) {
		out << *itr << " ";
	}
	

	
	out << std::endl;
}

template <class DataType>
DataType& List<DataType>::operator[] (long index)
{
	return data[index];
}

#endif