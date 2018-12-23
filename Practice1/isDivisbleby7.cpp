#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 

bool isDivisbleBy7(int n)
{
if(n<0) return isDivisbleBy7(-n);
if(n==0||n==7) return true;
if(n<10) return false;
return isDivisbleBy7(n/10-2*(n-(n/10)*10));
}
int main(int argc, char **argv)
{
cout<<isDivisbleBy7(616);

return 0;
}
