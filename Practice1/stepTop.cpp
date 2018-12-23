#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 
int countWays(int s, int m)
{
if(s<=1) return s;
int steps=0;
for( int i=1;i<=m&& i<=s;i++)
{
steps += countWays(s-i,m);
}
return steps;
}
int main(int argc, char **argv)
{
  int s = 5, m = 4;
    printf("Nuber of ways = %d", countWays(s+1, m));
    return 0;
return 0;
}
