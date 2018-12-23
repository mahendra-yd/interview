#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 
bool del[256]={false,};
bool isDel( char d) { if(d==' '|| d=='\n' || d=='\t') return true; return false;}
int wc(const char *p)
{
  int i=0;
  int count=0;
  bool out=true;
  while((*(p+i)!='\0'))
  {
    if(out){
      while(*(p+i)!='\0' && isDel(p[i]))i++; out=false;}
    else{
      while(*(p+i)!='\0'&& isDel(p[i])!=true) i++;
      count++;
      out=true;
    }
  }
return count;
}
int main(int argc, char **argv)
{
//char p[] = " \n   \t Mahendra\n\t  \nkumar yadav\t ";
char p[] = " shekhar \
how are\
 you  ";
//char p[] = "    Mahendra kumar yadav   ";
//char p[] = "abc def ghi";
for( int i=0;i<256;i++) del[i]=false;
del['\n']=true;
del[' ']=true;
del['\t']=true;

cout<<wc(p);
return 0;
}
