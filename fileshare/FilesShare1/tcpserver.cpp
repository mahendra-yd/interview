#include "tcpserver.h"
#include<iostream>
using namespace std;
Server::Server(string port, int len)
{
	listenlen = len;
	serversd = socket(AF_INET, SOCK_STREAM, 0); // creating socket
	int enable = 1;
	if (setsockopt(serversd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
		cout << "setsockopt(SO_REUSEADDR) failed" << endl;
	if(serversd==-1)
	{
		cout<<"socket creation failed"<<endl;
	}
	memset(&ipOfServer, 0, sizeof(ipOfServer));
	ipOfServer.sin_family = AF_INET;
	ipOfServer.sin_port = htons(atoi(port.c_str()));         // this is the port number of running server
	ipOfServer.sin_addr.s_addr = htonl(INADDR_ANY);
	if(-1==bind(serversd, (struct sockaddr*)&ipOfServer, sizeof(ipOfServer)))
	{
		cout<<"bind failed"<<endl;
	}
	listen(serversd, len);
}
int Server::Accept()
{	
	return accept(serversd, (struct sockaddr*)NULL, NULL);
}
Server::~Server()
{
	close(serversd);
}

