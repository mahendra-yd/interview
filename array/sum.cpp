#include<iostream>
#include<stdio.h>
#include<list>
#include<stdlib.h>
#include<vector>
using namespace std;
int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
 
    // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
    // return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
}
 
int hasArrayTwoCandidates(int A[],int size,int sum)
{
int l=0,h=size-1;
int count=0;
qsort(A,size,sizeof(int),compare_ints);
while(l<h)
{
if(A[l]+A[h]==sum)
  { count++; l++;h--;}
else if((A[l]+A[h]<=sum))
l++;
else
h--;
}
return count;
}
#define MAX 9999
int hasSumHash2(int A[],int size,int sum)
{
  int hash[MAX]={0,};
  int count=0;
  for(int i=0;i<size;i++)
  {
    if(hash[ sum - A[i]]==1){ count++;
      cout<<A[i]<<sum-A[i]<<endl;}
    else
      hash[A[i]]=1;
  }
  return count;

}
int hasSumHash(int A[],int size,int sum)
{
 vector < pair <bool,int> > hash;
 hash.resize(MAX);
  int count=0;
  for(int i=0;i<size;i++)
  {
    int tmp= sum - A[i];
    //if(tmp<0) tmp =MAX + tmp;
    if(tmp>0&& hash[tmp].first==true){ count++;
      printf("%d is at [%d] and %d at [%d]]\n",A[i],i,sum-A[i],hash[sum-A[i]].second);}
    else
    {
      hash[A[i]].first=true;
      hash[A[i]].second=i;
    }
  }
  return count;

}


/* Driver program to test above function */
int main()
{
    int A[] = {7,45, 6, 9,24,10 };
    int n = 16;
    int arr_size = 6;
    int x=0;
    
    //if( x =hasArrayTwoCandidates(A, arr_size, n))
    if( x =hasSumHash(A, arr_size, n))
        printf("Array has two elements with sum 16 =%d\n",x);
    else
        printf("Array doesn't have two elements with sum 16 ");
 
    getchar();
    return 0;
}
