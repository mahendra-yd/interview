// ConsoleApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Programm
{
public:
	virtual int  excecute() = 0;
};

// Function to print an array 
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

class ArrayRotation : public Programm
{
public:
	ArrayRotation() {};
	~ArrayRotation() {};
	int  excecute()
	{

		int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
		int n = sizeof(arr) / sizeof(arr[0]);
		RotateLeft(arr, sizeof(arr) / sizeof(arr[0]),3);
		printArray(arr, n);
		return 0;
	}
private:
	
	int i = 10;
	
	void rotateByOne(int arr[], int n)
	{
		int t = arr[n - 1];
		for (int i = n-1; i >0; i--)
		{
			arr[i ] = arr[i-1];
		}
		arr[0] = t;
		
	}

	void RotateLeft(int arr[], int n, int d)
	{
		for (int i = 0; i < d; i++)
		{
			rotateByOne(arr, n);
		}
	}



};





/* Driver program to test above functions */
int main()
{
		// Function calling
		ArrayRotation a;
		a.excecute();

	return 0;
}


