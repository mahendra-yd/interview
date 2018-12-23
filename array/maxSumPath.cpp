#include<iostream>
using namespace std;
int max(int x, int y) { return (x > y)? x : y; }
int maxPathSum(int a1[], int a2[], int m, int n)
{
  int i=0,j=0;
  int s1=0,s2=0,s=0;
  while(i<m&&j<n)
  {
    if(a1[i]>a2[j])
      s1+=a1[i++];
    else if(a1[i]<a2[j])
      s2+=a2[j++];
    else
    {
      s+=max(s1,s2);s1=s2=0;
      while(i<m&&j<n && a1[i]==a2[j]){s+=a1[i++];j++;} 
    }
  }
  while(i<m)
    s1+=a1[i++];
  while(j<n)
    s2+=a2[j++];
  s+=max(s1,s2);
  return s;
}
 
// Driver program to test above function
int main()
{
    int ar1[]  = {2, 3, 7, 10, 12, 15, 30, 34};
    int ar2[] =  {1, 5, 7, 8, 10, 15, 16, 19};
    int m = sizeof(ar1)/sizeof(ar1[0]);
    int n = sizeof(ar2)/sizeof(ar2[0]);
    cout << maxPathSum(ar1, ar2, m, n);
    return 0;
}
