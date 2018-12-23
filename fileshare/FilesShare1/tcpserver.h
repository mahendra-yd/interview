#include"tcpsocket.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <errno.h> 
#include <unistd.h>
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <string>
using namespace std;
class Server
{
public:
	int serversd , clintConnt ;
	int listenlen ;
	struct sockaddr_in ipOfServer;
	Server(string port="8080", int len=5);
	int Accept();
	~Server();

};

