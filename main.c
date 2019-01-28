#include<stdio.h>


int main()
{
	int no1, no2, sum=0;

	printf("\nEnter the two numbers: \n");
	scanf("%d%d", &no1, &no2);
	sum = add(no1, no2);
	printf("\nNO1 = %d, NO1 = %d\n", no1, no2);

	return 0;
}
