#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<queue>
#include<list>
#define ROW 4
#define COL 5
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 
int kadence(int a[], int n, int& top,int& bottom)
{
  bottom =-1;
  int max=INT_MIN,sum=0;;
  int localStart=0;
  for( int i=0;i<n;i++)
  {
    sum+=a[i];
    if(sum<0) { sum=0; localStart=i+1;}
    else
    if(max<sum) { max=sum; bottom=i;top=localStart;}
  }
  if(bottom!=-1) return max;
  
 top=bottom=0;
  max=a[0];
    for( int i=1;i<n;i++)
    {
      if(max<a[i]){top=bottom=i; max=a[i];}
    }
  
  return max;
}

void findMaxSum(int M[ROW][COL])
{
  int Left,Right,Top,Bottom;
  int top, bottom;
  int t[ROW]={0,};
  int sum=0,max=INT_MIN;
  for( int i=0;i<COL;i++)
  { 
    memset(t,0,ROW);
    for(int j=i;j<COL;j++)
    {
      for( int k=0;k<ROW;k++)
	t[k]+=M[k][j];
      sum = kadence(t,ROW,top,bottom);
      if(max<sum) {
           max=sum; 
           Top=top;
           Bottom=bottom;
           Left=i;
           Right=j;
        }
    }
  }
cout<<max<<"done;";
cout<<Left<< "  "<<Right<< "  "<<Top<< "  "<<Bottom<< "  "<<endl;
  for( int i=Left;i<Right;i++)
  {
    for( int j=Top;j<Bottom;j++)
      cout<<M[i][j]<<" ";
    cout<<endl;
  }
}
int main(int argc, char **argv)
{
  int M[ROW][COL] = {
    {1, 2, -1, -4, -20},
    {-8, -3, 4, 2, 1},
    {3, 8, 10, 1, 3},
    {-4, -1, 1, 7, -6}
  };
  findMaxSum(M);
  return 0;
}
