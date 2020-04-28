#pragma once
#include <fstream>
#include <string>

using namespace std;

class Worker {
private:
	string f;
	string name;
	string post;
	int year;
public:
	Worker()
	{
		name = "";
		post = "";
		year = 0;
	}
	Worker(string f, string name, string post, int year)
	{
		this->f = f;
		this->name = name;
		this->post = post;
		this->year = year;
	}
	Worker(const Worker& a)
	{
		this->f = a.f;
		this->name = a.name;
		this->post = a.post;
		this->year = a.year;
	}
	friend ostream& operator<<(ostream& os, const Worker a)
	{
		return os << a.f << " " << a.name << " " << a.post << " " << a.year << endl;
	}
	friend istream& operator>>(istream& is, Worker& a)
	{
		return is >> a.f >> a.name >> a.post >> a.year;
	}
	bool operator>(const Worker a)
	{
		return this->year > a.year;
	}
	bool operator<(const Worker a)
	{
		return this->year < a.year;
	}
	bool operator==(const Worker a)
	{
		return this->year == a.year;
	}
	string getF()
	{
		return this->f;
	}
	string get_post()
	{
		return this->post;
	}
	int get_year()
	{
		return this->year;
	}
	static int sort_f(const void* a, void const* b)
	{
		Worker* A = (Worker*)a;
		Worker* B = (Worker*)b;
		return strcmp(A->getF().c_str(), B->getF().c_str());
	}
	static int sort_post(const void* a, const void* b)
	{
		Worker* A = (Worker*)a;
		Worker* B = (Worker*)b;
		return A->get_post().compare(B->get_post());
	}
	static int sort_year(const void* a, const void* b)
	{
		Worker A = *(Worker*)a;
		Worker B = *(Worker*)b;
		if (A > B)
			return 1;
		else if (A == B)
			return 0;
		else
			return -1;
	}
	static int sort_x3(const void* a, const void* b)
	{
		if (!sort_f(a, b))
			if (!sort_post(a, b))
				return sort_year(a, b);
			else
				return sort_post(a, b);
		else
			return sort_f(a, b);
	}
	void writeBin(fstream& file)
	{
		file.write((char*)this, sizeof(*this));
	}
	void readBin(fstream& file)
	{
		file.read((char*)this, sizeof(*this));
	}
};