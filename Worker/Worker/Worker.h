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
		f = "";
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
	Worker(Worker& a)
	{
		this->f = a.f;
		this->name = a.name;
		this->post = a.post;
		this->year = a.year;
	}
	void reset()
	{
		f = "";
		name = "";
		post = "";
		year = 0;
	}
	friend ostream& operator<<(ostream& os, const Worker a)
	{
		return os << a.f << " " << a.name << " " << a.post << " " << a.year << endl;
	}
	friend istream& operator>>(istream& is, Worker& a)
	{
		return is >> a.f >> a.name >> a.post >> a.year;
	}
	bool operator>(const Worker& a)
	{
		return f.compare(a.f) > 0;
	}
	bool operator<(const Worker& a)
	{
		return f.compare(a.f) < 0;
	}
	bool operator==(const Worker& a)
	{
		return f.compare(a.f) == 0;
	}
	string get_f()
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
		return A->get_f().compare(B->get_f());
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
		if (A.get_year() > B.get_year())
			return 1;
		else if (A.get_year() == B.get_year())
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