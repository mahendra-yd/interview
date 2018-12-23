#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
#include<string.h>
using namespace std;
int search(const char * p,const char * s)
{
  int pl=strlen(p),sl=strlen(s);
  if(pl>sl) return -1;
  for(int i=0;i<sl-pl;i++)
  { 
    int j,k=i;
    for( j=0;j<pl;j++)
    {
      if(p[k++]!=p[j]) break;
    }
    if(j==pl) return i;
  }
return -1;
}
void lps(int lps[],int n,const char *p)
{
  lps[0]=0;
  int l=0;
  int i=1;
  while(i<n)
  {
    if(p[i]==p[l]) { l++; lps[i]=l;i++;}
    else 
    {
      if(l==0) { lps[i]=0;i++;}
      else l=lps[l-1];
    }
  }
}
void kmp(const char *p,const char *s)
{
  int pl=strlen(p),sl=strlen(s);
  if(pl>sl) return ;
  int lp[pl];
  lps(lp,pl,p);
  int i=0,j=0;
  while(i<sl)
  {
    if(s[i]==p[j]){ i++;j++;}
    if(j==pl){ printf("pattern fount at %d\n",i-j);j=lp[j-1];}
    if(i<sl&&s[i]!=p[j])
    {
      if(j==0) i++;
      else
	j=lp[j-1];

    }
  }
}

int main(int argc, char **argv)
{
   char *txt = "AABAACAADAABAAABAA";
   char *pat = "AABA";
   //int i =search(pat, txt);
   kmp(pat, txt);
//	printf("%s",txt+i);
   return 0;

return 0;
}

/* A modified Naive Pettern Searching algorithn that is optimized
   for the cases when all characters of pattern are different */
// p="ABCD"  s="ABCDEFGHABCD ABCDS"
void search(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i = 0;
 
    while(i <= N - M)
    {
        int j;
 
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
        {
            if (txt[i+j] != pat[j])
                break;
        }
        if (j == M)  // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
        {
           printf("Pattern found at index %d \n", i);
           i = i + M;
        }
        else if (j == 0)
        {
           i = i + 1;
        }
        else
        {
           i = i + j; // slide the pattern by j
        }
    }
}
