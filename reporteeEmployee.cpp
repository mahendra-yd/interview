#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
#include<map>
using namespace std;
int count( map<char,vector<char> >& m, map<char,vector<char> >::iterator it)
{
  int c =  it->second.size();
  map<char,vector<char> >::iterator mp;
  //  for(vector<char>::iterator i=it->second.begin();i!=it->second.end();i++)
  for(int i=0;i<it->second.size();i++)
  {
    if( it->first!=it->second[i]&& (mp = m.find(it->second[i])) !=m.end())
      c+=count(m,mp);
  }
  return c;
}

void printData(char arr[][2],int l)
{
  map<char,vector<char> > m;
  for(int i=0;i<l;i++)
    m[arr[i][1]].push_back(arr[i][0]);
  map<char,vector<char> >::iterator it;
  for(int i=0;i<6;i++)
  {
    if( (it = m.find(arr[i][0])) ==m.end()) cout<<arr[i][0]<<" [0] "<<endl;
    else
    {
      int c = count(m,it);
      cout<<arr[i][0]<<" [ "<<c<<" ]"<<endl;
    }
  }
}

int main(int argc, char **argv)
{
  char arr[][2]{
    { 'A', 'C' },
      { 'B', 'C' },
      { 'C', 'F' },
      { 'D', 'E' },
      { 'E', 'F' },
      { 'F', 'F' } 
  };


  printData(arr,6);


  return 0;
}
