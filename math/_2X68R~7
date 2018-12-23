#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void printLucky(int n)
{
       int  *data, index = 2, i = 0, j,count;
        data = (int *)malloc(sizeof(int) * n);
        while(i < n) { data[i] = i + 1;  i++; } // set all number in array
        if (n < 2) {  printf("Lucky Number is 1!!\n");  return ; }

        while (index <= n) {
                j = count = 0;
                for (i = index - 1; i < n; i = i + index) { data[i] = -1;} //set no. = -1 if its location is 2,3,4 iterativly
                for (i = 0; i < n; i++) { if (data[i] != -1) {  data[j++] = data[i]; } } // move element back 
                n = j;
                index++;
        }

        printf("Lucky Numbers:");
        for (i = 0; i < n; i++) { printf("%d  ", data[i]);}  printf("\n");
}
bool isLucky(int n) // check wheather numbe ris divisble by 2,3,4,5 ... n-1
{
int counter=2;
while(counter<=n)
{
if(n%counter==0) return false;
n=n-n/counter;
counter++;
}
return true;
}
int main() {

for(int i=1;i<40;i++)
if(isLucky(i)) cout<<i<<" ";
cout<<endl;
printLucky(40);
         return 0;
  }
