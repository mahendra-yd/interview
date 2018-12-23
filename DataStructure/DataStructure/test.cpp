#include<iostream>
#include<set>
#include<map>
#include<vector>
using namespace std;
#if 0
//std::for_each
//std::tie
using namespace std;
struct S {
	int n;               // defines S::n
	static int i;        // declares, but doesn't define S::i
};                       // defines S
template <class T>
T& operator=(const T& other) // copy assignment
{
	if (this != &other) { // self-assignment check expected
		if (/* storage cannot be reused (e.g. different sizes) */)
		{
			delete[] mArray;            // destroy storage in this
										/* reset size to zero and mArray to null, in case allocation throws */
			mArray = new int[/*size*/]; // create storage in this
		}
		/* copy data from other's storage to this storage */
	}
	return *this;
}
struct X
{
	X& operator++()
	{
		// actual increment takes place here
		return *this;
	}
	X operator++(int)
	{
		X tmp(*this); // copy
		operator++(); // pre-increment
		return tmp;   // return old value
	}
};
class X
{
public:
	X& operator+=(const X& rhs) // compound assignment (does not need to be a member,
	{                           // but often is, to modify the private members)
								/* addition of rhs to *this takes place here */
		return *this; // return the result by reference
	}

	// friends defined inside class body are inline and are hidden from non-ADL lookup
	friend X operator+(X lhs,        // passing lhs by value helps optimize chained a+b+c
		const X& rhs) // otherwise, both parameters may be const references
	{
		lhs += rhs; // reuse compound assignment
		return lhs; // return the result by value (uses move constructor)
	}
};
struct Record
{
	std::string name;
	unsigned int floor;
	double weight;
	friend bool operator<(const Record& l, const Record& r)
	{
		return std::tie(l.name, l.floor, l.weight)
			< std::tie(r.name, r.floor, r.weight); // keep the same order
	}
};
inline bool operator< (const X& lhs, const X& rhs) { /* do actual comparison */ }
inline bool operator> (const X& lhs, const X& rhs) { return rhs < lhs; }
inline bool operator<=(const X& lhs, const X& rhs) { return !(lhs > rhs); }
inline bool operator>=(const X& lhs, const X& rhs) { return !(lhs < rhs); }
inline bool operator==(const X& lhs, const X& rhs) { /* do actual comparison */ }
inline bool operator!=(const X& lhs, const X& rhs) { return !(lhs == rhs); }

template<class T>
struct T
{
	value_t& operator[](std::size_t idx) { return mVector[idx]; }
	const value_t& operator[](std::size_t idx) const { return mVector[idx]; }
};
struct Sum
{
	int sum;
	Sum() : sum(0) { }
	void operator()(int n) { sum += n; }
};
//Sum s = std::for_each(v.begin(), v.end(), Sum());

void safe_increment()
{
	std::lock_guard<std::mutex> lock(g_i_mutex);
	++g_i;

	std::cout << std::this_thread::get_id() << ": " << g_i << '\n';

	// g_i_mutex is automatically released when lock
	// goes out of scope
}
#include <mutex>
#include <thread>
#include <iostream>
#include <vector>
#include <functional>
#include <chrono>
#include <string>

struct Employee {
	Employee(std::string id) : id(id) {}
	std::string id;
	std::vector<std::string> lunch_partners;
	std::mutex m;
	std::string output() const
	{
		std::string ret = "Employee " + id + " has lunch partners: ";
		for (const auto& partner : lunch_partners)
			ret += partner + " ";
		return ret;
	}
};

void send_mail(Employee &, Employee &)
{
	// simulate a time-consuming messaging operation
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void assign_lunch_partner(Employee &e1, Employee &e2)
{
	static std::mutex io_mutex;
	{
		std::lock_guard<std::mutex> lk(io_mutex);
		std::cout << e1.id << " and " << e2.id << " are waiting for locks" << std::endl;
	}

	// use std::lock to acquire two locks without worrying about 
	// other calls to assign_lunch_partner deadlocking us
	{
		std::lock(e1.m, e2.m);
		std::lock_guard<std::mutex> lk1(e1.m, std::adopt_lock);
		std::lock_guard<std::mutex> lk2(e2.m, std::adopt_lock);
		// Equivalent code (if unique_locks are needed, e.g. for condition variables)
		//        std::unique_lock<std::mutex> lk1(e1.m, std::defer_lock);
		//        std::unique_lock<std::mutex> lk2(e2.m, std::defer_lock);
		//        std::lock(lk1, lk2);
		{
			std::lock_guard<std::mutex> lk(io_mutex);
			std::cout << e1.id << " and " << e2.id << " got locks" << std::endl;
		}
		e1.lunch_partners.push_back(e2.id);
		e2.lunch_partners.push_back(e1.id);
	}
	send_mail(e1, e2);
	send_mail(e2, e1);
}
void safe_increment()
{
	std::lock_guard<std::mutex> lock(g_i_mutex);
	++g_i;

	std::cout << std::this_thread::get_id() << ": " << g_i << '\n';

	// g_i_mutex is automatically released when lock
	// goes out of scope
}
int main()
{
	Employee alice("alice"), bob("bob"), christina("christina"), dave("dave");

	// assign in parallel threads because mailing users about lunch assignments
	// takes a long time
	std::vector<std::thread> threads;
	threads.emplace_back(assign_lunch_partner, std::ref(alice), std::ref(bob));
	threads.emplace_back(assign_lunch_partner, std::ref(christina), std::ref(bob));
	threads.emplace_back(assign_lunch_partner, std::ref(christina), std::ref(alice));
	threads.emplace_back(assign_lunch_partner, std::ref(dave), std::ref(bob));

	for (auto &thread : threads) thread.join();
	std::cout << alice.output() << '\n' << bob.output() << '\n'
		<< christina.output() << '\n' << dave.output() << '\n';
}
#endif
template <typename T1, typename T2>
auto add(T1 t1, T2 t2) //-> decltype(t1 + t2)
{
	static_assert(std::is_integral<T1>::value, "Type T1 must be integral");
	static_assert(std::is_integral<T2>::value, "Type T2 must be integral");

	return t1 + t2;
}
int main()
{
	add(1, 2);
}