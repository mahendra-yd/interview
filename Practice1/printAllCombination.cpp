#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 
void  printCombination(int n, int i, int l)
{
  static int a[100];
  if(n==0){ for(int k=0;k<i;k++) cout<<a[k]<<" ";cout<<endl;}
  else if(n>0) 
  {
    for(int k=1;k<=l;k++)
    {

      a[i]=k;
      printCombination(n-k,i+1,l);
    }
  }
}

int main(int argc, char **argv)
{

printCombination(5,0,3);

return 0;
}
