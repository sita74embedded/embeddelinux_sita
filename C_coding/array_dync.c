#include<stdio.h>
#include<stdlib.h>
int main()
{
	int **a;
	int i,j,r,c;
	printf("Enter the rows and columns\n");
	scanf("%d %d",&r,&c);
	a=(int**)malloc(r*sizeof(int* ));

	for(i=0;i<r;i++)
	{
		a[i]=(int*)malloc(c*(sizeof(int)));
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("Enter the value of [%d][%d]\n",i,j);
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

