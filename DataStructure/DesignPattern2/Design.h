#pragma once
#include<iostream>
#include "stdafx.h"
#include<mutex>
#include<thread>
#include<atomic>
#include<condition_variable>
using namespace std;

#define FUN cout<<" Inside "<<__FUNCTION__<<endl;
void DemoFactory();
void DemoAbstractFactory();
void SinglotonDemo();
int CPDemo();
