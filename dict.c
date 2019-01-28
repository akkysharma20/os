/* /usr/share/dict/words -> 3 processes (2 childs -> one for begin one for end)*/


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include<string.h>

#define SIZE 2000000
#define BSIZE 30

int main(int argc, char const *argv[])
{
	FILE *fp=NULL;
	int i=0, fd, fd1[2], fd2[2], fd3[2], fd4[2], count=0, flag=0;	
	unsigned char buff[SIZE]={0}, data[BSIZE], recdata[BSIZE], test[15];
	pid_t id1, id2;

	fd = open("words.txt", O_RDONLY, S_IRUSR | S_IWUSR);

	if(fd == -1)
	  perror("Error");	
	else
	 {
	   read(fd, buff , SIZE);	  
	   close(fd);
	 }
		
	pipe(fd1);
	pipe(fd2);
	pipe(fd3);
	pipe(fd4);

	printf("\nEnter the word to search\n");

	id1 = fork();
	id2 = fork();
	//printf("\n%d %d\n", getpid(), getppid());

	if(0 == id1)
	{
	   // printf("\nChild1\n");
	    close(fd1[1]);
	    read(fd1[0], recdata, sizeof(recdata));
	    fp = fopen("words.txt","r");
	    
	    fseek(fp, 0, SEEK_SET);

	    while(fgets(test, 12, fp) != NULL)
	     {
		if((strcmp(test, recdata)) == 0  )
		{
		  count++;
		   break;
		}
	        //puts(test); 	       
	     }	 
	    close(fd1[0]);

	    close(fd2[0]);
	    write(fd2[1], &count, BSIZE);
	    close(fd2[1]);
	    //printf("\nkil1\n");

	 }
	
	if(0 == id2)
	{
	    //printf("\nChild2\n");	   
	    close(fd3[1]);
	    read(fd3[0], recdata, sizeof(recdata));
	    fp = fopen("words.txt","r");
	    
	    fseek(fp, -99171, SEEK_END);

	    while(fgets(test, 12, fp) != NULL)
	     {
		if((strcmp(test, recdata)) == 0 )
		{
		  count++;
		   break;
		}
	        //puts(test); 	       
	     }	 
	    close(fd3[0]);
	    close(fd4[0]);
	    write(fd4[1], &count, BSIZE);
	    close(fd4[1]);
	    //printf("\nkil2\n");
	 }
	else
	{
	    //printf("\nParent1\n");	  
	    
	    scanf(" %s", data); 	  
	    close(fd1[0]);
	    write(fd1[1], data , sizeof(data));	   
	    close(fd1[1]);

	    close(fd3[0]);
	    write(fd3[1], data , sizeof(data));	   
	    close(fd3[1]);
	
	    close(fd4[1]);
	    read(fd4[0], &flag , sizeof(flag));

	    close(fd2[1]);	    
	    read(fd2[0], &flag , sizeof(flag));
	    if(1 == flag)
		printf("\n%s has been found in dictionary\n", data);
	    else
		printf("\n%s has not been found in dictionary\n", data);
	    close(fd2[0]);
	    kill(id1, -9);
	    kill(id2, -9);      	
	 }		
	return 0;
} 
