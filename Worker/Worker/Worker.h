#include <fstream>
#include <string>
using namespace std;
#pragma once
class Worker {
private:
	string name;
	string post;
	int year;
public:
	Worker()
	{
		this->name = "\0";
		this->post = "\0";
		this->year = 0;
	}
	Worker(string name, string post, int year)
	{
		this->name = name;
		this->post = post;
		this->year = year;
	}
	Worker(const Worker& a)
	{
		this->name = a.name;
		this->post = a.post;
		this->year = a.year;
	}

	friend ostream& operator<<(ostream& os, const Worker a)
	{
		return os << a.name << " " << a.post << " " << a.year << endl;
	}

	friend istream& operator>>(istream& is, Worker& a)
	{
		return is >> a.name >> a.post >> a.year;
	}

};

