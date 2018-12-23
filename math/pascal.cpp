#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;

// A O(n^2) time and O(1) extra space function for Pascal's Triangle
void printPascal(int n)
{
  for (int line = n; line <= n; line++)
  {
    int C = 1;  // used to represent C(line, i)
    for (int i = 1; i <= line; i++)  
    {
      printf("%d ", C);  // The first value in a line is always 1
      C = C * (line - i) / i;  
    }
    printf("\n");
  }
}
int main(int argc, char **argv)
{

printPascal(5);
return 0;
}
