#include "tcpsocket.h"
#include<iostream>

 #define handle_error(msg) \
            do { perror(msg); exit(EXIT_FAILURE); } while (0)

int Socket::Read(char * buf, int len){

	//return recv(sd, buf, len, 0);
	int l= read(sd, buf, len);
	if (l < 100)
	{
		perror("####### read less");
	}
	return l;
}
int Socket::Write(const char * buf, int len,size_t flag){
	size_t l=len;
	//int ret=send(sd, buf, l,flag);
	int ret = write(sd, buf, l);
	if(-1==ret)
	{
	perror("Write!!!");
	}
}
Socket::Socket(int clientsd)
{
	sd = clientsd;
}

Socket::Socket(const Socket& clientsd)
{
	sd = clientsd.sd;
}

Socket::Socket(string port, string ipaddress)
{
	sd = socket(AF_INET, SOCK_STREAM, 0);
	ipOfServer.sin_family = AF_INET;
	ipOfServer.sin_port = htons(atoi(port.c_str()));
	ipOfServer.sin_addr.s_addr = inet_addr("127.0.0.1");
}
Socket::~Socket()
{
}
void Socket::Close()
{
	close(sd);
}
bool Socket::Connect()
{
	if( connect(sd, (struct sockaddr *)&ipOfServer, sizeof(ipOfServer))==-1)
	{
		handle_error("connect");
		return false;	
	}
	return true;
}
