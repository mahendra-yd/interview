#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<ctime>
#include<vector>
#if 0
using namespace std;
const string Married = "Married";
const string Single = "Single";
const string Male = "Male";
const string Female = "Female";
class Person
{
private:
	string name, gender, mstatus;
public:
	Person(string name_,string gender_,string mstatus_):name(name_),gender(gender_),mstatus(mstatus_){}
	string getName() { return name; }
	string getGender() { return gender; }
	string getMstatus() { return mstatus; }
};
class Criteria {
public:	virtual  vector<Person>  meetCriteria(vector<Person> lp) = 0;// { return vector<Person>(NULL); }
};
class CriteriaMale :public Criteria
{
	vector<Person> meetCriteria(vector<Person> per)
	{
	vector<Person> p;
		for (vector<Person>::iterator i = per.begin(); i != per.end(); i++)
		{
			if (i->getGender() == Male)
				p.push_back(*i);
		}
		return p;
	}
};
class CriteriaFemale :public Criteria
{
	vector<Person> meetCriteria(vector<Person> per)
	{
	vector<Person> p;
		for (vector<Person>::iterator i = per.begin(); i != per.end(); i++)
		{
			if (i->getGender() == Female)
				p.push_back(*i);
		
		}
		return p;
	}
};
class CriteriaSingle :public Criteria
{
	vector<Person> meetCriteria(vector<Person> per)
	{
	vector<Person> p;
		for (vector<Person>::iterator i = per.begin(); i != per.end(); i++)
		{
			if (i->getMstatus() == Single)
				p.push_back(*i);
		}
		return p;
	}
};

class AndCriteria :public Criteria
{
	Criteria * criteria;
	Criteria * otherciteria;
public:
	AndCriteria(Criteria *a, Criteria *b) :criteria(a), otherciteria(b) {}
	vector<Person> meetCriteria(vector<Person> per)
	{
		vector<Person> a = criteria->meetCriteria(per);
		vector<Person> b = otherciteria->meetCriteria(a);
		return b;
	}
};
class OrCriteria :public Criteria
{
	Criteria * criteria;
	Criteria * otherciteria;
public:
	OrCriteria(Criteria *a, Criteria *b) :criteria(a), otherciteria(b) {}
	vector<Person> meetCriteria(vector<Person> per)
	{
		vector<Person> a = criteria->meetCriteria(per);
		vector<Person> b = otherciteria->meetCriteria(per);
		int j = 0, s = b.size();
		for (int i = 0; i < a.size(); i++)
		{
			for (j=0; j < s; j++)
			{
				if (b[j].getName() == a[i].getName()) continue;
			}
			b.push_back(a[i]);
		}
			return b;
	}
};
void PrintPerson(vector<Person> per)
{
		for (vector<Person>::iterator i = per.begin(); i != per.end(); i++)
		{
			cout << "Name:[ " << i->getName() << " ] Gender:[ " << i->getGender() << " ] Marrital Status: [ " << i->getMstatus() << " ]" << endl;
		}
	
}
void criteriaDemo()
{
	vector<Person> p;
	p.push_back(Person("ABC", Male, Single));
	p.push_back(Person("ABD", Male, Married));
	p.push_back(Person("ABE", Female, Married));
	p.push_back(Person("ABF", Female, Single));
	p.push_back(Person("ABG", Male, Single));
	p.push_back(Person("ABH", Male, Single));

	Criteria * male = new CriteriaMale;
	Criteria * female = new CriteriaFemale;
	Criteria * single = new CriteriaSingle;

	Criteria * singlemale = new AndCriteria(single,male);
	Criteria * singleOrfemale = new OrCriteria(single,female);

	PrintPerson(male->meetCriteria(p));
	cout << endl;
	PrintPerson(female->meetCriteria(p));
	cout << endl;
	PrintPerson(single->meetCriteria(p));
	cout << endl;
	PrintPerson(singlemale->meetCriteria(p));
	cout << endl;
	PrintPerson(singleOrfemale->meetCriteria(p));
}

#endif