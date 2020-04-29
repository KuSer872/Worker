#include <iostream>
template <class T>
inline void insertion_sort(T* A, int n)
{

	for (int i = 1; i < n; i++) {
		T key = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > key)
		{
			A[j + 1] = A[j];
			j = j - 1;
		}
		A[j + 1] = key;
	}
}

template <class T>
inline void selection_sort(T* A, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (A[min] > A[j])
				min = j;

		if (min != i) {
			T tmp = A[i];
			A[i] = A[min];
			A[min] = tmp;
		}
	}
}

template <class T>
inline void bubble_sort(T* A, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (A[j] > A[j + 1])
			{
				T tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}

}

template <class T>
inline void shell_sort(T* A, int n)
{
	for (int step = n / 2; step > 0; step /= 2)
		for (int i = step; i < n; i++)
			for (int j = i - step; j >= 0 && A[j] > A[j + step]; j -= step)
			{
				T tmp = A[j];
				A[j] = A[j + step];
				A[j + step] = tmp;
			}
}

template <class T>
inline void quick_sort(T* A, int left, int right, bool start = true)
{
	if (start) right -= 1;
	T mid = A[(left + right) / 2];
	int l = left; int r = right;
	do {
		while (A[l] < mid)
			l++;
		while (A[r] > mid)
			r--;
		if (l <= r) {
			if (l < r) {
				T help = A[l];
				A[l] = A[r];
				A[r] = help;
			}
			l++;
			r--;
		}
	} while (l <= r);
	if (l < right)
		quick_sort(A, l, right, false);
	if (left < r)
		quick_sort(A, left, r, false);
}