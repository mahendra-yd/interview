#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;

#define R 3
#define C 6
void spiralPrint(int r,int c, int a[][C])
{
  int l=0,m=0,i=0;
  while(l<r&&m<c)
  {
    for(i=l;i<c;i++)
      cout<<a[l][i]<<" ";l++;
    for(i=l;i<r;i++)
      cout<<a[i][c-1]<<" ";c--;
    if(l<r)
    {
      for(i=c-1;i>=m;i--)
	cout<<a[r-1][i]<<" ";r--;
    }
    if(m<c)
    {
      for(i=r-1;i>=l;i--)
	cout<<a[i][m]<<" ";m++;
    }
  }

}
/* Driver program to test above functions */
int main()
{
    int a[R][C] = { 
        {1,  2,  3,  4,  5,  6},
        {7,  8,  9,  10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };
 
    spiralPrint(R, C, a);
    return 0;
}
