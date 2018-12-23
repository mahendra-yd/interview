
#include<iostream>
#include<map>
#include<stdlib.h>
#include<algorithm>
#include "Array.h"
using namespace std;
#define LESS <
#define GREATER >
#define COMP GREATER
void heapifyMin(int a[], int i, int n)
{
	int l = 2 * i + 1, r = l + 1;
	while (r < n)
	{
		if (a[l] COMP a[r])r = l;
		if (a[r] COMP a[i]) swap(a[i], a[r]);
		else break;
		i = r;
		l = 2 * i + 1, r = l + 1;
	}
	if (l<n&& a[l] COMP a[i]) swap(a[l], a[i]);
}
void heapSort(int a[], int n)
{
	for (int i = n/2-1; i >=0; i--)
		heapifyMin(a, i, n);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		heapifyMin(a, 0, i);
	}
	for (int i = 0; i < n; i++) cout << a[i] << " ";
}
void selectionSort1(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] < a[j]) swap(a[i], a[j]);
		}
	}
}

void selectionSort(int a[], int n)
{
	// modified selction sort for minimum swap
	int min = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[min] > a[j]) min=j;
		}
		swap(a[i], a[min]);
	}
}
//http://en.wikipedia.org/wiki/Cycle_sort