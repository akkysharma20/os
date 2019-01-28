#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>
#define BSIZE 128
int main()
{
 int pp[2];
 int pc[2];
  int res;
  pid_t id;
 unsigned int buff[2]={0};
 pipe(pp); 
 pipe(pc);
 id=fork();
                                        if(0 == id) {
                                                      printf("CHILD\n");
                                                      close(pp[1]);
                                                      close(pc[0]); 
                                                      read(pp[0],buff,BSIZE);
						      res=buff[1]+buff[0];                                                     
                                                      write(pc[1],&res,4); 
                                                      close(pp[0]);
                                                      close(pc[1]);
                                                      }
                                               else{
                                                     printf("PARENT\n");
                                                     close(pp[0]);
                                                     close(pc[1]);
                                                     printf("Enter the numbers =");
                              	                     scanf("%d%d",&buff[1],&buff[0]);
                                                     write(pp[1],buff,BSIZE);
                                                     read(pc[0],&res,BSIZE);
                                                     printf("sum = %d\n",res); 
                                                     close(pp[1]);
                                                     close(pc[0]);
                                                      
}
return 0;
}
