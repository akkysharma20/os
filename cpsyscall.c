#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
 int fd;
 int result;
 unsigned char buff[128];
 fd=open("desd.txt", O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
 if(fd== -1)
{
  perror("ERROR");
  close(fd);
}

else
write(fd, "Good Morning\n",13) ;
printf("data= %d\n",fd);
result=read(fd,buff,128);
printf("Read=%d \n byte=%s",result,buff);
close(fd);
return 0;

}
