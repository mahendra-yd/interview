#include "tcpsocket.h"
#include <fstream>
#include <iostream>
#include "md5.h"
using namespace std;
#define BUFLEN 1024
string getFileName(const string& s) ;
enum MSGTYPE {Data,Cksum,FileName};
struct MSG
{
	int len;
	MSGTYPE msgtype;
	char data[BUFLEN];
}__attribute__((__packed__));

void ShareSend(string file)
{
	MD5 md5;
	MSG msg;
		// initialize resource socket and file descripter
	string fileName = getFileName(file);
	FILE *readFile = fopen(fileName.c_str(), "rb");
	if (readFile == NULL) { perror("file open"); }
	Socket socketsd("8888","127.0.0.1");
	if(!socketsd.Connect()){ perror("socket connect failed"); return;}

	// send file name to server
	memset((void*)&msg, 0, sizeof(MSG));
	msg.msgtype = MSGTYPE::FileName;
	msg.len = strlen(fileName.c_str());
	memcpy(msg.data, fileName.c_str(), msg.len);
	socketsd.Write((char*) &msg, sizeof(MSG));

	int rval = 0;
	while(!feof(readFile))
	{
		memset((char*)&msg,0, sizeof(MSG));
		rval = fread(msg.data, 1, BUFLEN, readFile);
		msg.len=rval;
		msg.msgtype = MSGTYPE::Data;
		md5.Update((unsigned char*)msg.data,msg.len);
		socketsd.Write((char*)&msg, sizeof(MSG));
	} 

	md5.Final();

	memset(msg.data, 0, BUFLEN);
	sprintf(msg.data,"%s",md5.digestChars);
	msg.len = strlen(msg.data)+1;
	msg.msgtype = MSGTYPE::Cksum;
	// send checksum to server for validation

	socketsd.Write((char*)&msg, sizeof(MSG), TCP_NODELAY);
	
	// release resources
	socketsd.Close();
	fclose(readFile);
}
void ShareReceive( Socket sd)
{
	int readlen=0;
	MD5 md5;
	MSG *msg=NULL;
	MSG filehdr;
	char filetempname[100] = "temp_";
	char buffer[BUFLEN]={0};
	char filename[BUFLEN]="recv_";
	memset((void*)&filehdr, 0, sizeof(MSG));
	readlen=sd.Read((char*)&filehdr, sizeof(MSG));
	memcpy(filetempname+5, filehdr.data, filehdr.len);
	FILE *writeFile = fopen(filetempname, "wb");
	if (writeFile == NULL) {	return;}
	int total = 0;
	char buf[1032];
	char tempbuf[2064];
	int MAX = 1032;
	int remainingdata = 0;
	MSG data;
	do
	{
		readlen = 0;
		memset(buf, 0, 1032);
		readlen = sd.Read(buf, sizeof(buf));
		memcpy(tempbuf+total, buf, readlen);
		total += readlen;
		if (total >= 1032)
		{
			memcpy(&data, tempbuf, 1032);
			memmove(tempbuf, tempbuf + 1032, total - 1032);
			total -= 1032;

			if (data.msgtype == MSGTYPE::Cksum) { break; }
			if (data.msgtype == MSGTYPE::Data)
			{
				md5.Update((unsigned char*)data.data, data.len);
				fwrite(data.data, 1, data.len, writeFile);
			}
		}
	} while(readlen>0);
	
	md5.Final();
	if (strncmp(data.data, md5.digestChars,32))
	{
		cout << "cksum nwtwork=" << data.data  << endl;
		cout << "cksum local=" << md5.digestChars << endl;
	}

	fclose(writeFile);
	sd.Close();

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
string getFileName(const string& s) 
{
	char sep = '/';
	size_t i = s.rfind(sep, s.length());
	if (i != string::npos) { return(s.substr(i+1, s.length() - i));	}
	return s;
}
