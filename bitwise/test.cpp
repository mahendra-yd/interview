#include<iostream>
#include<list>
#include<stdio.h>
using namespace std;
void changeToZero(int a[2])
{
//     a[ a[1] ] = a[ !a[1] ];
      a[0]  = !a[0] ;
}
 
 int main()
 {
     int a[] = {1, 1};
        changeToZero(a);
         
            printf(" arr[0] = %d \n", a[0]);
               printf(" arr[1] = %d ", a[1]);
                     return 0;
 }
