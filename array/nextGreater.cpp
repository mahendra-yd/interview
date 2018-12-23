#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;
void printNGE(int a[], int n)
{
  stack<int> s;
  for(int i=0;i<n;i++)
  {
    if(!s.empty())
    {
     while(a[i]>s.top()){ printf("[%d -> %d]\n",s.top(),a[i]);s.pop();if(s.empty()) break; }
    
    }
    s.push(a[i]);
  }

 while(!s.empty()){ printf("[%d -> -1]\n",s.top());s.pop();}

}

/* Driver program to test above functions */
int main()
{
    int arr[]= {11, 13, 21, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}
