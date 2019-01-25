#include"stdafx.h"
#include<queue>
using namespace std;
void InsertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int j = i-1;
		int x = a[i];
		while (j >= 0 && a[j] >x)
		{
			a[j+1] = a[j];
			j = j - 1;
		}
		a[j + 1] = x;
	}
}

void Bubblesort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for(int j=0;j<n-i-1;j++)
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
	}
}

void SelectionSort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;

		int temp = a[min];
		a[min] = a[i];
		a[i] = temp;
	}
}

int quickSortPartitaion(int a[], int l, int h)
{
	int m = (l + h) / 2;
	// compute median of first,mid,last this improve performance
	if (a[l] > a[m])
		swap(a[l], a[m]);
	if (a[m] > a[h])
		swap(a[m], a[h]);
	swap(a[m], a[h]);

	int pivot = a[h];
	int i = l-1;
	for (int j = l; j < h; j++)
	{
		if ( a[j] > pivot)
			swap(a[j], a[++i]);
		
	}
	swap(a[++i], a[h]);
	return i;
}

void quickSortUtil(int a[], int l, int h)
{
	if (l >= h) return;
	int key = quickSortPartitaion(a, l, h);
		//make partition of equal
		quickSortUtil(a, l, key-1 );
		quickSortUtil(a, key+1 , h);
}
void QuickSort(int a[], int n)
{
	quickSortUtil(a, 0, n - 1);
}

void PrintArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(2) << a[i]<<" ";
	cout << endl;
}

void heapify(int a[], int root, int n)
{
	int l = root * 2 + 1;
	int r = l + 1;
	int largest = root;
	if (l<n&& a[l]>a[largest])
		largest = l;
	if (r<n&&a[r]>a[largest]) 
		largest = r;
	if (root != largest)
	{
		swap(a[root], a[largest]);
		heapify(a, largest, n);
	}
}

void HeapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; --i)
		heapify(a, i, n);
	for (int i = n - 1; i > 0; --i)
	{
		swap(a[0], a[i]);
		heapify(a, 0, i);
	}
}

bool compareGreater(int a, int b)
{
	return a > b ? true : false;
}

template <typename T>
class priorityqueue
{
	size_t n;
	int loc;
	T *store;
	

	void bubbleUp(int n)
	{
		int parrent = n - 1 / 2;
		if (parrent < 0) return;
		if ((store[parrent]<store[n]))
		{
			swap(store[parrent], store[n]);
			bubbleUp(parrent);
		}
	}

	void bubbleDown(int c)
	{
		int l = 2 * c + 1;
		int r = l + 1;
		int max = c;
		if (l <= loc && (store[l]<store[max]))
			swap(store[l], store[max]);
		if (r <= loc && (store[r]<store[max]))
			swap(store[r], store[max]);
		if (max != c)
		{
			swap(store[max], store[c]);
			bubbleDown(max);
		}
	}

	bool compareLess(T a, T b)
	{
		return a < b ? true : false;
	}
public:
	bool(priorityqueue::*compfun)(T, T);
	priorityqueue(unsigned int size = 1000, bool(priorityqueue::*comp)(T , T) = &priorityqueue::compareLess)
	{
		n = size;
		loc = -1;
		compfun = comp;

		store = new T[n];
	}

	void push(T item) {
		store[++loc] = item;
		if ((store[0]<store[loc]))
			swap(store[0], store[loc]);
		bubbleUp(loc);
	}

	void  pop(){
		swap(store[0], store[loc]);
		loc--;
		bubbleDown(0);
	}
	T top(){
		return store[0];
	}
};
void DemoPriorityQueue(){
	priorityqueue <int > q(100u);
	q.push(7);
	q.push(1);
	q.push(5);
	q.push(12);
	cout << q.top() << endl; q.pop();
	cout << q.top() << endl; q.pop();
	q.push(6);
	q.push(2);
	cout << q.top() << endl; q.pop();
	cout << q.top() << endl; q.pop();
	cout << q.top() << endl; q.pop();
	cout << q.top() << endl; q.pop();
}
void mergesortedArray(int a[], int l, int m, int h)
{
	int *buf = new int[h-l+1];
	int i = l, j = m+1,k=0;
	while (i <= m && j <= h)
	{
		if (a[i] > a[j])
			buf[k] = a[j++];
		else
			buf[k] = a[i++];
		k++;
	}

	while (i <= m )
			buf[k++] = a[i++];
	while (j <= h)
		buf[k++] = a[j++];
	 k = 0;
	 for (int i = l; i <= h; i++)
		 a[i] = buf[k++];
	
}
void mergeUtil(int a[], int l, int h)
{
	if (l < h) {
		int m = (h + l) / 2;
		mergeUtil(a, l, m);
		mergeUtil(a, m+1 , h);
		mergesortedArray(a, l, m, h);
	}
}
void MergeSort(int a[], int n)
{
	mergeUtil(a, 0, n - 1);
}

void quickSortDemo()
{
	int a[] = { 7,1,5,12,6,2,3,18,9 };
	QuickSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

