#include<stdlib.h>

 void swap(int &a, int &b) { int t = a; a = b; b = t; }
	void bubbleSort(int a[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - i - 1; j++)
				if (a[j] < a[j + 1]) swap(a[j], a[j + 1]);
		}

	}
	void selectionSort(int a[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
				if (a[i] > a[j])swap(a[i], a[j]);
		}
	}
	void insertionSort(int a[], int n)
	{

	}

	void mergeSort(int a[], int n)
	{

	}
	void quicksort(int a[], int n)
	{

	}
	void heapsort(int a[], int n)
	{

	}
