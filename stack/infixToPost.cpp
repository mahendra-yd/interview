#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stack>
#include<queue>
#include<list>
using namespace std;
bool ischar(char c)
{
  if(c>='a' && c<='z')
    return true;
  return false;
}
int precedence(char c)
{
  switch(c)
  {
    case '+':
    case '-': return 1;
	      break;
    case '*':
    case '/':
    case '%': return 2;
	      break;
    case '^': return 3;
	      break;
     case '(': return 4;
	      break;
    default: return -1;
  }
  return -1;
}
bool isOp(char c) { if(c=='+' || c=='-'|| c=='*'|| c=='/'||c=='%'|| c== '^') return true; return false; }
void  infixToPostfix(char *exp)
{
  stack<char> s;
  while(*exp)
  {
    if(ischar(*exp)) 
      printf("%c",*exp);
    else if(isOp(*exp)) 
    { 
      if(s.empty())
	s.push(*exp); 
      else if(precedence(*exp)> precedence(s.top()))
	s.push(*exp);   
      else
      {
	while(!s.empty() &&  precedence(*exp)<= precedence(s.top()))
	{ cout<<s.top();
	  s.pop();
	}
	s.push(*exp);
      }
    }
    else if(*exp == '(') 
      s.push('(');
   else  if(*exp == ')') 
    { 
      while(!s.empty() && s.top() != '(') {
	cout<<s.top();s.pop();}
    }
    exp++;
  }
  while(!s.empty()) { printf("%c ",s.top());s.pop();}

}
// Driver program to test above functions
int main()
{
  char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
  infixToPostfix(exp);
  return 0;
}
