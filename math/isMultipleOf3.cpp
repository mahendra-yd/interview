#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
#include<math.h>
using namespace std;
int abs(int x)
{ 
return x>0?x:-x ;
}
bool isMultple3(int n)
{
  if(n==0) return true;
  if(n==1) return false;
  int odd=0,even=0;
  while(n)
  {
    if(n&1) odd++;
    n=n>>1;
    if(n&1) even++;
      n=n>>1;
  }
  return isMultple3(abs(odd-even));
}

int main(int argc, char **argv)
{
  cout<<isMultple3(23);

  return 0;
}
