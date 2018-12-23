#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<string.h>
using namespace std;
#define STRING_X "SUNDAY"
#define STRING_Y "SATURDAY"
int Min(int a,int b, int c) { return a<b?( a<c?a:c):( b<c?b:c);}
int EditDistanceRecursion(char* x, char* y,int m, int n)
{
if(m==0&&n==0) return 0;
if(m==0) return n;
if(n==0) return m;
return Min(EditDistanceRecursion(x,y,m-1,n)+1,EditDistanceRecursion(x,y,m,n-1)+1,EditDistanceRecursion(x,y,m-1,n-1)+(x[m]!=y[n]));
}
int EditDistanceDP(char* x, char* y,int m, int n)
{
  if(m==0&&n==0) return 0;
  if(m==0) return n;
  if(n==0) return m;
  int l[m+1][n+1];
  for(int i=0;i<=n;i++) l[0][i]=i;
  for(int i=0;i<=m;i++) l[i][0]=i;
  for( int i=1;i<m;i++)
  {
    for( int j=1;j<n;j++)
      l[i][j]= Min(l[i-1][j]+1,l[i][j-1]+1,l[i-1][j-1]+ (x[i]!=y[j]));
  }
  return l[m-1][n-1];
}
int main(int argc, char **argv)
{
    char X[] = STRING_X; // vertical
    char Y[] = STRING_Y; // horizontal
 
    printf("Minimum edits required to convert %s into %s is %d\n", X, Y, EditDistanceDP(X, Y, strlen(X), strlen(Y) ) );
    printf("Minimum edits required to convert %s into %s is %d by recursion\n", X, Y, EditDistanceRecursion(X, Y, strlen(X), strlen(Y)));

return 0;
}
