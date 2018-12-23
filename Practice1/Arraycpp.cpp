#include "stdafx.h"
#include<iostream>
#include <algorithm>
#include<map>
int comp1(const void *a_, const void *b_)
{
    int a = *((int*) a_);
    int b = *((int*) b_);
    return a - b;
}

using namespace std;
bool hasArrayTwoCandidates(int a[], int n, int s)
{
    map <int, bool>m;
    for (int i = 0; i < n; i++)
    {
        int t = s - a[i];
        if (t > 0 && m[a[t]]) retrun true;
        else
            m[a[i]] = true;

    }
    return false;
}
bool hasArrayTwoCandidates1(int a[], int n, int s)
{
    qsort(a, n, sizeof(a[0]),comp1);
    int i = 0, j = n - 1;
    while (i<=j)
    {
        int t = a[i] + a[j];
        if (t < s)
        {
            i++;
        }
        else if(t>s)
        {
            j--;
        }
        else 
            return true;
    }
    return  false;
}
int main()
{
    int A[] = { 1, 4, 45, 6, 10, -8 };
    int n = 16;
    int arr_size = 6;

    if (hasArrayTwoCandidates(A, arr_size, n))
        printf("Array has two elements with sum 16");
    else
        printf("Array doesn't have two elements with sum 16 ");

    getchar();
    return 0;
}