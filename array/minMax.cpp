#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;
struct MM  { int min,max;};
MM getMinMax( int a[], int l, int h)
{
  MM m;
  if(l==h){m.min =a[l];m.max=a[l];return m;} //if one element
  if(l+1==h) { if(a[l]>a[h]) { m.min =a[h];m.max=a[l]; } else { m.min =a[l];m.max=a[h]; } return m;} // if two elements are there in array
  int mid = (l+h)/2;
  MM ml = getMinMax(a,l,mid);
  MM mr = getMinMax(a,mid+1,h);
  if(ml.min<mr.min) m.min=ml.min; else m.min = mr.min;
  if(ml.max>mr.max) m.max=ml.max; else m.max = mr.max;
  return m;
}
int main()
{
  int arr[] = {1000, 11, 445, 1, 330, 3000};
  int arr_size = 6;
  struct MM minmax = getMinMax(arr, 0, arr_size-1);
  printf("\nMinimum element is %d", minmax.min);
  printf("\nMaximum element is %d", minmax.max);
return 0;
}
