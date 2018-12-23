#include "stdafx.h"
#include "network.h"
#include <iostream>
#include<winsock2.h>
#include <string.h>
using namespace std;

class SockAddress
{
	string ipAddress;
	string port;
	struct sockaddr_in address;
public:
	SockAddress(string ip = "127.0.0.1", string port = "8080")
	{
		this->ipAddress = ip;
		this->port = port;
	}

	void SetSockAddress(string ip, string port)
	{
		this->ipAddress = ip;
		this->port = port;
	}
};
class Server : public SockAddress
{
public:
	Server() :SockAddress()
	{

	}
};

class Socket :SockAddress
{
public:
	Socket(string ip, string port) : SockAddress(ip, port)
	{

	}

};
class TcpServer : public Server
{
public:
	void listen() {}
	void listen(string ip, string port)
	{
		SetSockAddress(ip, port);
	}

	bool listening()
	{
		return true;
	}

	/*TcpSocket  nextConnection()
	{
	TcpSocket s;
	return  s;
	}*/
};
class TcpSocket : public Socket
{
public:
	TcpSocket(string ip = "127.0.0.1", string port = "8080") : Socket(ip, port) {}
	void ConnectHost(string ip = "", string port = "")
	{

	}
	int socket;
	int  Write(char* buf, int len)
	{

	}
	int Read(char* & buf, int len)
	{

	}
	bool flush()
	{

	}

};


network::network()
{
}


network::~network()
{
}
