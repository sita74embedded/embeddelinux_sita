#include<stdio.h>
#include<stdlib.h>
int main()
{
	int r,c,i,j;
	printf("Enter the number of rows\n");
	scanf("%d",&r);
	printf("Enter the number of  columns\n");
	scanf("%d",&c);
	int **a;
	a=(int**)malloc(r*sizeof(int*));
	for(i=0;i<r;i++)
	{
		a[i]=malloc(c*sizeof(int));
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("Enter the element [%d][%d]\n",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
