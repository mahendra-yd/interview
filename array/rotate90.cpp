#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void displayMatrix(unsigned int const *p, unsigned int row, unsigned int col);
void rotate(unsigned int *pS, unsigned int *pD, unsigned int row, unsigned int col);
 
int main()
{
    unsigned int image[][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    unsigned int *pSource;
    unsigned int *pDestination;
    unsigned int m, n;
    m = 3, n = 4, pSource = (unsigned int *)image;
    pDestination = (unsigned int *)malloc(sizeof(int)*m*n);
    displayMatrix(pSource, m, n);
    rotate(pSource, pDestination, m, n);
    displayMatrix(pDestination, n, m);
    free(pDestination);
    return 0;
}
void rotate(unsigned int *pS, unsigned int *pD, unsigned int row, unsigned int col)
{
//  pD= (unsigned int*) malloc(row*col*sizeof(int));
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
    {
      *(pD+j*row-i+row-1) = *(pS+i*col+j);
    }

}
void displayMatrix(unsigned int const *p, unsigned int row, unsigned int col)
{
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
      printf(" %2d",*(p+i*col+j));

    }
    cout<<endl;
  }


}
