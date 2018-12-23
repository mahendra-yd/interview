#include <stdio.h> // standard input and output library
#include <stdlib.h> // this includes functions regarding memory allocation
#include <string.h> // contains string functions
#include <errno.h> //It defines macros for reporting and retrieving error conditions through error codes
#include <time.h> //contains various functions for manipulating date and time
#include <sys/types.h> //contains a number of basic derived types that should be used whenever appropriate
#include<iostream>
#include<string>
using namespace std;
class Server
{
	int clintListn = 0, clintConnt = 0;
	int listenlen = 5;
	struct sockaddr_in ipOfServer;
	Server(string port="8080", int listenlen=5)
	{
		listenlen = listenlen;
		clintListn = socket(AF_INET, SOCK_STREAM, 0); // creating socket
		memset(&ipOfServer, '0', sizeof(ipOfServer));
		ipOfServer.sin_family = AF_INET;
		ipOfServer.sin_addr.s_addr = htonl(INADDR_ANY);
		ipOfServer.sin_port = htons(atoi(port.c_str()));         // this is the port number of running server
	}

	bind(clintListn, (struct sockaddr*)&ipOfServer, sizeof(ipOfServer));
	listen(clintListn, 20);

};
int main()
{
	time_t clock;
	char dataSending[1025]; // Actually this is called packet in Network Communication, which contain data and send through.
	int clintListn = 0, clintConnt = 0;
	struct sockaddr_in ipOfServer;
	clintListn = socket(AF_INET, SOCK_STREAM, 0); // creating socket
	memset(&ipOfServer, '0', sizeof(ipOfServer));
	memset(dataSending, '0', sizeof(dataSending));
	ipOfServer.sin_family = AF_INET;
	ipOfServer.sin_addr.s_addr = htonl(INADDR_ANY);
	ipOfServer.sin_port = htons(8080);         // this is the port number of running server
	bind(clintListn, (struct sockaddr*)&ipOfServer, sizeof(ipOfServer));
	listen(clintListn, 20);

	while (1)
	{
		printf("\n\nHi,Iam running server.Some Client hit me\n"); // whenever a request from client came. It will be processed here.
		clintConnt = accept(clintListn, (struct sockaddr*)NULL, NULL);
		printf("connected to cleitn\n");
		clock = time(NULL);
		snprintf(dataSending, sizeof(dataSending), "%.24s\r\n", ctime(&clock)); // Printing successful message
		write(clintConnt, dataSending, strlen(dataSending));

		close(clintConnt);
		sleep(1);
	}

	return 0;
}
