#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
#include<string.h>
using namespace std;
bool isPalindrome(int i,int j, char* s)
{
while(i<j)
{
if(s[i]!=s[j]) return false;
i++;j--;
}
return true;
} 
int longestPalSubstr(char *s)
{
int n=strlen(s);
int m=INT_MIN;int x=0,y=0;
for(int i=0;i<n;i++)
for(int j=i;j<n;j++)
if(isPalindrome(i,j,s)) { if(m<j-i) {m=j-i;x=i;y=j;}}
for(int i=x;i<=y;i++)
cout<<s[i];
cout<<endl;
return y-x+1;
}

int longestPalSubstrDP(char *s)
{
  //t[i][j]=t[i+1][j-1];
  int n=strlen(s);
  int start,max;
  bool t[n][n];
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++) t[i][j]=false;
  for(int i=0;i<n;i++)t[i][i]=true; // string of single char is palindrome
  for(int i=0;i<n-1;i++){ if(s[i]==s[i+1]){ t[i][i+1]=true; start=i;max=2;}} // aa or bb or cc are palindromes

  for(int i=3;i<=n;i++)
    for(int j=0;j<n-i+1;j++)
    {
      if( s[j] == s[i+j-1]&& t[j+1][i+j-2] )
      {
	t[j][i+j-1]=true;
	if(max<i) { start =j; max=i;}
      }
    }
  for(int i=start;i<start+max;i++)
    cout<<s[i];
  cout<<endl;
  return max;


}
// Driver program to test above functions
int main()
{
    char str[] = "forgeeksskeegfor";
    printf("\nLength is: %d\n", PalSubstrDP( str ) );
    return 0;
}
