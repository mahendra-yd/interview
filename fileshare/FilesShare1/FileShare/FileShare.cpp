
// FileShare.cpp : Defines the entry point for the console application.
#include "stdafx.h"

#include"comman.h"

using namespace std;


class  Server
{
	public:
	WSADATA wsaData;
	int iResult;

	SOCKET ListenSocket = INVALID_SOCKET;

	struct addrinfo *result = NULL;
	struct addrinfo hints;
	struct sockaddr sockaddr;;
	struct sockaddr_in sockaddrin;

	int iSendResult;
	char recvbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;
	Server(string address, string port) {
		// Initialize Winsock
		iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (iResult != 0) {			printf("WSAStartup failed with error: %d\n", iResult);}

		// Create a SOCKET for connecting to server
		ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (ListenSocket == INVALID_SOCKET) {
			printf("socket failed with error: %ld\n", WSAGetLastError());
		}

		struct sockaddr_in myaddr;
		int s;

		inet_addr("63.161.169.137", &myaddr.sin_addr.s_addr);

		bind(s, (struct sockaddr*)myaddr, sizeof(myaddr));


		sockaddrin.sin_family = AF_INET;
		sockaddrin.sin_port = htons(atoi(port.c_str()));
		sockaddrin.sin_addr.S_un.S_addr = inet_addr(address.c_str());
		// Setup the TCP listening socket
		iResult = bind(ListenSocket, (struct sockaddr*)sockaddrin, (int)result->ai_addrlen);
		if (iResult == SOCKET_ERROR) {
			printf("bind failed with error: %d\n", WSAGetLastError());
			freeaddrinfo(result);
			closesocket(ListenSocket);
			WSACleanup();
		}

		freeaddrinfo(result);
		iResult = listen(ListenSocket, SOMAXCONN);
		if (iResult == SOCKET_ERROR) {
			printf("listen failed with error: %d\n", WSAGetLastError());
			closesocket(ListenSocket);
			WSACleanup();
		}

	}

	SOCKET Accept() {

		// Accept a client socket
		SOCKET ClientSocket = accept(ListenSocket, NULL, NULL);
		if (ClientSocket == INVALID_SOCKET) {
			printf("accept failed with error: %d\n", WSAGetLastError());
			closesocket(ListenSocket);
			WSACleanup();
			return 1;
		}
		return ClientSocket;
	}

	~Server()
	{
		closesocket(ListenSocket);
		shutdown(ListenSocket, SD_SEND);
		WSACleanup();

	}
};

class clientSocket
{
public:
	SOCKET socket;
	clientSocket(SOCKET s)
	{
		socket = s;
	}
	// cleanup
	~clientSocket()
	{
		closesocket(socket);
	}
	// Receive until the peer shuts down the connection
	int Receive(char *recvbuf, int recvbuflen)
	{
		int iResult = recv(socket, recvbuf, recvbuflen, 0);
		if (iResult > 0) {
			//printf("Bytes received: %d\n", iResult);
			//iSendResult = send(ClientSocket, recvbuf, iResult, 0);
		}
		return iResult;
	}
	int Send(char * sendbuf, int sendlen)
	{
		int iSendResult = send(socket, sendbuf, sendlen, 0);
		return iSendResult;
	}

	
};
int main()
{

	return 0;
}

