#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;

double sqrtd(double n)
{
  double m,l=0,h=n;
  double e=0.000001;
  while(h-l > e)
  {
    m=(l+h)/2; // l+(h-l)/2
    if(m*m==n) return m;
    else if(m*m>n)
      h=m;
    else
      l=m;
  }
return m;
}
double sqrt(double n)
{
  double l=1;
  double e=0.00000001;
  while(n-l > e)
  {
    n=(l+n)/2; // l+(h-l)/2
    l=l/n;
  }
return n;
}
int main(int argc, char **argv)
{
printf("%f\n",sqrtd(97));
printf("%f\n",sqrt(97));

return 0;
}
