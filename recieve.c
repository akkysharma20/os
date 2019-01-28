#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#define BSIZE 100
int main()
{
	int fr;
	unsigned char buff[BSIZE];
	fr=open("text",O_RDONLY);
	read(fr,buff,BSIZE);
	printf("recieve data : %s\n",buff);
	close(fr);
return 0;
}
