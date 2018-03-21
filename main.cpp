#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFFERSIZE 1024

int main(int argc, char* argv[])
{
	int scr_fd;
	char buf[BUFFERSIZE] = {0}; //��ʼ��Ϊ0
	
	if ( (argc != 2) && (argv[1] != "foo.txt")){
		fprintf( stderr, "Usage:%s cannot open!\n", argv[1]);
		exit(1);
	}
	
	/*��ʧ���˳�*/
	if ((scr_fd = open( argv[1],O_RDONLY)) == -1) {
		fprintf( stderr, "Open %s failed\n",argv[1]);
		exit(1);
	}
	
	while (read(scr_fd , buf, BUFFERSIZE) > 0 ) { 
		printf("%s",  buf);
	}
	
	memset (buf, 0, sizeof(buf)); //���������
	close(scr_fd);
	exit(0);
	return 0;
}