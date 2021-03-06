
#include "stdafx.h"
#include<queue>
#include<chrono>
#include<iostream>
#include<mutex>

using namespace std;
class Prioritylock
{
	mutex dataAccessLocl;//data access mutex
	mutex priorityLockInQueue; // priority mutex
	mutex mutexForInsertInQueue; // global resource q mutex
	condition_variable cv;
public:
	priority_queue <int> q;

	void lock(int x)
	{
		// push new thread in queueu
		mutexForInsertInQueue.lock();
		q.push(x);
		mutexForInsertInQueue.unlock();

		unique_lock<mutex> l(priorityLockInQueue);
		
		cv.wait(l, [this, x] {return x == q.top(); });
		dataAccessLocl.lock();
	}
	void unlock()
	{
		q.pop();
		dataAccessLocl.unlock();
		cv.notify_all();
	}
};

Prioritylock plock;

int loc = 0;
void threadProc(int priority)
{
	char buf[1000] = { 0 };
	plock.lock(priority);
	this_thread::sleep_for(chrono::milliseconds(500));
	printf( " EXECUTING - thread id %u priority %d prev %d\n", this_thread::get_id, priority, loc);
	loc = priority;

	std::cout.flush();
	plock.unlock();
}

#define MAX 30

void DemoPriorityLock()
{
	thread *t[MAX];
	try {
		for (int i = 0; i < MAX; i++)
			t[i] = new thread(threadProc, (rand()%MAX) + 1);


		for (int i = 0; i < MAX; i++)
			t[i]->join();
	}
	catch (exception ex)
	{
		cout << ex.what();
	}
}



