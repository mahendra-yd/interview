#include "tcpserver.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <string>
#include <thread>
#include <iostream>
using namespace std;
void ShareReceive(Socket sd);
void ReadInput();
void clienthandler(int  csd)
{
	Socket sd(csd);
	ShareReceive(sd);
}
void server()
{
	Server s("8888");
	while (1) {
		int csd=s.Accept();
		cout<<"csd="<<csd<<endl;
		thread t(clienthandler,csd);	
		t.detach();
	}
}

int main()
{
	std::thread t1(server);
//	std::thread t2(ReadInput);
	t1.join();
//	t2.join();
	return 0;
}

