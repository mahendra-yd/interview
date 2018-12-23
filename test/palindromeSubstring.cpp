#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<map>
#include<list>
#include<string.h>
#include<string>
using namespace std;
void prints(int i, int j,char* s)
{
  for(int l=i;l<=j;l++)
    cout<<s[l];
//  cout<<endl;
}
int PalSubstrDP(char *s)
{
  int n=strlen(s);
  map<string,bool> m;
  int start,max;
  int t[n][n];
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++) t[i][j]=0;
  for(int i=0;i<n;i++)t[i][i]=1; // string of single char is palindrome
  for(int i=0;i<n-1;i++){ if(s[i]==s[i+1]){ t[i][i+1]=1; start=i;max=2;}} // aa or bb or cc are palindromes

  for(int i=3;i<=n;i++)
    for(int j=0;j<n-i+1;j++)
    {
      if( s[j] == s[i+j-1]&& t[j+1][i+j-2] )
      {
	t[j][i+j-1]=1;
	if(max<i) { start =j; max=i;}
      }
    }
  string p(s);
  for(int i=0;i<n;i++)
  {
    for(int j=i;j<n;j++)
      if(t[i][j]) m[p.substr(i,j-i+1)]=true;
  } 
  cout<<"job done\n";
  for( map<string,bool>::iterator it=m.begin();it!=m.end();it++)
  {    cout<<it->first<< " ";cout<<endl;}
  return 0;
}
int main()
{
  //  char str[] = "forgeeksskeegfor";
  //char str[] = "abcbaaa";
  char str[] = "abaaa";
 PalSubstrDP( str  );
  return 0;
}
