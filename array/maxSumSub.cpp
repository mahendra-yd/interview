#include<iostream>
#include<list>
#include<stdio.h>
#include<limits.h>
using namespace std;
int max(int a,int b) { return a>b ? a : b ; }


int  maxSubArraySum(int a[], int n)
{
  int sum=~0,msum=~0;
  for(int i=0;i<n;i++)
  {
    sum = max(a[i],sum+a[i]);
    msum = max(sum,msum);
  }
  return msum;
}
int maxSubArraySum1(int a[],int n)
{
int tmp=0,max=0;
for(int i=0;i<n;i++)
{
	tmp = tmp+a[i];
	if(tmp<0)
		tmp=0;
		else
			if(tmp>max)
				max=tmp;
}
return max;


}


int main()
{
  int a[] = {-2, -3, -4, -1, -2, -1, -5, -3};
 // int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
  int n = sizeof(a)/sizeof(a[0]);
  int max_sum = maxSubArraySum(a, n);
  printf("Maximum contiguous sum is %d\n", max_sum);
  return 0;
}
