#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<ctime>
#include<vector>
using namespace std;
class AbstractLogger
{
public:
	static int INFO;
	static int DEBUG;
	static int ERROR;
	int level;
	AbstractLogger* nextLogger;
	AbstractLogger(int l):level(l),nextLogger(NULL){}
	void setNextLogger(AbstractLogger* next) { nextLogger = next; }
	void logMessage(int level_, string message)
	{
		if (level <= level_)
		{
			write(message);
		}
		if (nextLogger != NULL)
		{
			nextLogger->logMessage(level_, message);
		}
	}
virtual void write(string m) { cout << m << endl; }
};
class consoleLogger :public AbstractLogger
{
public:
	consoleLogger(int l):AbstractLogger(l) {}
	void write(string m) { cout << "console Logger [ " << m << "]" << endl; }
};
class errorLogger :public AbstractLogger
{
public:
	errorLogger(int l):AbstractLogger(l) {}
	void write(string m) { cout << "error Logger [ " << m << "]" << endl; }
};
class fileLogger :public AbstractLogger
{
public:
	fileLogger(int l):AbstractLogger(l) {}
	void write(string m) { cout << "file Logger [ " << m << "]" << endl; }
};

int AbstractLogger::INFO = 1;
int AbstractLogger::DEBUG = 2;
int AbstractLogger::ERROR = 3;

void chainPatternDemo()
{
	AbstractLogger* console = new consoleLogger(AbstractLogger::INFO);
	AbstractLogger* file = new fileLogger(AbstractLogger::DEBUG);
	AbstractLogger* error = new errorLogger(AbstractLogger::ERROR);
	error->setNextLogger(file);
	file->setNextLogger(console);

	error->logMessage(AbstractLogger::INFO, "This is  info message ");
	error->logMessage(AbstractLogger::DEBUG, "This is  debug message ");
	error->logMessage(AbstractLogger::ERROR, "This is  error message ");
}

