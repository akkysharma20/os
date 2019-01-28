/* Write a program to get FIFO behavior (sender) */


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	int fd;	
	
	mkfifo("myfifo", S_IRUSR | S_IWUSR);
	
	printf("\nRun reader process to read the fifo file\n");

	fd = open("myfifo", O_WRONLY);
	write(fd,"\nHelloWorld\n", sizeof("\nHelloWorld\n"));

	close(fd);

	return 0;
}
	
