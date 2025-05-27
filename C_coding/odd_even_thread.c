#include<stdio.h>
#include<pthread.h>

void* odd_even(int* n)
{
	int i;
	int k=*n;
	for(i=0;i<k;i++)
	{
		if(i%2==0)
		{
			printf("even %d \n",i);
		}
		else
		{
			printf("odd %d \n",i);
		}
	}
}

int main()
{
	int n;
	pthread_t thread_id;
	printf("Enter the value of n\n");
	int *p=&n;
	scanf("%d",&n);
	int a=pthread_create(&thread_id, NULL, odd_even,p);
	if(a!=0)
	{
		perror("thread not created");
		return 1;
	}
	pthread_join(thread_id,NULL);
}

