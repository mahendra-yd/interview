#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;

void toh(int n,char a,char b, char c)
{
  //if(n==1) cout<<"Move 1 disk from "<<a<<" to "<<b<<endl;
  if(n>0)
  {
    toh(n-1,a,c,b);
    cout<<"Move "<<n<<" disk from "<<a<<" to "<<b<<endl;
    toh(n-1,c,b,a);
  }
}
int main(int argc, char **argv)
{
toh(4,'A','B','C');
return 0;

