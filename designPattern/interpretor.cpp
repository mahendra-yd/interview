#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<ctime>
#include<vector>
using namespace std;
class Expression {public:	virtual bool interpret(string s) = 0;};
class TerminalExpression :public Expression
{
	string data;
public:
	TerminalExpression(string s):data(s){}
	bool interpret(string context) 	{		
		if (context.find(data)!=-1) 
			return true;		
	return false;	
	}
};
class OrExpression :public Expression
{
	Expression *exp1 = NULL, *exp2 = NULL;
public:
	OrExpression(Expression* e1,Expression* e2):exp1(e1),exp2(e2){}
	bool interpret(string context) { return exp1->interpret(context) || exp2->interpret(context); }
};
class AndExpression :public Expression
{
	Expression *exp1 = NULL, *exp2 = NULL;
public:
	AndExpression(Expression* e1,Expression* e2):exp1(e1),exp2(e2){}
	bool interpret(string context) { return exp1->interpret(context) && exp2->interpret(context); }
};
void interpretorDemo()
{
	Expression* robert = new TerminalExpression("Robert");
	Expression* john = new TerminalExpression("John");
	Expression* male = new OrExpression(robert, john);

	Expression* julie = new TerminalExpression("Julie");
	Expression* married = new TerminalExpression("Married");

	Expression* marriedWomen = new AndExpression(julie, married);

	cout << "John is male ? " << male->interpret("John")<<endl;
	cout << "julie is married ?" << marriedWomen->interpret("Julie Married") << endl;
}

