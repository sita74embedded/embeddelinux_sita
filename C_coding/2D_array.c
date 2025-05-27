#include<stdio.h>
int main()
{
	int r,c,i,j;
	printf("Enter the number of rows\n");
	scanf("%d",&r);
	printf("Enter the number of colums\n");
	scanf("%d",&c);
	int a[100][100];
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("Enter the element \n");
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
