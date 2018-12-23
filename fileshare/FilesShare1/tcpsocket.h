#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <errno.h> 
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <string>

using namespace std;
class Socket
{
	public:
		int sd;
		struct sockaddr_in ipOfServer;
		int Read(char * buf, int len);
		int Write(const char * buf, int len, size_t flag=0);
		Socket(int clientsd);
		Socket(const Socket& clientsd);
		//Socket& operator=(const Socket& socketdes);
		Socket(string port="8080", string ipaddress="127.0.0.1");
		~Socket();
		void Close();
		bool Connect();
};

