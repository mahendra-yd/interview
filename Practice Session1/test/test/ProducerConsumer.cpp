#include"stdafx.h"
#include<stack>
#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<chrono>
using namespace std;

#define MAX 1000
template<class T>
class Buffer
{
	T *globalBuf;
	int size_;
	unsigned int readerCounter, writerCounter ;
	int counter;
	mutex mlocl;
	condition_variable cv;
public:
	Buffer(int size=MAX)
	{
		size_ = size;
		globalBuf = new T[size];
		readerCounter = -1;
		writerCounter = 0;
		counter = 0;
	}

	void Write(int data)
	{
		unique_lock<mutex> l(mlocl);
		cv.wait(l, [this]() {return counter < size_; });
		globalBuf[writerCounter%size_] = data;
		writerCounter++;
		counter++;
		l.unlock();
		cv.notify_one();
		return;
	}

	T Read()
	{
		unique_lock<mutex> l(mlocl);
		cv.wait(l, [this]() {return counter != 0; });
		T temp = globalBuf[readerCounter%size_];
		readerCounter++;
		counter--;
		l.unlock();
		cv.notify_one();
		return temp;
	}
};


void Writer(Buffer<int>&pc)
{
	int counter = 1;
	while (true)
	{
		pc.Write(++counter);
		//this_thread::sleep_for(chrono::milliseconds(rand() % 3));
	}
}
void Reader(Buffer<int>&pc)
{
	while (true)
	{
		cout << pc.Read() << " ";
		//this_thread::sleep_for(chrono::milliseconds(rand() % 3));

	}
}

int ProducerConsumerDemo()
{
	thread* w[100];
	thread* r[100];
	int count = 100;
	Buffer<int> pc(5);

	for (int i = 0; i < count; i++)
	{
		w[i] = new thread(Reader, std::ref(pc));
		r[i] = new thread(Writer, std::ref(pc));
	}
	for (int i = 0; i < count; i++)
	{
		w[i]->join();
		r[i]->join();
	}
	return 0;
}
