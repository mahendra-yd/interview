#include"stdafx.h"
#include<stack>
#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<chrono>
using namespace std;
int findPlatform(int arr[], int dep[], int n)
{
	sort(arr, arr + n);
	sort(dep, dep + n);

	int counter = 1;
	int i=0, j=0;
	int max = INT_MIN;
	while(i<n&&j<n)
	{
		if (arr[i] < dep[j])
		{
			counter++;
			if (max < counter)
				max = counter;
			i++;
		}
		else
		{
			counter--;
			j++;
		}
	}
	return counter;
}

void Demo()
{
	int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
	int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Minimum Number of Platforms Required = "
		<< findPlatform(arr, dep, n);
}
