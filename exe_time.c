#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main()
{
	FILE *fp=NULL;
	unsigned char c, buff[100];
	double time_spent = 0.0;
	double count=0,time=0;
	clock_t begin = clock();

	fp = fopen("test.txt","r");

	while( !feof(fp))
	{
	//fread(buff,sizeof(buff),1,fp);
	c=fgetc(fp);
	if(c=='\n')
		count++;
	} 

	clock_t end = clock();

	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nTime elapsed is %f seconds\n", (count/ CLOCKS_PER_SEC));

	return 0;
}

	
