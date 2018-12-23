#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<string.h>
using namespace std;
int max (int x, int y) { return (x > y)? x : y; }
int lps(char *s,int l, int h)
{
  if(l==h) return 1;
  if(s[l]==s[h] && l+1==h) return 2;
  if(s[l]==s[h]) return lps(s,l+1,h-1)+2;
  return max(lps(s,l+1,h),lps(s,l,h-1));
}

int lpsDP(char *a,int n)
{
  int M[n][n];
for( int i=0;i<n;i++)
 for( int j=0;j<n;j++)
M[i][j]=0;   


  for(int i=0;i<n;i++) M[i][i]=1;
  //for(int i=0;i<n;i++) if(a[i]==a[i+1]) M[i][i+1]=2;
  for( int l=2;l<=n;l++)
  {
    for( int i=0;i<n-l+1;i++)
    {
      int j=i+l-1;
      if( a[i]==a[j]&&l==2) M[i][j]= 2;
      else
	if(a[i]==a[j]) M[i][j]= M[i+1][j-1]+2;
	else M[i][j] = max(M[i][j-1],M[i+1][j]);
    }
  }
for( int i=0;i<n;i++)
{for( int j=0;j<n;j++)
cout<<M[i][j]<<" ";
cout<<endl;
}

  return M[0][n-1];
}
int main(int argc, char **argv)
{
  char seq[] = "GEEKSFORGEEKS";
  int n = strlen(seq);
  printf ("The lnegth of the LPS is %d", lps(seq,0, n-1));
  printf ("The lnegth of the LPS is %d", lpsDP(seq, n));
  return 0;
}
