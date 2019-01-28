#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
int main()
{
	int fs ;
	int fd ; 
	unsigned char buff[128];
	int result;
	fs = open ("sourcefile.txt", O_RDONLY|O_CREAT, S_IRUSR|S_IWUSR);
	fd = open ("destination.txt", O_WRONLY|O_CREAT , S_IRUSR|S_IWUSR);
	if (fs ==-1)
	{
		perror("error\n");
	}
	if (fd==-1)
	{
	 	perror("error\n");
	}
	else{
        result=read(fs,buff,15);
	write(fd,buff,result);
	close(fd);
	}
	return 0;	

}

