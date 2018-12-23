#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 

int x[]={0,0,-1,0,1};
int y[]={0,-1,0,1,0};
bool isSafe(char k[4][3], int a, int b)
{ 
  if(a>=0&&a<4 &&b>=0&&b<3&& k[a][b]!='*' && k[a][b]!='#') 
    return true; 
  return false;
}
int util(char s[4][3], int i, int j,int n)
{
  if(n<=0) return 0;
  if(n==1) return 1;
  int count=0;
  for( int k=0;k<5;k++)
  {
    int a=i+x[k];
    int b=j+y[k];
    if(isSafe(s,a,b))
      count+=util(s,a,b,n-1);
  }
  return count;
}
int getCount(char k[4][3], int n)
{
  if(n==1) return 10;
  int count=0;
  for( int i=0;i<4;i++)
  {
    for(int j=0;j<3;j++)
    {
      if(k[i][j]!='*' && k[i][j]!='#')
	count+=util(k,i,j,n);
    }
  }
  return count;
}
int main(int argc, char **argv)
{
char keypad[4][3] = {{'1','2','3'},
                        {'4','5','6'},
                        {'7','8','9'},
                        {'*','0','#'}};
   printf("Count for numbers of length %d: %d\n", 1, getCount(keypad, 1));
   printf("Count for numbers of length %d: %d\n", 2, getCount(keypad, 2));
   printf("Count for numbers of length %d: %d\n", 3, getCount(keypad, 3));
   printf("Count for numbers of length %d: %d\n", 4, getCount(keypad, 4));
   printf("Count for numbers of length %d: %d\n", 5, getCount(keypad, 5));

return 0;
}
