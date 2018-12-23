#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 

float sqrt(int n)
{
float x=n;
float y=1;
float d=0.00001;
while(x-y>d)
{
x=(x+y)/2;
y=n/x;
}
cout<<endl;
return x;
}
int main(int argc, char **argv)
{

cout<<sqrt(5);
cout<<sqrt(9);
cout<<sqrt(4);
cout<<sqrt(8);
return 0;
}
