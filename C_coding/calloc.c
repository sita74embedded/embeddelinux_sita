#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n=2;
	int *ptr=(int*)calloc(n,sizeof(int));
	printf("%d\n",*ptr);
}
