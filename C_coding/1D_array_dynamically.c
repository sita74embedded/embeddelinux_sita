#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i;
	printf("Enter the num of elements into an array\n");
	scanf("%d",&n);
	int *p=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		printf("Enter the value %d->",i);
		scanf("%d",&p[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",p[i]);
	}
	free(ptr);
}
