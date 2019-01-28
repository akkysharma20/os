#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#define BSIZE 100
int main()
{
	int fs;
	unsigned char buff[BSIZE]={0};
	fs=mkfifo("/home/batch1/Desktop/os/fifo/mkfifo _API/text", S_IRUSR|S_IWUSR);
	if(-1==fs)
	{
		perror("error\n");
	}
	else
	{
		fs=open("text",O_WRONLY);
		printf("enter data\n");
		scanf("%[^\n]s",buff);
		write(fs,buff,sizeof(buff));
		close(fs);
	}
return 0;
}
