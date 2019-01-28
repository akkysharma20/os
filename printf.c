#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdio.h>
#define BSIZE 128
int main()
{
	int fs, fd;
	int result;
	unsigned char buff[BSIZE];
	printf("enter the character to be obtained\n");
	scanf("%s",buff);
	fs=open("printf_test.txt", O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR);
	if (-1==fs){
		perror("error\n");	
	}
	else{
		write(fs,buff,BSIZE);
		close(fs);
	}
	
	fd=open("printf_test.txt", O_RDONLY, S_IRUSR|S_IWUSR);
	if(-1==fd){
	perror("error\n");
	}
	else{
		result=read(fd,buff,BSIZE);
		printf("read:%d %s\n",result,buff);
		close(fd);
	}
return 0;
}
