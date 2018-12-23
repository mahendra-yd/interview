// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<string>
#include <regex>

#define N 4
using namespace std;

class Solution1 {
public:
	int myAtoi(string str) {
		int  sign = 1;// false if -ve
		int i = 0;
		long long int result = 0;
		int len = str.length();
		while (i<len && (str[i] == ' ' || str[i] == '\t')) i++;
		if (i == len) return 0;
		if (str[i] == '+' || str[i] == '-') {
			if (str[i] == '-') { sign = -1; }
			i++;
		}

		while ((str[i] - '0') >= 0 && (str[i] - '0') <= 9 && i<len)
		{
			result = result * 10 + (str[i] - '0');
			i++;
		}


		if (result == INT32_MAX)
			return INT32_MAX;
		if (result == INT32_MIN * -1)
			return INT32_MIN;
		if (result > INT32_MAX)
			return INT32_MIN;

		return result * sign;
	}
};
class Solution2 {
public:
	string convert(string s, int numRows) {
		int r = numRows, c = 500;
		vector<vector<char>> mat(r, vector<char>(c, 0));
		cout << s << endl;
		int i = 0, k = 0, j = 0;
		int len = s.length();
		while (k<len)
		{
			i = 0;
			while (i<numRows && k<len)
			{
				mat[i++][j] = s[k++];
			}
			i--; i--; j++;
			while (i>0 && k<len)
			{
				mat[i--][j++] = s[k++];
			}
			j++;
		}

		int row = mat.size();
		int col = mat[0].size();
		string res;
		for (int i = 0; i<row; i++)
		{
			for (int j = 0; j<col; j++)
			{
				if (isChar(mat[i][j]))
				{
					res.append(1, mat[i][j]);
					cout << mat[i][j] << " ";
				}
				else
					cout << " ";

			}
			cout << endl;
		}
		return res;
	}

	bool isChar(char c)
	{
		return (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')));
	}
};
class Solution {
public:
	bool isMatch(string s, string p) {
		if (s.empty()) return p.empty();
		if (p.empty()) return false;

		bool fmatch = s[0] == p[0] || p[0] == '.';

		if (p.length() >= 2 && p[1] == '*')
		{
			return isMatch(s, p.substr(2)) || fmatch && isMatch(s.substr(1), p);
		}
		else
		{
			return fmatch && isMatch(s.substr(1), p.substr(1));
		}
	}
};

