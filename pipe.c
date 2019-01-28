 
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include<string.h>

#define SIZE 2000000

int main(int argc, char *argv[])
{
           int fd1[2], fd;          
           unsigned char buff[SIZE];
	   pid_t pid;
         printf("\nNO1 \n");
	   //pipe(fd);
           pid = fork();

           if (pid == -1)
	       perror("fork");              
           
           if (pid == 0) 
	   {    
		printf("\nt2");          

           } 
	   else { printf("\nhii");           
		//close(0);
		//dup(fd[1]);
	       // close(fd[1]);
		execvp(fd, argv[1]);	
	    	//fd = open(argv[1], O_RDONLY, S_IRUSR | S_IWUSR);
		//read(fd, buff , SIZE);	
		//printf("\nt%s", buff ); buff;   
              /* close(fd[0]);          // Close unused read end 
		printf("\nt1%s",argv[1]);  
               write(fd[1], argv[1], strlen(argv[1]));
               close(fd[1]);          //Reader will see EOF 
               wait(NULL);                //Wait for child 
               exit(EXIT_SUCCESS);*/
           }

	return 0;
}

