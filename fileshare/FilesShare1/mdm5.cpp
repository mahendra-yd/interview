#include "md5.h"
void fun();
int main()
{
	MD5 md5 ;
	puts( md5.digestString( "HELLO THERE I AM MD5!" ) ) ;

	// print the digest for a binary file on disk.
	puts( md5.digestFile( "ttt" ) ) ;
fun();
	return 0;
}
void fun()
{

MD5 md5;
		FILE *file;

		int len;
		unsigned char buffer[1024] ;

		if( (file = fopen ("ttt", "rb")) == NULL )
			printf( "ttt can't be opened\n" ) ;
		else
		{
			while( len = fread( buffer, 1, 1024, file ) )
				md5.Update( buffer, len ) ;
			md5.Final();

			fclose( file );
		}

		printf( md5.digestChars) ;


}
