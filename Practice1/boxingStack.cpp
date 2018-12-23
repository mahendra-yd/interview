#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 
struct Box
{
  // h .> height, w .> width, l .> length
  int h, w, l;  // for simplicity of solution, always keep w <= d
};
int compare(Box a, Box b)
{
return a.w*a.l > b.w*b.l;
}

int lis(Box a[], int n)
{
  Box rotate[n*3];
  int k=0;
  for( int i=0;i<n;i++)
  {
    rotate[k]=a[i];
    k++;
    rotate[k].h=a[i].w;
    rotate[k].w= Min(a[i].h,a[i].l);
    rotate[k].l= max(a[i].h,a[i].l);
    k++;
    rotate[k].h=a[i].l;
    rotate[k].w=Min(a[i].h,a[i].w);
    rotate[k].l=max(a[i].h,a[i].w);
    k++;
  }
  n=n*3;
  sort(rotate,rotate+n-1,compare);

  int l[n+1];
  for( int i=0;i<n;i++) l[i]=rotate[i].h;

  for( int i=1;i<n;i++)
    for( int j=0;j<i;j++)
      if( rotate[i].w*rotate[i].l < rotate[j].l * rotate[j].w && l[i]<l[j]+rotate[j].h)
	l[i]=l[j]+rotate[j].h;
  int m=0;
  for(int i=0;i<n;i++)
    if(m<l[i])m=l[i];
  return m;
}

int main(int argc, char **argv)
{
  Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
  int n = sizeof(arr)/sizeof(arr[0]);

  printf("The maximum possible height of stack is %d\n",
      lis (arr, n) );


  return 0;
}
