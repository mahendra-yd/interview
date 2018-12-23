#include "tcpsocket.h"
#include <fstream>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include "md5.h"
using namespace std;
string getFileName(const string& s) 
{
	char sep = '/';
	size_t i = s.rfind(sep, s.length());
	if (i != string::npos) { return(s.substr(i+1, s.length() - i));	}
	return s;
}
enum MSGTYPE {Data,Header};
struct MSG
{
	MSGTYPE msgtype;
	int len;
	char * data;
};
void ShareReceive( Socket sd)
{
	int readlen=0;
	MD5 md5;
	char buffer[1024]={0};
	char filename[1024]="recv_";
	readlen=sd.Read(buffer,sizeof(buffer));
	sscanf(buffer,"%s",(char*)(filename+5));
	cout<<"file name read from client [["<<filename<<"]] recv len= "<<readlen<<endl;
	cout<<"data from buffer should be file name!!"<<buffer<<endl;
	ofstream filewrite (filename, ios::out|ios::binary);
	do
	{
		cout<<"11"<<endl;
		memset(buffer,0,1024);
		readlen=sd.Read(buffer,sizeof(buffer));
		cout<<"22"<<endl;
		md5.Update((unsigned char*)buffer,readlen);
		filewrite.write(buffer,readlen);
	}
	while(readlen>0);
	md5.Final();
	sprintf(buffer,"%s","Data Received send cksum");
	sd.Write(buffer,strlen(buffer));
	memset(buffer,0,1024);
	cout<<"33"<<endl;
	sd.Read(buffer,sizeof(buffer));
	cout<<"###########"<<buffer<<endl;
	filewrite.close();

}
void ShareSend(string file)
{
	MD5 md5;
	string fileName = getFileName(file);
	ifstream fileread (file.c_str(), ios::in|ios::binary|ios::ate);
	if (fileread.is_open())
	{
		Socket s("8888","127.0.0.1");
		s.Connect();
		int writelen=0;
		cout<<"sending file name ####### "<<fileName<<endl;
		s.Write(fileName.c_str(),(int)fileName.size()+1,TCP_NODELAY );
		cout<<"43"<<endl;
		long size = fileread.tellg();
		fileread.seekg (0, ios::beg);
		int buflen;
		char * memblock = new  char [1024];
		while(true)
		{
			cout<<"53"<<endl;
			memset(memblock,0,1024);
			buflen=1024<size?1024:size;
			fileread.read(memblock, buflen);
			md5.Update((unsigned char*)memblock,buflen);
			cout<<"63"<<endl;
			size-=buflen;
			if(size<1024)
				break;
			s.Write(memblock,buflen);
		} 
		s.Write(memblock,buflen);
		md5.Final();
		fileread.close();
		memset(memblock,0,1024);
		cout<<"73"<<endl;
		s.Write(memblock,0,TCP_NODELAY);
		s.Read(memblock,1024);
		cout<<"Server!!!"<<memblock<<endl;
		memset(memblock,0,1024);
		sprintf(memblock,"cksum=%scksumlen=%d",md5.digestChars,strlen(md5.digestChars)+15);
		cout<<"83"<<endl;
		s.Write(memblock,strlen(memblock),TCP_NODELAY);
		cout<<memblock<<endl;
		s.Write(memblock,strlen(memblock));
		s.Close();
		delete[] memblock;
	}
	else cout << "Unable to open file";


}

void ReadInput()
{

	char ch='y';
	while( ch=='y'|| ch=='Y')
	{
		string filePath;
		cout<<"Enter file path to be send"<<endl;
		getline(cin,filePath);
		cout<<filePath<<endl;
		ShareSend(filePath);
		cout<<"Enter y/Y to continue"<<endl;
		cin>>ch;
		cin.clear();
		cin.ignore(); 
	}
}

