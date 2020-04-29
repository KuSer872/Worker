#include <iostream>
#include "Worker.h"
#include "sorting.h"
using namespace std;

void Search(Worker* arr, int n, int exp)
{
	if (exp != -1) {
		bool flag = 0;
		for (int i = 0; i < n; i++)
			if (2020 - arr[i].get_year() > exp) {
				cout << arr[i].get_f() << endl;
				flag = 1;
			}
		if (!flag)
			cout << "Worker Not Found" << endl;
	}
	return;
}

int main()
{
	ifstream f("f.txt", ios_base::in);

	int n;
	f >> n;

	Worker* workers = new Worker[n];

	cout << "Original" << endl << endl;

	for (int i = 0; i < n; i++)
		f >> workers[i];
	for (int i = 0; i < n; i++)
		cout << workers[i];

	qsort(workers, n, sizeof(Worker), Worker::sort_x3);

	fstream out("Workers.bin", ios::out | ios::binary);
	for (int i = 0; i < n; i++)
		workers[i].writeBin(out);
	out.close();

	cout << endl << endl << "BIN READING QSORT\nsort x3" << endl << endl;

	fstream in("Workers.bin", ios::in | ios::binary);
	for (int i = 0; i < n; i++)
	{
		workers[i].readBin(in);
	}
	in.close();

	for (int i = 0; i < n; i++)
		cout << workers[i];

	for (int i = 0; i < n; i++)
		workers[i].reset();
	f.clear();
	f.seekg(ios_base::beg);

	f >> n;
	for (int i = 0; i < n; i++)
		f >> workers[i];

	insertion_sort(workers, n);

	cout << endl << endl << "Insertion Sort" << endl << endl;

	for (int i = 0; i < n; i++)
		cout << workers[i];

	for (int i = 0; i < n; i++)
		workers[i].reset();
	f.clear();
	f.seekg(ios_base::beg);

	f >> n;
	for (int i = 0; i < n; i++)
		f >> workers[i];

	selection_sort(workers, n);

	cout << endl << endl << "Selection Sort" << endl << endl;

	for (int i = 0; i < n; i++)
		cout << workers[i];

	for (int i = 0; i < n; i++)
		workers[i].reset();
	f.clear();
	f.seekg(ios_base::beg);

	f >> n;
	for (int i = 0; i < n; i++)
		f >> workers[i];

	bubble_sort(workers, n);

	cout << endl << endl << "Bubble Sort" << endl << endl;

	for (int i = 0; i < n; i++)
		cout << workers[i];

	for (int i = 0; i < n; i++)
		workers[i].reset();
	f.clear();
	f.seekg(ios_base::beg);

	f >> n;
	for (int i = 0; i < n; i++)
		f >> workers[i];

	shell_sort(workers, n);

	cout << endl << endl << "Shell Sort" << endl << endl;

	for (int i = 0; i < n; i++)
		cout << workers[i];

	for (int i = 0; i < n; i++)
		workers[i].reset();
	f.clear();
	f.seekg(ios_base::beg);

	f >> n;
	for (int i = 0; i < n; i++)
		f >> workers[i];

	quick_sort(workers, 0, n - 1);

	cout << endl << endl << "Quick Sort" << endl << endl;

	for (int i = 0; i < n; i++)
		cout << workers[i];

	int exp = 0;
	cout << "\nEnter experience of worker.\nEnter \"-1\" if you want to stop.\n" << endl;
	while (exp != -1)
	{
		cin >> exp;
		Search(workers, n, exp);
	}
}

