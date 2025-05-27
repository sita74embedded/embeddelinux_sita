#include<stdio.h>
int main()
{
	int num,count=0;
	printf("enter the num\n");
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		if(num&(1<<i))
		{
			count++;
		}
	}
	printf("count is %d\n",count);
}
