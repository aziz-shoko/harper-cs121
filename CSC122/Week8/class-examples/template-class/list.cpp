#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include "list.h"


List::List()
{
	;
}

void List::Clear()
{
	data.clear();
}

void List::Sort()
{
	std::sort(data.begin(),data.end());
}

double List::Min()
{
	return *(std::min_element(data.begin(),data.end()));
}

double List::Max()
{
	return *(std::max_element(data.begin(),data.end()));
}

double List::Median()
{
	if (data.empty()) {
		throw "Median: List size is 0!";
	}

	long mid=data.size()/2;

	std::vector<double> temp=data;
	sort(temp.begin(),temp.end());
	
	return (temp.size() % 2)?temp[mid]:(temp[mid]+temp[mid-1])/2.0;
}

double List::Average()
{
	double sum=0.0;
	long count=data.size();
	if (count == 0) {
		throw "Average: List size is 0!";
	}
	//for(std::vector<double>::iterator itr=data.begin();itr!=data.end();itr++) {
	for(auto itr=data.begin();itr!=data.end();itr++) {
		sum += *itr;
	}
	return sum/count;
}

bool List::Exists(double val) 
{
	return (std::is_sorted(data.begin(),data.end()))
		?binary_search(data.begin(),data.end(),val)
		:find(data.begin(),data.end(),val) != data.end();
}

void List::Unique()
{
	//std::vector<double>::iterator newEnd=unique(data.begin(),data.end());
	auto newEnd=unique(data.begin(),data.end());
        data.erase(newEnd,data.end());
}

long List::Count()
{
	return data.size();
}

void List::Random(long count,long min, long max)
{
	for (long i=0;i<count;i++){
		data.push_back(rand()%(max-min-1)+min);
	}
}

void List::Display(std::ostream& out)
{
	//for(std::vector<double>::iterator itr=data.begin();itr!=data.end();itr++) {
	for(auto itr=data.begin();itr!=data.end();itr++) {
		out << *itr << " ";
	}
	out << std::endl;
}

double& List::operator[] (long index)
{
	return data[index];
}