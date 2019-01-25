#include"stdafx.h"
#include<iostream>

using namespace std;

void PrintSpiral(const vector<vector<int>> & matrix)
{
	int row = matrix.size();
	int col = matrix[0].size();
	int r = 0, c = 0;
	while (r < row && c < col)
	{
		// print upper row
		/*
		00 01 02 03 04
		10 11 12 13 14
		20 21 22 23 24
		*/
		for (int i = c; i < col; i++)
		{
			cout<<setw(2) << matrix[r][i] << " ";
		}
		r++;
		// print right col

		for (int i = r; i < row; i++)
		{
			cout << setw(2) << matrix[i][col-1] << " ";
		}
		col--;
		// print bottom row
		if (r < row)
		{
			for (int i = col - 1; i >=c; i--)
			{
				cout << setw(2) << matrix[row - 1][i] << " ";
			}
			row--;
		}
		// print left col
		if (c < col)
		{
			for (int i = row - 1; i >= r; i--)
			{
				cout << setw(2) << matrix[i][c] << " ";
			}
			c++;
		}
	}
}
void PrintMatrix(const vector<vector<int>> matrix)
{
	int  row = matrix.size();
	int col = row;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout<<setw(2)<< matrix[i][j]<<" ";
		}
		cout << endl;
	}
}
void RotateMatrix90(vector<vector<int>> & matrix)
{
	int  row = matrix.size();
	int col = row;

	//1st approach do transpose of matrix and then reverse rows
	//for (int i = 0; i < row; i++)
	//	for (int j = 0;j<i && j < col; j++)
	//		swap(matrix[i][j] ,matrix[j][i]);
	//for (int i = 0; i < row; i++)
	//	for (int j = 0; j < col/2; j++)
	//		swap(matrix[i][j], matrix[i][col - j - 1]);
	//2nd approach do inplace 
	int N = row;
	/*
	00 01 02 03 04
	10 11 12 13 14
	20 21 22 23 24
	30 31 32 33 34
	40 41 42 43 44
	*/
	for (int i = 0; i < N/2; i++)
	{
		for (int j = i; j < N - i - 1; j++)
		{
			int t = matrix[i][j];
			matrix[i][j] = matrix[j][N - i - 1];
			matrix[j][N - i - 1] = matrix[N - i - 1][N - j - 1];
			matrix[N - i - 1][N - j - 1] = matrix[N - j - 1][i];
			matrix[N - j - 1][i] = t;
		}
	}

}
int main()
{
	vector<vector<int>> matrix = 
	{ { 1, 2,  3,  4,  5 },
	  { 6, 7,  8,  9,  10 },
	  {11, 12, 13, 14, 15 },
	 { 16, 17, 18, 19, 20 }
	};

	PrintMatrix(matrix);
	RotateMatrix90(matrix);
	cout << endl;
	PrintMatrix(matrix);
	return 0;
}
