#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std; int max(int a, int b) { return a>b?a:b;} int Min(int a, int b) { return a<b?a:b;} 
int stringToIP(const char * ips)
{
  int i=strlen(ips);
  bool first=true,second=false;
  if(i>15 || i<7) return -1;
  i=0;
  int dot=0;
  int sum=0;
  int ip=0;
  while(ips[i]!='\0')
  {
    if(ips[i]=='.')
    {
      if(first) { if(sum==0) second=true;first =false;}// only if not considering 0.0.0.0
      if(second && sum>0) return -1;
      if(sum>255) return -1;
      ip= ip | (sum<<(dot*8));
      sum=0;
      dot++;
    }
    else
    {
      sum=sum*10+ ips[i]-'0';
    }
    i++;
  }
  if(dot==3) { if(sum>255) return -1; ip= ip | (sum<<(dot*8)); return ip;}
  return -1;
}
//0.6.5.4
char * ipToString( int ip)
{
char *p= new char[18];
if(ip<0) return NULL;
int a,b,c,d;
a= (ip & 0xFF000000)>24;
b=(ip & 0x00FF0000)>16; 
c=(ip & 0x0000FF00)>8;
d=(ip & 0x000000FF);
if(a>255|| b>255 || c>255 ||d >255 ||b<0||c<0||d<0 ||a<0 || a==0&&(b||c||d)) return NULL;
sprintf(p,"%d.%d.%d.%d",d,c,b,a);
return p;
}
int main(int argc, char **argv)
{
int ip = stringToIP("10.0.0.1");
cout<<ip<<endl;
printf("%s\n",ipToString(ip));
/*
struct sockaddr_in addr;
char *some_addr;
inet_aton("10.0.0.1", &addr.sin_addr); // store IP in addr
some_addr = inet_ntoa(addr.sin_addr); // return the IP
printf("%s\n", some_addr); // prints "10.0.0.1"
addr.sin_addr.s_addr = inet_addr("10.0.0.1");
*/
return 0;
}
