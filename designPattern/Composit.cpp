#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<ctime>
#include<vector>
using namespace std;
class Employee
{
	string name;
	string dept;
	int sal;
	vector<Employee*> list;
public:
	Employee(string name, string dept, int s) :name(name), dept(dept), sal(s) {}
	void addEmployee(Employee* e) { list.push_back(e); }
	void removeEmployee(Employee *e) { for (vector<Employee*>::iterator  i = list.begin(); i != list.end(); i++) if (*i == e) list.erase(i); }
	vector<Employee*> getSubOrdinate() { return list; }
	friend	ostream& operator<<(ostream& out, Employee *e)
	{
		out << "name: " << e->name << " department: " << e->dept << " sal: " << e->sal << endl;
		return out;
	}
};

void compositDemo()
{
	Employee * ceo = new Employee("Aarav", "CEO", 3000000);
	Employee * hs = new Employee("john", "HeadSales", 3000);
	Employee * hm = new Employee("jack", "HeadMarketing", 3000);
	Employee * ck1 = new Employee("clerk1", "clerk",1000);
	Employee * ck2 = new Employee("clerk2", "clerk", 1000);
	Employee * se1 = new Employee("sales1", "SEO", 300);
	Employee * se2 = new Employee("sales2", "SEO", 300);
	ceo->addEmployee(hs);
	ceo->addEmployee(hm);
	hs->addEmployee(se1);
	hs->addEmployee(se2);
	hm->addEmployee(ck1);
	hm->addEmployee(ck2);

	// print all employee 
	cout<<ceo;
	for (int i = 0; i < ceo->getSubOrdinate().size(); i++)
	{
		Employee* head = ceo->getSubOrdinate()[i];
		cout << head;
		for (int j = 0; j < head->getSubOrdinate().size(); j++)
			cout<< head->getSubOrdinate()[j];
	}
}